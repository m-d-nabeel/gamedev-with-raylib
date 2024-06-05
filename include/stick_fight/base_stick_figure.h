#pragma once

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
  virtual void SetPosition(Vector2 position);
  virtual Vector2 GetPosition();
  virtual void MoveRight();
  virtual void MoveLeft();
  virtual void SetState(const std::string &state);
  virtual std::string GetState();

protected:
  void LoadTextures(const std::filesystem::path &path);
  int figureSpeed;
  int currentFrame;
  int framesCounter;
  int framesSpeed;
  Vector2 position;
  Rectangle frameRec;
  std::unordered_map<std::string, std::vector<Texture>> stickFigures;
  std::vector<std::string> searchString;
  std::string currentState;
};