#pragma once

#include "base_stick_figure.h"
#include "raylib.h"
class StickFightGame {
private:
  StickFigure *stickFigure;
  Texture background;

public:
  StickFightGame();
  ~StickFightGame() = default;
  void LoopLogic();
  void DrawGame();
  void HandleInput();
  void UpdateGame();
};