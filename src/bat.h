#pragma once

#include "ball.h"
#include "raylib.h"
class Bat {
public:
  Bat();
  void Draw();
  void SetColor(unsigned char r, unsigned char g, unsigned char b,
                unsigned char a);
  float GetX();
  bool IsCollidingWithBall(Ball &ball);

private:
  float x;
  float y;
  float width;
  float height;
  Color color;
};