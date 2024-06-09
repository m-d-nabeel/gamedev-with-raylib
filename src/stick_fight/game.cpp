#include "../../include/stick_fight/game.h"
#include "../../include/stick_fight/derived_stick_figure.h"
#include "raylib.h"
#include <string>

StickFightGame::StickFightGame() : stickFigure(new SwordStickFigure()), background(LoadTexture("assets/StickFigure/Extras/background1.png")) {
  background.width  = GetScreenWidth();
  background.height = GetScreenHeight();
}

void StickFightGame::SetStickFigure(StickFigure *stickFigure) {
  delete this->stickFigure;
  this->stickFigure = stickFigure;
}

void StickFightGame::SetBackground(Texture background) {
  this->background = background;
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
  // ------ Change stick figure ------
  if (IsKeyPressed(KEY_R)) {
    const int random = GetRandomValue(0, 2);
    if (random == 0) {
      FighterStickFigure *fighterStickFigure = new FighterStickFigure();
      SetStickFigure(fighterStickFigure);
    } else if (random == 1) {
      SwordStickFigure *swordStickFigure = new SwordStickFigure();
      SetStickFigure(swordStickFigure);
    } else if (random == 2) {
      StickFigure *stickFigure = new PistolStickFigure();
      SetStickFigure(stickFigure);
    }
  }
  // ------ Change stick figure ------
  std::string newState  = StickFigureState::IDLE;
  int movementDirection = 0;

  if (IsKeyDown(KEY_RIGHT) && IsKeyDown(KEY_LEFT_SHIFT)) {
    movementDirection = 1;
    newState          = StickFigureState::RUN;
  }
  if (IsKeyDown(KEY_LEFT) && IsKeyDown(KEY_LEFT_SHIFT)) {
    movementDirection = -1;
    newState          = StickFigureState::RUN;
  }
  if (IsKeyDown(KEY_RIGHT) && !IsKeyDown(KEY_LEFT_SHIFT)) {
    movementDirection = 1;
    newState          = StickFigureState::WALK;
  }
  if (IsKeyDown(KEY_LEFT) && !IsKeyDown(KEY_LEFT_SHIFT)) {
    movementDirection = -1;
    newState          = StickFigureState::WALK;
  }
  if (IsKeyDown(KEY_SPACE)) {
    newState = StickFigureState::JUMP;
  }
  
  if (stickFigure->GetState() != newState) {
    stickFigure->SetMovementDirection(movementDirection);
    stickFigure->SetState(newState);
  }
}

void StickFightGame::UpdateGame() {
  // stickFigure->Update();
}
// Path: src/stick_fight/main.cpp