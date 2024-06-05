#include "../include/constants.h"
#include "../include/start_menu.h"
#include <raylib.h>

int main() {
  int monitor = GetCurrentMonitor();
  InitWindow(GetMonitorWidth(monitor), GetMonitorWidth(monitor), "Breakout Game");
  InitAudioDevice();
  SetTargetFPS(FRAME_RATE);
  SetExitKey(KEY_NULL);
  ToggleFullscreen();
  // Start the game
  StartMenu::DisplayStartMenu();
  // Close the game
  CloseAudioDevice();
  CloseWindow();
  return 0;
}
