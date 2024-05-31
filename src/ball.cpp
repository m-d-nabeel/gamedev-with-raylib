#include "../include/ball.h"
#include "../include/constants.h"
#include <raylib.h>
#include <raymath.h>

Ball::Ball() {
  position       = {static_cast<float>(GetScreenWidth() * 1.0 / 2), static_cast<float>(GetScreenHeight() - BRICK_HEIGHT)};
  speed          = {0, 0};
  defaultSpeed   = 10.0f;
  radius         = 15;
  texture        = LoadTexture("assets/Balls/EggBlue.png");
  texture.height = radius * 2;
  texture.width  = radius * 2;
  wallHitSound   = LoadSound("assets/Sounds/wallHit.wav");
  gameOverSound  = LoadSound("assets/Sounds/gameOver.wav");
  ballHitPower   = 10;
}

void Ball::Update() {
  position = Vector2Add(position, speed);
  if (position.x + radius >= GetScreenWidth() || position.x - radius <= 0) {
    PlaySound(wallHitSound);
    speed.x *= -1;
  }
  if (position.y + radius >= GetScreenHeight() || position.y - radius - TOP_PADDING <= 0) {
    PlaySound(wallHitSound);
    speed.y *= -1;
  }
}

void Ball::Reset() {
  position = {static_cast<float>(GetScreenWidth() * 1.0 / 2), static_cast<float>(GetScreenHeight() - BRICK_HEIGHT)};
  speed    = {0, 0};
}

bool Ball::IsCollidingWithBottomWall() const {
  if (position.y + radius >= GetScreenHeight()) {
    PlaySound(gameOverSound);
    return true;
  };
  return false;
}

void Ball::Draw() const {
  DrawCircleGradient(position.x, position.y, 1.5f * radius, BLUE, {255, 255, 255, 0});
  DrawTextureV(texture, Vector2Subtract(position, {radius, radius}), WHITE);
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