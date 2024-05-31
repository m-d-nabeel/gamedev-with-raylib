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
  void SaveGameProgress();
  void LoadGameProgress();
  void DisplayPauseMenu();
  bool IsGameEvent(GameEvents gameEvent);
  ~Game() = default;

private:
  Ball ball;
  Bat bat;
  Bricks bricks;
  GameState gameState;
  GameEvents gameSaveEvent;
  Texture2D heartTexture;
  PowerUpType powerUpType;
  PowerUpState powerUpState;
  PowerUpDuration powerUpDuration;
  Sound allBricksBrokenSound;

private:
  bool isFullScreen;
  unsigned int hBricksCount;
  unsigned int vBricksCount;
  unsigned int score;
  unsigned int lives;
  unsigned int level;
};
