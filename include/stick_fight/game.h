#pragma once

#include "raylib.h"
#include "stick_figure.h"
class StickFightGame {
private:
  StickFigure stickFigure;
  Texture background;

public:
  StickFightGame();
  ~StickFightGame() = default;
  void LoopLogic();
  void DrawGame();
  void HandleInput();
  void UpdateGame();
};