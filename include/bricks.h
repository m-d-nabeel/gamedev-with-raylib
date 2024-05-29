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
  void Update(Ball &ball, unsigned int &score);
  void Draw();
  void RenderForCurrWindow();
  bool IsAllBricksDestroyed();
  void Reset();
  ~Bricks() = default;

private:
  std::vector<std::vector<Brick>> arrBricks;
  int bHCount;
  int bVCount;
  int totalBricks;
};
