#include "../include/ball.h"
#include "../include/constants.h"
#include "../include/game.h"
#include <raylib.h>
#include <raymath.h>

Ball::Ball() {
  position = {INIT_SWIDTH / 2, INIT_SHEIGHT - BRICK_HEIGHT};
  speed    = {0, 0};
  radius   = 15;
}

void Ball::Update() {
  position = Vector2Add(position, speed);
  if (position.x + radius >= INIT_SWIDTH || position.x - radius <= 0) {
    speed.x *= -1;
  }
  if (position.y + radius >= INIT_SHEIGHT || position.y - radius <= 0) {
    speed.y *= -1;
  }
}

bool Ball::IsCollidingWithBottomWall() {
  return position.y + radius >= INIT_SHEIGHT;
}

void Ball::Draw() {
  DrawCircleV(position, radius, DARKBROWN);
}

bool Ball::IsNotMoving() {
  return Vector2LengthSqr(speed) == 0;
}

Vector2 Ball::GetPosition() {
  return position;
}

void Ball::SetPosition(Vector2 position) {
  this->position = position;
}

void Ball::SetSpeed(Vector2 speed) {
  this->speed = speed;
}

float Ball::GetRadius() {
  return radius;
}

Vector2 Ball::GetSpeed() {
  return speed;
}