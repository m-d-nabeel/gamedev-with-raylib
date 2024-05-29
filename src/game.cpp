#include "../include/game.h"
#include "../include/constants.h"
#include "raylib.h"

constexpr bool DEB_ENV = false;

Game::Game() {
  gameState            = PLAYING;
  hBricksCount         = DEB_ENV ? 1 : (INIT_SWIDTH + BRICK_PADDING) / (BRICK_WIDTH + BRICK_PADDING);
  vBricksCount         = DEB_ENV ? 1 : (INIT_SHEIGHT / 2) / (BRICK_HEIGHT + BRICK_PADDING);
  bricks               = Bricks(hBricksCount, vBricksCount);
  bat                  = Bat();
  ball                 = Ball();
  isFullScreen         = false;
  score                = 0;
  lives                = 3;
  level                = 1;
  powerUpType          = NONE;
  powerUpState         = INACTIVE;
  heartTexture         = LoadTexture("assets/heart.png");
  heartTexture.width   = 25;
  heartTexture.height  = 25;
  allBricksBrokenSound = LoadSound("assets/Sounds/allBricksBrokenSound.wav");
}

void Game::ResetGame() {
  score        = 0;
  lives        = 3;
  level        = 1;
  powerUpType  = NONE;
  powerUpState = INACTIVE;
  ball.Reset();
  bat.Reset();
  bricks.Reset();
}

void Game::UpdateGame() {
  if (gameState == GAME_OVER || gameState == PAUSED || gameState == GAME_WON) {
    return;
  }
  if (ball.IsCollidingWithBottomWall()) {
    lives--;
    gameState = LIVE_LOST;
    if (lives == 0) {
      gameState = GAME_OVER;
      return;
    }
    ball.Reset();
    bat.Reset();
    return;
  }
  if (bricks.IsAllBricksDestroyed()) {
    PlaySound(allBricksBrokenSound);
    gameState = GAME_WON;
    return;
  }
  bat.HandleKeyboardInput(ball, gameState);
  bricks.Update(ball, score);
  ball.Update();
  bat.HandleCollisionWithBall(ball);
}

void Game::DrawGame() {
  ClearBackground(BLACK);

  // GAMEPLAY INFORMATION DISPLAY
  DrawRectangleGradientV(0, 0, GetScreenWidth(), TOP_PADDING, Color{17, 24, 39, 255}, BLACK);
  const char *scoreText = TextFormat("Score: %i", score);
  const char *levelText = TextFormat("Level: %i", level);
  const int fontSize    = 20;
  DrawText(scoreText, GetScreenWidth() / 2 - MeasureText(scoreText, fontSize) / 2 - 10, 10, fontSize, GRAY);
  DrawText(levelText, 0, 10, fontSize, GRAY);
  for (int i = 0; i < lives; i++) {
    DrawTexture(heartTexture, GetScreenWidth() - 30 - 30 * i, 10, WHITE);
  }
  // END OF GAMEPLAY INFORMATION DISPLAY

  if (gameState != PLAYING && gameState != LIVE_LOST) {
    DrawCenteredText("Press R to restart", 20, LIGHTGRAY);
    DrawCenteredText("Press ESC to exit", 20, LIGHTGRAY, 20);
  }

  bricks.Draw();
  ball.Draw();
  bat.Draw();

  switch (gameState) {
  case PLAYING:
    DrawCenteredText("Press SPACE to pause ", 20, GRAY, 40);
    break;
  case PAUSED:
    DrawCenteredText("Paused", 50, BLUE, -50);
    break;
  case GAME_OVER:
    DrawCenteredText("Game Over", 60, RED, -60);
    break;
  case GAME_WON:
    DrawCenteredText("You Won", 60, GREEN, -60);
    break;
  case LEVEL_COMPLETE:
    DrawCenteredText("Level Complete", 50, GREEN, -50);
    break;
  case LIVE_LOST:
    DrawCenteredText("Life Lost", 50, RED, -50);
    DrawCenteredText("Press ENTER to continue", 20, GRAY, 20);
    break;
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
