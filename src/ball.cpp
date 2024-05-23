#include "ball.h"
#include <raylib.h>

Ball::Ball() {
  x = 100;
  y = 100;
  speedX = 5;
  speedY = 5;
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

float Ball::GetX() { return x; }

float Ball::GetY() { return y; }

float Ball::GetRadius() { return radius; }

float Ball::GetSpeedX() { return speedX; }

float Ball::GetSpeedY() { return speedY; }

void Ball::SetSpeedX(float speedX) { this->speedX = speedX; }

void Ball::SetSpeedY(float speedY) { this->speedY = speedY; }