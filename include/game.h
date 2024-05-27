#pragma once

#include "ball.h"
#include "bat.h"
#include "bricks.h"
#include "constants.h"
#include "raylib.h"

class Game {
public:
  Game();
  void LoopLogic();
  void ResetGame();
  void UpdateGame();
  void DrawGame();
  void HandleKeyboardInput();
  void RedrawBricks();
  static void DrawCenteredText(const char *text, int fontSize, Color color, int paddingY = 0);
  ~Game() = default;

private:
  Ball ball;
  Bat bat;
  Bricks bricks;
  GameState gameState;
  int hBricksCount;
  int vBricksCount;
  bool isFullScreen;
};
