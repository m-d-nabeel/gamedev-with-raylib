#include "../../include/stick_fight/base_stick_figure.h"
#include <iostream>
#include <string>
#include <raylib.h>

StickFigure::StickFigure() {
  currentFrame      = 0;
  framesCounter     = 0;
  framesSpeed       = 8;
  position          = Vector2{(float)GetScreenWidth() / 4, (float)GetScreenHeight() / 2};
  frameRec          = Rectangle{0.0f, 0.0f, 300, 600};
  figureSpeed       = FIGURE_SPEED;
  currentState      = "Idle";
  movementDirection = 0;
  isJumping         = false;
  jumpDirection     = 1;
  jumpStartY        = position.y;
  jumpHeight        = 100.0f;
  searchString      = {
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
      "shot",
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
  if (currentState == StickFigureState::JUMP) {
    if (!isJumping) {
      Jump();
    } else {
      UpdateJump();
    }
  }
  if (currentState == StickFigureState::RUN) {
    figureSpeed = FIGURE_SPEED * 1.25;
    Move(movementDirection);
  }
  if (currentState == StickFigureState::WALK) {
    figureSpeed = FIGURE_SPEED;
    Move(movementDirection);
  }
  if (currentState == StickFigureState::IDLE) {
    figureSpeed = FIGURE_SPEED;
  }
  if (currentState == StickFigureState::SLIDE) {
    Slide();
  }
  if (currentState == StickFigureState::DEATH) {
    Death();
  }
}

// Animation functions
void StickFigure::AnimateInReverse() {
  framesCounter++;
  if (framesCounter >= (60 / framesSpeed)) {
    framesCounter = 0;
    currentFrame--;
    if (currentFrame < 0) {
      currentFrame = stickFigures[currentState].size() - 1;
    }
  }
}

void StickFigure::DefaultAnimation() {
  framesCounter++;
  if (framesCounter >= (60 / framesSpeed)) {
    framesCounter = 0;
    currentFrame++;
    if (currentFrame >= stickFigures[currentState].size()) {
      currentFrame = 0;
    }
  }
}

// Movement functions
void StickFigure::Move(int direction) {
  if (direction == 0) {
    return;
  }
  if (direction == 1) {
    position.x += figureSpeed;
    if (position.x >= GetScreenWidth() - stickFigures[currentState][currentFrame].width) {
      position.x = GetScreenWidth() - stickFigures[currentState][currentFrame].width;
    }
    DefaultAnimation();
  }
  if (direction == -1) {
    position.x -= figureSpeed;
    if (position.x <= 0) {
      position.x = 0;
    }
    AnimateInReverse();
  }
}

void StickFigure::Jump() {
  if (!isJumping) {
    isJumping     = true;
    jumpDirection = 1;
    jumpStartY    = position.y;
    SetState("jump");
  }
}
void StickFigure::UpdateJump() {
  if (isJumping) {
    if (jumpDirection == 1) {
      position.y -= figureSpeed;
      if (position.y <= jumpStartY - jumpHeight) {
        position.y    = jumpStartY - jumpHeight;
        jumpDirection = -1;
      }
    } else if (jumpDirection == -1) {
      position.y += figureSpeed;
      if (position.y >= jumpStartY) {
        position.y    = jumpStartY;
        jumpDirection = 0;
        isJumping     = false;
        SetState("Idle"); // Transition back to Idle state after landing
      }
    }
    DefaultAnimation(); // Animate while jumping
  }
}

void StickFigure::Slide() {
  SetState("slide");
}

void StickFigure::Death() {
  SetState("death");
}

void StickFigure::Dash() {
  SetState("dash");
}

// Load textures
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

void StickFigure::SetState(const std::string &state) {
  if (stickFigures.find(state) == stickFigures.end()) {
    std::cerr << "State not found: " << state << std::endl;
    return;
  }
  currentState = state;
}

void StickFigure::SetMovementDirection(int direction) {
  movementDirection = direction;
}

std::string StickFigure::GetState() {
  return currentState;
}

FigureType StickFigure::GetFigureType() {
  return figType;
}