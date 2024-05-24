#include "ball.h"
#include "constants.h"
#include <raylib.h>

Ball::Ball() {
  x = S_WIDTH / 2;
  y = BOTTOM_LINE - BAT_HEIGHT - BALL_RADIUS - 1;
  speedX = 0;
  speedY = 0;
  radius = 15;
}

void Ball::Update() {
  x += speedX;
  y += speedY;

  if (x + radius >= GetScreenWidth() || x - radius <= 0)
    speedX *= -1;

  if (y + radius >= GetScreenHeight() || y - radius <= 0)
    speedY *= -1;
}

void Ball::Draw() { DrawCircle(x, y, radius, WHITE); }

bool Ball::IsNotMoving() { return speedX == 0 && speedY == 0; }

float Ball::GetX() { return x; }

float Ball::GetY() { return y; }

float Ball::GetRadius() { return radius; }

float Ball::GetSpeedX() { return speedX; }

float Ball::GetSpeedY() { return speedY; }

void Ball::SetSpeedX(float speedX) { this->speedX = speedX; }

void Ball::SetSpeedY(float speedY) { this->speedY = speedY; }