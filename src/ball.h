#pragma once

class Ball {
public:
  Ball();
  void Update();
  void Draw();
  float GetX();
  float GetY();
  void SetX(float x);
  void SetY(float y);
  float GetRadius();
  float GetSpeedX();
  float GetSpeedY();
  void SetSpeedX(float speedX);
  void SetSpeedY(float speedY);
  bool IsNotMoving();

private:
  float x;
  float y;
  float speedX;
  float speedY;
  float radius;
};