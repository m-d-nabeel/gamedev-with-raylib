#include "bat.h"
#include "ball.h"
#include "constants.h"
#include <raylib.h>

Bat::Bat()
    : x(S_WIDTH / 2 - BAT_WIDTH / 2), y(S_HEIGHT - BALL_RADIUS),
      width(BAT_WIDTH), height(BAT_HEIGHT) {
  color = Color{255, 255, 255, 255};
}

void Bat::Draw() { DrawRectangle(x, y, width, height, color); }

void Bat::SetColor(unsigned char r, unsigned char g, unsigned char b,
                   unsigned char a) {
  color = Color{r, g, b, a};
}

bool Bat::IsCollidingWithBall(Ball &ball) {
  Vector2 ballPosition = {ball.GetX(), ball.GetY()};
  Rectangle brickRectangle = {x, y, BRICK_WIDTH, BRICK_HEIGHT};
  return CheckCollisionCircleRec(ballPosition, BALL_RADIUS, brickRectangle);
}

float Bat::GetX() { return x; }