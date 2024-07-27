#include "./include/constants.h"
#include "./include/start_menu.h"
#include <raylib.h>

int main() {
  InitWindow(INIT_SWIDTH, INIT_SHEIGHT, "Breakout Game");
  InitAudioDevice();
  SetTargetFPS(FRAME_RATE);
  SetExitKey(KEY_NULL);
  // Start the game
  StartMenu::DisplayStartMenu();
  // Close the game
  CloseAudioDevice();
  CloseWindow();
  return 0;
}
