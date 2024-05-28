#include "../include/bricks.h"
#include "../include/brick.h"
#include "../include/constants.h"
#include "raymath.h"
#include <vector>
#include <raylib.h>

const Color BRICK_COLORS[] = {BLUE, VIOLET, BROWN, DARKGRAY, GOLD, MAROON, BEIGE};

Bricks::Bricks() {
  bHCount     = 0;
  bVCount     = 0;
  totalBricks = 0;
  arrBricks   = std::vector<std::vector<Brick>>();
}

Bricks::Bricks(int hCount, int vCount) : bHCount(hCount), bVCount(vCount) {
  arrBricks              = std::vector<std::vector<Brick>>(bVCount, std::vector<Brick>(bHCount));
  totalBricks            = bHCount * bVCount;
  const int leftoutSpace = GetScreenWidth() - (bHCount * BRICK_WIDTH + (bHCount - 1) * BRICK_PADDING);
  const int leftPadding  = leftoutSpace / 2;
  for (int i = 0; i < bVCount; i++) {
    for (int j = 0; j < bHCount; j++) {
      arrBricks[i][j].SetPosition(leftPadding + j * (BRICK_WIDTH + BRICK_PADDING), i * (BRICK_HEIGHT + BRICK_PADDING));
      arrBricks[i][j].SetColor(BRICK_COLORS[GetRandomValue(0, 6)]);
      arrBricks[i][j].SetVisible(true);
    }
  }
}

void Bricks::Draw() {
  for (int i = 0; i < bVCount; i++) {
    for (int j = 0; j < bHCount; j++) {
      if (arrBricks[i][j].IsVisible()) {
        arrBricks[i][j].Draw();
      }
    }
  }
}

void Bricks::Update(Ball &ball) {
  for (int i = 0; i < bVCount; i++) {
    for (int j = 0; j < bHCount; j++) {
      if (arrBricks[i][j].IsVisible()) {
        if (arrBricks[i][j].IsCollidingWithBall(ball)) {
          ball.SetSpeed(Vector2Reflect(ball.GetSpeed(), {0, 1}));
          arrBricks[i][j].SetVisible(false);
          totalBricks--;
        }
        arrBricks[i][j].Draw();
      }
    }
  }
}

void Bricks::RenderForCurrWindow() {
  std::vector<std::vector<Brick>> newArrBricks = std::vector<std::vector<Brick>>(bVCount, std::vector<Brick>(bHCount));
  totalBricks                                  = bHCount * bVCount;
  const int leftoutSpace = GetScreenWidth() - (bHCount * BRICK_WIDTH + (bHCount - 1) * BRICK_PADDING);
  const int leftPadding  = leftoutSpace / 2;
  for (int i = 0; i < bVCount; i++) {
    for (int j = 0; j < bHCount; j++) {
      newArrBricks[i][j].SetPosition(
          leftPadding + j * (BRICK_WIDTH + BRICK_PADDING), i * (BRICK_HEIGHT + BRICK_PADDING));
      newArrBricks[i][j].SetColor(arrBricks[i][j].GetColor());
      newArrBricks[i][j].SetVisible(arrBricks[i][j].IsVisible());
    }
  }
  arrBricks = newArrBricks;
}

bool Bricks::IsAllBricksDestroyed() {
  return totalBricks == 0;
}