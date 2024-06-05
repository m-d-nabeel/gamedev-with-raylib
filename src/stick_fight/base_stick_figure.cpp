#include "../../include/stick_fight/base_stick_figure.h"
#include <iostream>
#include <string>
#include <raylib.h>

StickFigure::StickFigure() {
  currentFrame  = 0;
  framesCounter = 0;
  framesSpeed   = 8;
  position      = Vector2{(float)GetScreenWidth() / 4, (float)GetScreenHeight() / 2};
  frameRec      = Rectangle{0.0f, 0.0f, 300, 600};
  figureSpeed   = 10;
  currentState  = "Idle";
  searchString  = {
      "Idle",
      "air_attack",
      "climb",
      "combo",
      "death",
      "dash",
      "hit",
      "jump",
      "run",
      "slide",
      "walk",
  };
  for (const std::string &s : searchString) {
    stickFigures[s] = std::vector<Texture>();
  }
}

StickFigure::~StickFigure() {
  for (auto &pair : stickFigures) {
    for (Texture &texture : pair.second) {
      UnloadTexture(texture);
    }
  }
  stickFigures.clear();
}

void StickFigure::Draw() {
  DrawTexture(stickFigures[currentState][currentFrame], position.x, position.y, WHITE);
}

void StickFigure::Update() {
  framesCounter++;
  if (framesCounter >= (60 / framesSpeed)) {
    framesCounter = 0;
    currentFrame++;
    if (currentFrame > stickFigures[currentState].size() - 1) {
      currentFrame = 0;
    }
  }
}

void StickFigure::LoadTextures(const std::filesystem::path &path) {
  for (const std::string &str : searchString) {
    for (const auto &entry : std::filesystem::directory_iterator(path)) {
      auto filename = entry.path().filename();
      if (filename.string().find(str) != std::string::npos) {
        Texture stickFigure = LoadTexture(entry.path().string().c_str());
        if (stickFigure.id == 0) {
          std::cerr << "Error loading texture: " << entry.path() << std::endl;
          continue;
        }
        stickFigure.height = 600;
        stickFigure.width  = 300;
        stickFigures[str].push_back(stickFigure);
      }
    }
  }
}

void StickFigure::SetPosition(Vector2 position) {
  this->position = position;
}

Vector2 StickFigure::GetPosition() {
  return position;
}

void StickFigure::MoveRight() {
  position.x += figureSpeed;
  if (position.x >= GetScreenWidth() - stickFigures[currentState][currentFrame].width) {
    position.x = GetScreenWidth() - stickFigures[currentState][currentFrame].width;
  }
}

void StickFigure::MoveLeft() {
  position.x -= figureSpeed;
  if (position.x <= 0) {
    position.x = 0;
  }
}

void StickFigure::SetState(const std::string &state) {
  if (stickFigures.find(state) == stickFigures.end()) {
    std::cerr << "State not found: " << state << std::endl;
    return;
  }
  currentState = state;
}

std::string StickFigure::GetState() {
  return currentState;
}