#include "../include/constants.h"
#include "../include/game.h"
#include <raylib.h>

int main() {
  InitWindow(INIT_SWIDTH, INIT_SHEIGHT, "Breakout Game");
  InitAudioDevice();
  SetTargetFPS(FRAME_RATE);
  Game game = Game();
  game.ResetGame();
  while (!WindowShouldClose()) {
    game.LoopLogic();
  }
  CloseAudioDevice();
  CloseWindow();
  return 0;
}
