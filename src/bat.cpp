#include "bat.h"
#include "ball.h"
#include "constants.h"
#include <raylib.h>

Bat::Bat()
    : x(S_WIDTH / 2 - BAT_WIDTH / 2), y(S_HEIGHT - BALL_RADIUS),
      width(BAT_WIDTH), height(BAT_HEIGHT) {
  color = DARKBLUE;
}

void Bat::Draw() { DrawRectangle(x, y, width, height, color); }

bool Bat::IsCollidingWithBall(Ball &ball) {
  Vector2 ballPosition = {ball.GetX(), ball.GetY()};
  Rectangle batRectangle = {x, y, BAT_WIDTH, BAT_HEIGHT};
  return CheckCollisionCircleRec(ballPosition, BALL_RADIUS, batRectangle);
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

  if (ball.IsNotMoving()) {
    ball.SetX(x + width / 2);
  }
}

float Bat::GetX() { return x; }