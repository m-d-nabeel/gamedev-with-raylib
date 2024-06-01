#include "../../include/stick_fight/game.h"
#include "raylib.h"

StickFightGame::StickFightGame() {
  stickFigure       = StickFigure();
  background        = LoadTexture("assets/StickFigure/Extras/background1.png");
  background.width  = GetScreenWidth();
  background.height = GetScreenHeight();
}

void StickFightGame::LoopLogic() {
  HandleInput();
  UpdateGame();
  DrawGame();
}

void StickFightGame::DrawGame() {
  BeginDrawing();
  ClearBackground(WHITE);
  DrawTexture(background, 0, 0, WHITE);
  stickFigure.AnimateStickFigure();
  EndDrawing();
}

void StickFightGame::HandleInput() {
  // Handle input
}

void StickFightGame::UpdateGame() {
  // Update the game
}

// Path: src/stick_fight/main.cpp