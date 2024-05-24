#include "ball.h"
#include "bat.h"
#include "bricks.h"
#include "constants.h"
#include <raylib.h>

enum GameState {
  PLAYING,
  PAUSED,
  GAME_OVER,
};

void DrawCenteredText(const char *text, int fontSize, Color color,
                      int paddingY = 0) {
  float width = MeasureText(text, fontSize);
  DrawText(text, S_WIDTH / 2 - width / 2, S_HEIGHT / 2 + paddingY, fontSize,
           color);
}

void ResetGame(Ball &ball, Bricks &bricks, Bat &bat) {
  ball = Ball();
  bricks.Reset();
  bat = Bat();
}

void UpdateGame(GameState &gameState, Ball &ball, Bat &bat, Bricks &bricks) {
  if (IsKeyPressed(KEY_ENTER) && ball.IsNotMoving() &&
      bat.IsCollidingWithBall(ball)) {
    ball.SetSpeedX(1);
    ball.SetSpeedY(-1 * BALL_SPEED);
  }

  bricks.Update(ball);
  ball.Update();

  if (bat.IsCollidingWithBall(ball)) {
    ball.SetSpeedY(ball.GetSpeedY() * -1);
    if (ball.GetX() < bat.GetX() + BAT_WIDTH / 2) {
      ball.SetSpeedX(ball.GetSpeedX() * -1);
    }
  }

  if (ball.GetY() + ball.GetRadius() >= S_HEIGHT) {
    gameState = GAME_OVER;
  }
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
    ball.SetSpeedX(0);
    ball.SetSpeedY(0);
    DrawCenteredText("Game Over", 60, RED, -60);
  }
}

int main() {
  InitWindow(S_WIDTH, S_HEIGHT, "Learning CPP with Raylib");
  SetTargetFPS(FRATE);

  const int horizontalBricks =
      (GetScreenWidth() + BRICK_PADDING) / (BRICK_WIDTH + BRICK_PADDING);

  const int verticalBricks =
      (GetScreenHeight() / 2) / (BRICK_HEIGHT + BRICK_PADDING);

  Ball ball = Ball();
  Bat bat = Bat();
  Bricks bricks = Bricks(horizontalBricks, verticalBricks);
  GameState gameState = PLAYING;

  while (!WindowShouldClose()) {

    if ((IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_FOUR) || IsKeyDown(KEY_A)) &&
        gameState == PLAYING) {
      bat.Move(-1, ball);
    }
    if ((IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_SIX) || IsKeyDown(KEY_D)) &&
        gameState == PLAYING) {
      bat.Move(1, ball);
    }

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
