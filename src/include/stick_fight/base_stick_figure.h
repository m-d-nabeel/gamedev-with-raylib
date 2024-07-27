#pragma once

#include <filesystem>
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

protected:
  void LoadTextures(const std::filesystem::path &path, const std::string &searchString = "Idle");
  int currentFrame;
  int framesCounter;
  int framesSpeed;
  Vector2 position;
  Rectangle frameRec;
  std::vector<Texture> stickFigures;
};