#pragma once

#include "ball.h"
#include "bat.h"
#include "bricks.h"
#include "constants.h"

class Game {
public:
  Game();
  void ResetGame();
  void UpdateGame();
  void DrawGame();
  void HandleKeyboardInput();
  static inline float GetScreenWidth() {
    return static_cast<float>(GetScreenWidth());
  }
  static inline float GetScreenHeight() {
    return static_cast<float>(GetScreenHeight());
  }
  inline void DrawCenteredText(const char *text, int fontSize, Color color, int paddingY = 0) {
    float width = MeasureText(text, fontSize);
    DrawText(text, INIT_SWIDTH / 2 - width / 2, INIT_SHEIGHT / 2 + paddingY, fontSize, color);
  }
  ~Game();

private:
  Ball ball;
  Bat bat;
  Bricks *bricks;
  GameState gameState;
  int ScreenWidth;
  int ScreenHeight;
};