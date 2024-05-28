#include "../include/ball.h"
#include "../include/constants.h"
#include <raylib.h>
#include <raymath.h>

Ball::Ball() {
  position     = {static_cast<float>(GetScreenWidth() * 1.0 / 2), static_cast<float>(GetScreenHeight() - BRICK_HEIGHT)};
  speed        = {0, 0};
  defaultSpeed = 10.0f;
  radius       = 15;
}

void Ball::Update() {
  position = Vector2Add(position, speed);
  if (position.x + radius >= GetScreenWidth() || position.x - radius <= 0) {
    speed.x *= -1;
  }
  if (position.y + radius >= GetScreenHeight() || position.y - radius <= 0) {
    speed.y *= -1;
  }
}

bool Ball::IsCollidingWithBottomWall() const {
  return position.y + radius >= GetScreenHeight();
}

void Ball::Draw() const {
  DrawCircleV(position, radius, DARKBROWN);
}

bool Ball::IsNotMoving() const {
  return Vector2LengthSqr(speed) == 0;
}

Vector2 Ball::GetPosition() const {
  return position;
}

void Ball::SetPosition(Vector2 position) {
  this->position = position;
}

void Ball::SetSpeed(Vector2 speed) {
  this->speed = speed;
}

float Ball::GetRadius() const {
  return radius;
}

Vector2 Ball::GetSpeed() const {
  return speed;
}

float Ball::GetDefaultSpeed() const {
  return defaultSpeed;
}

void Ball::SetDefaultSpeed(float speed) {
  defaultSpeed = speed;
}