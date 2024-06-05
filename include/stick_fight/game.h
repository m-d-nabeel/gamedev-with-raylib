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
  void SetStickFigure(StickFigure *stickFigure);
  void SetBackground(Texture background);
  // StickFightGame(const StickFightGame &) = delete; // Delete copy constructor
};