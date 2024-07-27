#include "../include/brick_breaker/bricks.h"
#include "../include/brick_breaker/brick.h"
#include "../include/constants.h"
#include "raymath.h"
#include <vector>
#include <raylib.h>

const Color BRICK_COLORS[] = {BLUE, VIOLET, BROWN, DARKGRAY, GOLD, MAROON, BEIGE};

Bricks::Bricks() {
  bHCount         = 0;
  bVCount         = 0;
  totalBricks     = 0;
  arrBricks       = std::vector<std::vector<Brick>>();
  brickBreakSound = LoadSound("src/resources/Sounds/brickBreak.wav");
  SetSoundVolume(brickBreakSound, 0.5f);
}

Bricks::Bricks(int hCount, int vCount) : bHCount(hCount), bVCount(vCount) {
  arrBricks              = std::vector<std::vector<Brick>>(bVCount, std::vector<Brick>(bHCount));
  totalBricks            = bHCount * bVCount;
  const int leftoutSpace = GetScreenWidth() - (bHCount * BRICK_WIDTH + (bHCount - 1) * BRICK_PADDING);
  const int leftPadding  = leftoutSpace / 2;
  brickBreakSound        = LoadSound("src/resources/Sounds/brickBreak.wav");
  SetSoundVolume(brickBreakSound, 0.5f);

  for (int i = 0; i < bVCount; i++) {
    for (int j = 0; j < bHCount; j++) {
      arrBricks[i][j].SetPosition(leftPadding + j * (BRICK_WIDTH + BRICK_PADDING), i * (BRICK_HEIGHT + BRICK_PADDING) + TOP_PADDING);
      arrBricks[i][j].SetColor(BRICK_COLORS[GetRandomValue(0, 6)]);
      arrBricks[i][j].SetVisible(true);
    }
  }
}

void Bricks::Reset() {
  totalBricks = bHCount * bVCount;
  for (int i = 0; i < bVCount; i++) {
    for (int j = 0; j < bHCount; j++) {
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

void Bricks::Update(Ball &ball, unsigned int &score) {
  for (int i = 0; i < bVCount; i++) {
    for (int j = 0; j < bHCount; j++) {
      if (arrBricks[i][j].IsVisible()) {
        if (arrBricks[i][j].IsCollidingWithBall(ball)) {
          ball.SetSpeed(Vector2Reflect(ball.GetSpeed(), {0, 1}));
          arrBricks[i][j].SetVisible(false);
          totalBricks--;
          score += 10;
          PlaySound(brickBreakSound);
        }
        arrBricks[i][j].Draw();
      }
    }
  }
}

void Bricks::RenderForCurrWindow() {
  totalBricks            = bHCount * bVCount;
  const int leftoutSpace = GetScreenWidth() - (bHCount * BRICK_WIDTH + (bHCount - 1) * BRICK_PADDING);
  const int leftPadding  = leftoutSpace / 2;
  for (int i = 0; i < bVCount; i++) {
    for (int j = 0; j < bHCount; j++) {
      arrBricks[i][j].SetPosition(leftPadding + j * (BRICK_WIDTH + BRICK_PADDING), i * (BRICK_HEIGHT + BRICK_PADDING) + TOP_PADDING);
    }
  }
}

void Bricks::SetBrickDestroyed(int x, int y) {
  arrBricks[y][x].SetVisible(false);
  totalBricks--;
}

bool Bricks::IsAllBricksDestroyed() {
  return totalBricks == 0;
}

bool Bricks::IsBrickDestroyed(int x, int y) {
  return !arrBricks[y][x].IsVisible();
}