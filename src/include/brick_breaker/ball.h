#pragma once

#include "raylib.h"
#include "raymath.h"

class Ball {
public:
  Ball();
  void Update();
  void Draw() const;
  bool IsNotMoving() const;
  bool IsCollidingWithBottomWall() const;
  void SetPosition(Vector2 position);
  void SetSpeed(Vector2 speed);
  Vector2 GetSpeed() const;
  Vector2 GetPosition() const;
  float GetRadius() const;
  float GetDefaultSpeed() const;
  void SetDefaultSpeed(float speed);
  void Reset();

private:
  Vector2 position;
  Vector2 speed;
  float radius;
  float defaultSpeed;
  Texture2D texture;
  Sound wallHitSound;
  Sound gameOverSound;
  unsigned int ballHitPower;
  Rectangle frameRec;
  int currentFrame;
  int framesCounter;
  int framesSpeed;
};