#pragma once

#include "ball.h"
#include "raylib.h"
class Bat {
public:
  Bat();
  void Draw();
  float GetX();
  bool IsCollidingWithBall(Ball &ball);
  void Move(int direction, Ball &ball);

private:
  float x;
  float y;
  float width;
  float height;
  Color color;
};