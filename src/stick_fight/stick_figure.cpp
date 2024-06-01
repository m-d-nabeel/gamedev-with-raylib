#include "../../include/stick_fight/stick_figure.h"
#include <filesystem>
#include <raylib.h>

StickFigure::StickFigure() {
  currentFrame               = 0;
  framesCounter              = 0;
  framesSpeed                = 18;
  position                   = Vector2{(float)GetScreenWidth() / 2, 3 * (float)GetScreenHeight() / 4};
  std::filesystem::path path = "assets/StickFigure/Fighter sprites";
  for (const auto &entry : std::filesystem::directory_iterator(path)) {
    auto filename = entry.path().filename();
    if (filename.string().find("fighter_run") != std::string::npos) {
      Texture stickFigure = LoadTexture(entry.path().string().c_str());
      stickFigure.height  = 200;
      stickFigure.width   = 200;
      stickFigures.push_back(stickFigure);
    }
  }
}

void StickFigure::Draw() {
  DrawTexture(stickFigures[currentFrame], position.x, position.y, WHITE);
}

void StickFigure::Update() {
  framesCounter++;
  if (framesCounter >= (60 / framesSpeed)) {
    framesCounter = 0;
    currentFrame++;
    if (currentFrame > stickFigures.size() - 1) {
      currentFrame = 0;
    }
  }
}

void StickFigure::AnimateStickFigure() {
  Update();
  Draw();
}

