#include "../include/stick_fight/base_stick_figure.h"
#include <iostream>
#include <raylib.h>

StickFigure::StickFigure() {
  currentFrame  = 0;
  framesCounter = 0;
  framesSpeed   = 8;
  position      = Vector2{(float)GetScreenWidth() / 4, (float)GetScreenHeight() / 2};
  frameRec      = Rectangle{0.0f, 0.0f, 300, 600};
}

StickFigure::~StickFigure() {
  for (auto &stickFigure : stickFigures) {
    UnloadTexture(stickFigure);
  }
}

void StickFigure::Draw() {
  // DrawTexture(stickFigures[currentFrame], position.x, position.y, WHITE);
  if (!stickFigures.empty()) {
    DrawTexture(stickFigures[currentFrame], position.x, position.y, WHITE);
  } else {
    std::cerr << "Error: No stick figures to draw." << std::endl;
  }
}

void StickFigure::Update() {
  if (stickFigures.empty()) {
    std::cerr << "Error: No stick figures to update." << std::endl;
    return;
  }
  framesCounter++;
  if (framesCounter >= (60 / framesSpeed)) {
    framesCounter = 0;
    currentFrame++;
    if (currentFrame >= stickFigures.size()) {
      currentFrame = 0;
    }
  }
}

void StickFigure::LoadTextures(const std::filesystem::path &path, const std::string &searchString) {
  for (const auto &entry : std::filesystem::directory_iterator(path)) {
    auto filename = entry.path().filename();
    if (filename.string().find(searchString) != std::string::npos) {
      Texture stickFigure = LoadTexture(entry.path().string().c_str());
      if (stickFigure.id == 0) {
        std::cerr << "Error loading texture: " << entry.path() << std::endl;
        continue;
      }
      stickFigure.height = 600;
      stickFigure.width  = 300;
      stickFigures.push_back(stickFigure);
    }
  }
  if (stickFigures.empty()) {
    std::cerr << "Error: No textures loaded from path " << path << " with search string " << searchString << std::endl;
  }
}

void StickFigure::SetPosition(Vector2 position) {
  this->position = position;
}

Vector2 StickFigure::GetPosition() {
  return position;
}