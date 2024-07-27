#include "../include/brick_breaker/bat.h"
#include "../include/brick_breaker/ball.h"
#include "../include/constants.h"
#include "raymath.h"
#include <raylib.h>

Bat::Bat() {
  color    = DARKBLUE;
  x        = (GetScreenWidth() - BAT_WIDTH) / 2;
  width    = BAT_WIDTH;
  height   = BAT_HEIGHT;
  y        = GetScreenHeight() - BALL_RADIUS;
  movement = 0;
  hitSound = LoadSound("src/resources/Sounds/wallHit.wav");
}

void Bat::Reset() {
  x        = (GetScreenWidth() - BAT_WIDTH) / 2;
  movement = 0;
}

void Bat::Draw() {
  Rectangle rect = {x, y, width, height};
  DrawRectangleRounded(rect, 0.5, 5, color);
}

bool Bat::IsCollidingWithBall(Ball &ball) {
  Rectangle batRectangle = {x, y, BAT_WIDTH + 10.0f, BAT_HEIGHT + 10.0f};
  if (CheckCollisionCircleRec(ball.GetPosition(), BALL_RADIUS, batRectangle)) {
    PlaySound(hitSound);
    return true;
  }
  return false;
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

  if (x + width / 2 >= GetScreenWidth()) {
    x = GetScreenWidth() - width / 2;
  }
}

void Bat::HandleCollisionWithBall(Ball &ball) {
  if (ball.IsNotMoving()) {
    ball.SetPosition({x + BAT_WIDTH / 2, static_cast<float>(GetScreenHeight() - BRICK_HEIGHT)});
    return;
  }
  Vector2 speed = ball.GetSpeed();
  if (IsCollidingWithBall(ball)) {
    speed = Vector2Reflect(speed, {0, 1});
    if (ball.GetPosition().x < x + BAT_WIDTH / 2) {
      speed = Vector2Reflect(speed, {1, 0});
    }
    if (movement != 0) {
      speed.x += movement * SPEEDUP;
    }
    Vector2 direction = Vector2Normalize(speed);
    ball.SetSpeed(Vector2Scale(direction, ball.GetDefaultSpeed()));
  }
}

void Bat::HandleKeyboardInput(Ball &ball, GameState &gameState) {
  if (gameState == GAME_OVER || gameState == PAUSED) {
    return;
  }
  if (IsKeyPressed(KEY_ENTER) && ball.IsNotMoving() && IsCollidingWithBall(ball)) {
    gameState = PLAYING;
    ball.SetSpeed({0, -ball.GetDefaultSpeed()});
  }
  if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_FOUR) || IsKeyDown(KEY_A)) {
    movement = -1;
  } else if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_SIX) || IsKeyDown(KEY_D)) {
    movement = 1;
  } else {
    movement = 0;
  }
  Move(movement, ball);
}

float Bat::GetX() {
  return x;
}

int Bat::GetMovement() {
  return movement;
}