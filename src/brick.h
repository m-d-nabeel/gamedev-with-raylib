#pragma once

#include "raylib.h"

class Brick {
public:
  Brick();
  void Draw();
  void SetPosition(float x, float y);
  void SetSize(float width, float height);
  void SetColor(unsigned char r, unsigned char g, unsigned char b, unsigned char a);
  void SetVisible(bool visible);
  bool IsVisible();
  float GetX();
  float GetY();
  float GetWidth();
  float GetHeight();

private:
  float x;
  float y;
  float width;
  float height;
  Color color;
  bool visible;
};