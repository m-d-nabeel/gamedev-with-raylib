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
  bool isFullScreen;
  unsigned int hBricksCount;
  unsigned int vBricksCount;
  unsigned int score;
  unsigned int lives;
  unsigned int level;
  Texture2D heartTexture;
  PowerUpType powerUpType;
  PowerUpState powerUpState;
  PowerUpDuration powerUpDuration;
  Sound allBricksBrokenSound;
};
