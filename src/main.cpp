#include "ball.h"
#include "bat.h"
#include "bricks.h"
#include "constants.h"
#include <raylib.h>

void DrawCenteredText(const char *text, int fontSize, Color color, int paddingY = 0) {
  float width = MeasureText(text, fontSize);
  DrawText(text, S_WIDTH / 2 - width / 2, S_HEIGHT / 2 + paddingY, fontSize, color);
}

void ResetGame(Ball &ball, Bricks &bricks, Bat &bat) {
  ball = Ball();
  bricks.Reset();
  bat = Bat();
}

void UpdateGame(GameState &gameState, Ball &ball, Bat &bat, Bricks &bricks) {
  if (gameState == GAME_OVER) {
    return;
  }
  if (ball.IsCollidingWithBottomWall()) {
    gameState = GAME_OVER;
    return;
  }
  bat.HandleKeyboardInput(ball, gameState);
  bricks.Update(ball);
  ball.Update();
  bat.HandleCollisionWithBall(ball);
}

void DrawGame(Ball &ball, Bat &bat, Bricks &bricks, GameState gameState) {
  ClearBackground(GRAY);
  DrawCenteredText("Press R to restart", 20, LIGHTGRAY);
  DrawCenteredText("Press ESC to exit", 20, LIGHTGRAY, 20);
  DrawCenteredText("Press SPACE to pause ", 20, LIGHTGRAY, 40);

  bricks.Draw();
  ball.Draw();
  bat.Draw();

  if (gameState == PAUSED) {
    DrawCenteredText("Paused", 50, BLUE, -50);
  } else if (gameState == GAME_OVER) {
    ball.SetSpeed({0, 0});
    DrawCenteredText("Game Over", 60, RED, -60);
  }
}

int main() {
  InitWindow(S_WIDTH, S_HEIGHT, "Learning CPP with Raylib");
  SetTargetFPS(FRATE);

  // Initialize game objects
  const int horizontalBricks = (GetScreenWidth() + BRICK_PADDING) / (BRICK_WIDTH + BRICK_PADDING);
  const int verticalBricks   = (GetScreenHeight() / 2) / (BRICK_HEIGHT + BRICK_PADDING);
  Ball ball                  = Ball();
  Bat bat                    = Bat();
  Bricks bricks              = Bricks(horizontalBricks, verticalBricks);
  GameState gameState        = PLAYING;

  // Main game loop
  while (!WindowShouldClose()) {
    if (IsKeyPressed(KEY_R)) {
      ResetGame(ball, bricks, bat);
      gameState = PLAYING;
    }
    if (IsKeyPressed(KEY_SPACE)) {
      if (gameState == PLAYING) {
        gameState = PAUSED;
      } else if (gameState == PAUSED) {
        gameState = PLAYING;
      }
    }
    if (IsKeyPressed(KEY_ESCAPE)) {
      break;
    }
    if (gameState != PAUSED) {
      UpdateGame(gameState, ball, bat, bricks);
    }
    BeginDrawing();
    DrawGame(ball, bat, bricks, gameState);
    EndDrawing();
  }

  CloseWindow();
  return 0;
}
