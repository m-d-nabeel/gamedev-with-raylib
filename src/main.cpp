#include "../include/constants.h"
#include "../include/game.h"
#include <raylib.h>

int main() {
  InitWindow(INIT_SWIDTH, INIT_SHEIGHT, "Learning CPP with Raylib");
  SetTargetFPS(FRAME_RATE);
  Game game = Game();
  while (!WindowShouldClose()) {
    game.HandleKeyboardInput();
    game.UpdateGame();
    BeginDrawing();
    game.DrawGame();
    EndDrawing();
  }
  return 0;
}
