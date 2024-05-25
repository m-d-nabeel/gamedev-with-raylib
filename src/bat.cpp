#include "bat.h"
#include "ball.h"
#include "constants.h"
#include <raylib.h>

Bat::Bat() : x(S_WIDTH / 2 - BAT_WIDTH / 2), y(S_HEIGHT - BALL_RADIUS), width(BAT_WIDTH), height(BAT_HEIGHT) {
  color = DARKBLUE;
}

void Bat::Draw() {
  DrawRectangle(x, y, width, height, color);
}

bool Bat::IsCollidingWithBall(Ball &ball) {
  Rectangle batRectangle = {x, y, BAT_WIDTH, BAT_HEIGHT};
  return CheckCollisionCircleRec(ball.GetPosition(), BALL_RADIUS, batRectangle);
}

void Bat::Move(int direction, Ball &ball) {
  if (direction == 0) {
    return;
  }

  if (direction < 0) {
    x -= BAT_SPEED;
  } else {
    x += BAT_SPEED;
  }

  if (x + width / 2 <= 0) {
    x = -width / 2;
  }

  if (x + width / 2 >= S_WIDTH) {
    x = S_WIDTH - width / 2;
  }
}

void Bat::HandleCollisionWithBall(Ball &ball) {
  if (ball.IsNotMoving()) {
    ball.SetPosition({x + BAT_WIDTH / 2, static_cast<float>(GetScreenHeight() - BRICK_HEIGHT)});
    return;
  }
  if (IsCollidingWithBall(ball)) {
    ball.SetSpeed(Vector2Reflect(ball.GetSpeed(), {0, 1}));
    if (ball.GetPosition().x < x + BAT_WIDTH / 2) {
      ball.SetSpeed(Vector2Reflect(ball.GetSpeed(), {1, 0}));
    }
  }
}

void Bat::HandleKeyboardInput(Ball &ball, GameState &gameState) {
  if (gameState == GAME_OVER || gameState == PAUSED) {
    return;
  }
  if (IsKeyPressed(KEY_ENTER) && ball.IsNotMoving() && IsCollidingWithBall(ball)) {
    gameState = PLAYING;
    ball.SetSpeed({1, -1 * BALL_SPEED});
  }
  if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_FOUR) || IsKeyDown(KEY_A)) {
    Move(-1, ball);
  }
  if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_SIX) || IsKeyDown(KEY_D)) {
    Move(1, ball);
  }
}

float Bat::GetX() {
  return x;
}