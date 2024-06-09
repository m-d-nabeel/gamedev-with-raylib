#pragma once

#include "../constants.h"
#include <filesystem>
#include <string>
#include <unordered_map>
#include <vector>
#include <raylib.h>

class StickFigure {
public:
  StickFigure();
  virtual ~StickFigure();
  virtual void Draw();
  virtual void Update();
  virtual void AnimateInReverse();
  virtual void DefaultAnimation();

  virtual void SetState(const std::string &state);
  virtual void SetPosition(Vector2 position);
  virtual void SetMovementDirection(int direction);

  virtual Vector2 GetPosition();
  virtual std::string GetState();
  virtual FigureType GetFigureType();

  virtual void Move(int direction);
  virtual void Jump();
  virtual void Slide();
  virtual void Death();
  virtual void Dash();
  virtual void UpdateJump();

protected:
  void LoadTextures(const std::filesystem::path &path);

  int figureSpeed;
  int currentFrame;
  int framesCounter;
  int framesSpeed;
  int movementDirection;
  bool isJumping;
  int jumpDirection;
  float jumpStartY;
  float jumpHeight;

  FigureType figType;
  Vector2 position;
  Rectangle frameRec;

  std::unordered_map<std::string, std::vector<Texture>> stickFigures;
  std::vector<std::string> searchString;
  std::string currentState;
};