#include "ball.h"
#include "bat.h"
#include "bricks.h"
#include "constants.h"
#include <raylib.h>

struct BallSpeed {
  float x;
  float y;
};

enum GameState {
  PLAYING,
  PAUSED,
  RESUMED,
  GAME_OVER,
};

void DrawCenteredText(const char *text, int fontSize, Color color,
                      int paddingY = 0) {
  float width = MeasureText(text, fontSize);
  DrawText(text, S_WIDTH / 2 - width / 2, S_HEIGHT / 2 + paddingY, fontSize,
           color);
}

// void HandleGameState(GameState &gameState, Ball &ball, BallSpeed &bs) {
//   switch (gameState) {
//   case PLAYING:
//     break;
//   case PAUSED:
//     if (!ball.IsNotMoving()) {
//       bs.x = ball.GetSpeedX();
//       bs.y = ball.GetSpeedY();
//     }
//     ball.SetSpeedX(0);
//     ball.SetSpeedY(0);
//     DrawCenteredText("Paused", 50, BLUE, -50);
//     break;
//   case RESUMED:
//     ball.SetSpeedX(bs.x);
//     ball.SetSpeedY(bs.y);
//     break;
//   case GAME_OVER:
//     DrawCenteredText("Game Over", 60, RED, -60);
//     ball.SetSpeedX(0);
//     ball.SetSpeedY(0);
//     break;
//   }
// }

void ResetGame(Ball &ball, Bricks &bricks) {
  ball = Ball();
  bricks.Reset();
}

void UpdateGame(GameState &gameState, Ball &ball, Bat &bat, Bricks &bricks,
                BallSpeed &bs) {
  if (IsKeyPressed(KEY_ENTER) && ball.IsNotMoving() &&
      bat.IsCollidingWithBall(ball)) {
    ball.SetSpeedX(1);
    ball.SetSpeedY(-5);
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

  Ball ball = Ball();
  Bat bat = Bat();
  Bricks bricks = Bricks(5, 5);
  BallSpeed bs;
  GameState gameState = PLAYING;

  while (!WindowShouldClose()) {
    if (IsKeyPressed(KEY_R)) {
      ResetGame(ball, bricks);
      gameState = PLAYING;
    }

    if (IsKeyPressed(KEY_SPACE)) {
      if (gameState == PLAYING || gameState == RESUMED) {
        gameState = PAUSED;
      } else if (gameState == PAUSED) {
        gameState = RESUMED;
      }
    }

    if (IsKeyPressed(KEY_ESCAPE)) {
      break;
    }

    if (gameState != PAUSED) {
      UpdateGame(gameState, ball, bat, bricks, bs);
    }



    BeginDrawing();
    DrawGame(ball, bat, bricks, gameState);
    EndDrawing();
  }

  CloseWindow();
  return 0;
}
