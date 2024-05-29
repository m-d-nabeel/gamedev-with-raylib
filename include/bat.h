#pragma once

#include "../include/constants.h"
#include "ball.h"
#include "raylib.h"
class Bat {
public:
  Bat();
  void Draw();
  float GetX();
  bool IsCollidingWithBall(Ball &ball);
  void HandleCollisionWithBall(Ball &ball);
  void Move(int direction, Ball &ball);
  void HandleKeyboardInput(Ball &ball, GameState &gameState);
  int GetMovement();
  void Reset();

private:
  float x;
  float y;
  float width;
  float height;
  int movement;
  Color color;
  Sound hitSound;
};