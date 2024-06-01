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
  GameEvents gameEvent;
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
