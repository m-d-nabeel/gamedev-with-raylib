#pragma once

#include "./brick_breaker/game.h"
#include "constants.h"
#include "raylib.h"
#include "utils.h"

#define TOTAL_OPTIONS 3

struct StartMenu {
  static void DisplayStartMenu() {
    int selectedOption      = 1;
    Rectangle pauseMenuRect = {(float)GetScreenWidth() / 2 - 250, (float)GetScreenHeight() / 2 - 250, 500, 500};
    Sound navigateSound     = LoadSound("assets/Sounds/wallHit.wav");
    Sound selectSound       = LoadSound("assets/Sounds/brickBreak.wav");

    defer({
      UnloadSound(navigateSound);
      UnloadSound(selectSound);
      printf("INFO: DEFER: Sounds unloaded successfully\n");
      BeginDrawing();
    });

    while (!WindowShouldClose()) {

      if (IsKeyPressed(KEY_DOWN)) {
        selectedOption++;
        PlaySound(navigateSound);
        if (selectedOption > TOTAL_OPTIONS)
          selectedOption = 1;
      }
      if (IsKeyPressed(KEY_UP)) {
        selectedOption--;
        PlaySound(navigateSound);
        if (selectedOption < 1)
          selectedOption = TOTAL_OPTIONS;
      }
      if (IsKeyPressed(KEY_ENTER)) {
        PlaySound(selectSound);
        switch (selectedOption) {
        case 1:
          StartBrickBreaker();
          break;
        case 2:
          StartStickFightGame();
          break;
        case 3:
          return;
        }
      }
      BeginDrawing();
      DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), Color{0, 0, 0, 100});
      DrawRectangleGradientEx(pauseMenuRect, Color{17, 24, 39, 255}, BLACK, Color{17, 24, 39, 255}, BLACK);
      StartMenu::DrawCenteredText("Brick Breaker", 30, selectedOption == 1 ? RED : WHITE, -50);
      StartMenu::DrawCenteredText("Stick Fight", 30, selectedOption == 2 ? RED : WHITE);
      StartMenu::DrawCenteredText("Exit", 30, selectedOption == 3 ? RED : WHITE, 100);
      EndDrawing();
      if (IsKeyPressed(KEY_ESCAPE)) {
        break;
      }
    }
  }
  static void StartBrickBreaker() {
    Game game = Game();
    game.ResetGame();
    while (!WindowShouldClose()) {
      game.LoopLogic();
      if (game.IsGameEvent(GameEvents::EXIT_EVENT)) {
        break;
      }
    }
  }
  static void StartStickFightGame() {
    // Game game = Game();
    // game.ResetGame();
    // SetExitKey(KEY_NULL);
    // while (!WindowShouldClose()) {
    //   game.LoopLogic();
    //   if (game.IsGameEvent(GameEvents::EXIT_EVENT)) {
    //     break;
    //   }
    // }
  }
  static void DrawCenteredText(const char *text, int fontSize, Color color, int paddingY = 0) {
    float screenWidth  = GetScreenWidth();
    float screenHeight = GetScreenHeight();
    float textWidth    = MeasureText(text, fontSize);
    float textHeight   = fontSize;
    float posX         = screenWidth / 2 - textWidth / 2;
    float posY         = screenHeight / 2 - textHeight / 2 + paddingY;
    DrawText(text, static_cast<int>(posX), static_cast<int>(posY), fontSize, color);
  }
};