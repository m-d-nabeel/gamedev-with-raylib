#pragma once

#include "raylib.h"
#include "raymath.h"
class Ball {
public:
  Ball();
  void Update();
  void Draw() const;
  void SetPosition(Vector2 position);
  void SetSpeed(Vector2 speed);
  Vector2 GetSpeed() const;
  Vector2 GetPosition() const;
  float GetRadius() const;
  bool IsNotMoving() const;
  bool IsCollidingWithBottomWall() const;

private:
  Vector2 position;
  Vector2 speed;
  float radius;
};
