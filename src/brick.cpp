#include "../include/brick.h"
#include "../include/constants.h"
#include <raylib.h>

Brick::Brick() {
  width  = 100;
  height = 30;
  x      = 100;
  y      = 100;
  color  = Color{};
}

void Brick::Draw() {
  DrawRectangle(x, y, BRICK_WIDTH, BRICK_HEIGHT, color);
}

void Brick::SetPosition(float x, float y) {
  this->x = x;
  this->y = y;
}

void Brick::SetColor(Color c) {
  color = c;
}

bool Brick::IsCollidingWithBall(Ball &ball) {
  Rectangle brickRectangle = {x, y, BRICK_WIDTH, BRICK_HEIGHT};
  return CheckCollisionCircleRec(ball.GetPosition(), BALL_RADIUS, brickRectangle);
}

void Brick::SetVisible(bool visible) {
  this->visible = visible;
}

bool Brick::IsVisible() {
  return visible;
}

float Brick::GetX() {
  return x;
}

float Brick::GetY() {
  return y;
}
