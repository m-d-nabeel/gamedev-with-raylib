#pragma once

#include "ball.h"
#include "raylib.h"

class Brick {
public:
  Brick();
  void Draw();
  void SetPosition(float x, float y);
  void SetColor(Color c);
  Color GetColor();
  void SetVisible(bool visible);
  bool IsVisible();
  float GetX();
  float GetY();
  bool IsCollidingWithBall(Ball &ball);

private:
  float x;
  float y;
  float width;
  float height;
  Color color;
  bool visible;
};