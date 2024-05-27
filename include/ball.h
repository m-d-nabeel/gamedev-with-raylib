#pragma once

#include "raylib.h"
#include "raymath.h"
class Ball {
public:
  Ball();
  void Update();
  void Draw();
  void SetPosition(Vector2 position);
  void SetSpeed(Vector2 speed);
  Vector2 GetSpeed();
  Vector2 GetPosition();
  float GetRadius();
  bool IsNotMoving();
  bool IsCollidingWithBottomWall();

private:
  Vector2 position;
  Vector2 speed;
  float radius;
};