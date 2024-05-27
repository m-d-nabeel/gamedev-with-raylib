#pragma once

#include "ball.h"
#include "brick.h"
#include <raylib.h>

class Bricks {
public:
  Bricks();
  Bricks(int brickHorizontalCount, int brickVerticalCount);
  void Update(Ball &ball);
  void Draw();
  void Reset();
  bool IsAllBricksDestroyed();
  ~Bricks();

private:
  Brick **arrBricks;
  int brickHorizontalCount;
  int brickVerticalCount;
  int totalBricks;
};