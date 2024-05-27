#include "../include/game.h"
#include "raylib.h"

Game::Game() {
  ScreenWidth  = INIT_SWIDTH;
  ScreenHeight = INIT_SHEIGHT;
  gameState    = GameState::PLAYING;
  // int hBricksCount = (INIT_SWIDTH + BRICK_PADDING) / (BRICK_WIDTH + BRICK_PADDING);
  // int vBricksCount = (INIT_SHEIGHT / 2) / (BRICK_HEIGHT + BRICK_PADDING);
  int hBricksCount = 2;
  int vBricksCount = 2;
  bricks           = new Bricks(hBricksCount, vBricksCount);
  bat              = Bat();
  ball             = Ball();
}

void Game::ResetGame() {
  ball = Ball();
  bricks->Reset();
  bat = Bat();
}

void Game::UpdateGame() {
  if (gameState == GameState::GAME_OVER || gameState == GameState::PAUSED) {
    return;
  }
  if (ball.IsCollidingWithBottomWall()) {
    gameState = GameState::GAME_OVER;
    return;
  }
  if (bricks->IsAllBricksDestroyed()) {
    gameState = GameState::GAME_WON;
    return;
  }
  bat.HandleKeyboardInput(ball, gameState);
  bricks->Update(ball);
  ball.Update();
  bat.HandleCollisionWithBall(ball);
}

void Game::DrawGame() {
  ClearBackground(BLACK);

  if (gameState == GameState::PLAYING) {
    DrawCenteredText("Press SPACE to pause ", 20, LIGHTGRAY, 40);
  } else {
    DrawCenteredText("Press R to restart", 20, LIGHTGRAY);
    DrawCenteredText("Press ESC to exit", 20, LIGHTGRAY, 20);
  }

  bricks->Draw();
  ball.Draw();
  bat.Draw();

  if (gameState == GameState::PAUSED) {
    DrawCenteredText("Paused", 50, BLUE, -50);
  } else if (gameState == GameState::GAME_OVER) {
    ball.SetSpeed({0, 0});
    DrawCenteredText("Game Over", 60, RED, -60);
  } else if (gameState == GameState::GAME_WON) {
    ball.SetSpeed({0, 0});
    DrawCenteredText("You Won", 60, GREEN, -60);
  }
}

void Game::HandleKeyboardInput() {
  if (IsKeyPressed(KEY_R)) {
    ResetGame();
    gameState = GameState::PLAYING;
  }
  if (IsKeyPressed(KEY_SPACE)) {
    if (gameState == GameState::PLAYING) {
      gameState = GameState::PAUSED;
    } else if (gameState == GameState::PAUSED) {
      gameState = GameState::PLAYING;
    }
  }
  if (IsKeyPressed(KEY_ESCAPE)) {
    CloseWindow();
  }
}

Game::~Game() {
  delete bricks;
  CloseWindow();
}