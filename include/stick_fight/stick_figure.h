#pragma once

#include <vector>
#include <raylib.h>

class StickFigure {
public:
  StickFigure();
  ~StickFigure() = default;
  void Draw();
  void Update();
  void AnimateStickFigure();

private:
  Texture runningStickFigure;
  std::vector<Texture> stickFigures;
  int currentFrame;
  int framesCounter;
  int framesSpeed;
  Vector2 position;
  Rectangle frameRec;
};