#include <raylib.h>

#include "brick.h"

Brick::Brick() {
  width = 100;
  height = 30;
  x = 100;
  y = 100;
  color = Color{20, 160, 133, 255};
}

void Brick::Draw() { DrawRectangle(x, y, width, height, color); }

void Brick::SetPosition(float x, float y) {
  this->x = x;
  this->y = y;
}

void Brick::SetSize(float width, float height) {
  this->width = width;
  this->height = height;
}

void Brick::SetColor(unsigned char r, unsigned char g, unsigned char b,
                     unsigned char a) {
  color = Color{r, g, b, a};
}

void Brick::SetVisible(bool visible) { this->visible = visible; }

bool Brick::IsVisible() { return visible; }

float Brick::GetX() { return x; }

float Brick::GetY() { return y; }

float Brick::GetWidth() { return width; }

float Brick::GetHeight() { return height; }
