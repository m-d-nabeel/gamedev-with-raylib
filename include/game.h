#pragma once

#include "ball.h"
#include "bat.h"
#include "bricks.h"
#include "constants.h"
#include "raylib.h"

class Game {
public:
  Game();
  void ResetGame();
  void UpdateGame();
  void DrawGame();
  void HandleKeyboardInput();
  static void DrawCenteredText(const char *text, int fontSize, Color color, int paddingY = 0);
  ~Game();

private:
  Ball ball;
  Bat bat;
  Bricks *bricks;
  GameState gameState;
  int hBricksCount;
  int vBricksCount;

public:
  static bool isFullscreen;
};
