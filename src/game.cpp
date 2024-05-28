#include "../include/game.h"
#include "../include/constants.h"
#include "raylib.h"

Game::Game() {
  gameState    = PLAYING;
  hBricksCount = (INIT_SWIDTH + BRICK_PADDING) / (BRICK_WIDTH + BRICK_PADDING);
  vBricksCount = (INIT_SHEIGHT / 2) / (BRICK_HEIGHT + BRICK_PADDING);
  bricks       = Bricks();
  bat          = Bat();
  ball         = Ball();
  isFullScreen = false;
}

void Game::ResetGame() {
  ball   = Ball();
  bricks = Bricks(hBricksCount, vBricksCount);
  bat    = Bat();
}

void Game::UpdateGame() {
  if (gameState == GAME_OVER || gameState == PAUSED || gameState == GAME_WON) {
    return;
  }
  if (ball.IsCollidingWithBottomWall()) {
    gameState = GAME_OVER;
    return;
  }
  if (bricks.IsAllBricksDestroyed()) {
    gameState = GAME_WON;
    return;
  }
  bat.HandleKeyboardInput(ball, gameState);
  bricks.Update(ball);
  ball.Update();
  bat.HandleCollisionWithBall(ball);
}

void Game::DrawGame() {
  ClearBackground(BLACK);
  if (gameState == PLAYING) {
    DrawCenteredText("Press SPACE to pause ", 20, LIGHTGRAY, 40);
  } else {
    DrawCenteredText("Press R to restart", 20, LIGHTGRAY);
    DrawCenteredText("Press ESC to exit", 20, LIGHTGRAY, 20);
  }

  bricks.Draw();
  ball.Draw();
  bat.Draw();

  if (gameState == PAUSED) {
    DrawCenteredText("Paused", 50, BLUE, -50);
  } else if (gameState == GAME_OVER) {
    DrawCenteredText("Game Over", 60, RED, -60);
  } else if (gameState == GAME_WON) {
    DrawCenteredText("You Won", 60, GREEN, -60);
  }
}

void Game::HandleKeyboardInput() {
  if (IsKeyPressed(KEY_R)) {
    ResetGame();
    gameState = PLAYING;
  }
  if (IsKeyPressed(KEY_SPACE)) {
    if (gameState == PLAYING) {
      gameState = PAUSED;
    } else if (gameState == PAUSED) {
      gameState = PLAYING;
    }
  }
  if (IsKeyPressed(KEY_F11)) {
    if (isFullScreen) {
      SetWindowSize(INIT_SWIDTH, INIT_SHEIGHT);
      isFullScreen = false;
    } else {
      int monitor = GetCurrentMonitor();
      SetWindowSize(GetMonitorWidth(monitor), GetMonitorHeight(monitor));
      isFullScreen = true;
    }
  }
}

void Game::LoopLogic() {
  HandleKeyboardInput();
  UpdateGame();
  BeginDrawing();
  DrawGame();
  EndDrawing();
  if (isFullScreen) {
    ToggleFullscreen();
    isFullScreen = false;
    RedrawBricks();
    ball.SetDefaultSpeed(ball.GetDefaultSpeed() * 1.25f);
  }
}

void Game::DrawCenteredText(const char *text, int fontSize, Color color, int paddingY) {
  float screenWidth  = GetScreenWidth();
  float screenHeight = GetScreenHeight();
  float textWidth    = MeasureText(text, fontSize);
  float textHeight   = fontSize;
  float posX         = screenWidth / 2 - textWidth / 2;
  float posY         = screenHeight / 2 - textHeight / 2 + paddingY;
  DrawText(text, static_cast<int>(posX), static_cast<int>(posY), fontSize, color);
}

void Game::RedrawBricks() {
  ball = Ball();
  bat  = Bat();
  bricks.RenderForCurrWindow();
}