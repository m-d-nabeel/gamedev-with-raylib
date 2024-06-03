#include "../../include/stick_fight/game.h"
#include "../../include/stick_fight/derived_stick_figure.h"
#include "raylib.h"
#include <iostream>

StickFightGame::StickFightGame() : stickFigure(new FighterStickFigure()), background(LoadTexture("assets/StickFigure/Extras/background1.png")) {
  if (stickFigure == nullptr) {
    std::cerr << "Error: stickFigure is null" << std::endl;
  }
  if (background.id == 0) {
    std::cerr << "Error loading background texture." << std::endl;
  }
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
  stickFigure->Update();
  stickFigure->Draw();
  EndDrawing();
}

void StickFightGame::HandleInput() {
  // Handle input
}

void StickFightGame::UpdateGame() {
  // Update the game
}

// Path: src/stick_fight/main.cpp