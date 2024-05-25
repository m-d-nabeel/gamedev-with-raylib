#pragma once

#include "ball.h"
#include "constants.h"
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

private:
  float x;
  float y;
  float width;
  float height;
  Color color;
};