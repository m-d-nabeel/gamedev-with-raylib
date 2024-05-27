#pragma once

#include "ball.h"
#include "brick.h"
#include <raylib.h>

#include <memory>
#include <vector>

class Bricks {
public:
  Bricks();
  Bricks(int bHCount, int bVCount);
  void Update(Ball &ball);
  void Draw();
  void RenderForCurrWindow();
  bool IsAllBricksDestroyed();
  ~Bricks() = default;

private:
  std::vector<std::vector<Brick>> arrBricks;
  int bHCount;
  int bVCount;
  int totalBricks;
};
