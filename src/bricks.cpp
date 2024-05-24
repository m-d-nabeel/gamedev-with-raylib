#include "bricks.h"
#include "brick.h"
#include "constants.h"
#include <raylib.h>

const Color BRICK_COLORS[] = {RED, ORANGE, YELLOW, GREEN, BLUE, VIOLET, BROWN};

Bricks::Bricks(int hCount, int vCount)
    : brickHorizontalCount(hCount), brickVerticalCount(vCount) {
  arrBricks = new Brick *[brickVerticalCount];
  const int leftoutSpace =
      S_WIDTH - (brickHorizontalCount * BRICK_WIDTH +
                 (brickHorizontalCount - 1) * BRICK_PADDING);
  const int leftPadding = leftoutSpace / 2;
  for (int i = 0; i < brickVerticalCount; i++) {
    arrBricks[i] = new Brick[brickHorizontalCount];
    for (int j = 0; j < brickHorizontalCount; j++) {
      arrBricks[i][j].SetPosition(leftPadding +
                                      j * (BRICK_WIDTH + BRICK_PADDING),
                                  i * (BRICK_HEIGHT + BRICK_PADDING));
      arrBricks[i][j].SetColor(BRICK_COLORS[GetRandomValue(0, 6)]);
      arrBricks[i][j].SetVisible(true);
    }
  }
}

void Bricks::Draw() {
  for (int i = 0; i < brickVerticalCount; i++) {
    for (int j = 0; j < brickHorizontalCount; j++) {
      if (arrBricks[i][j].IsVisible()) {
        arrBricks[i][j].Draw();
      }
    }
  }
}

void Bricks::Update(Ball &ball) {
  for (int i = 0; i < brickVerticalCount; i++) {
    for (int j = 0; j < brickHorizontalCount; j++) {
      if (arrBricks[i][j].IsVisible()) {
        if (arrBricks[i][j].IsCollidingWithBall(ball)) {
          ball.SetSpeedY(ball.GetSpeedY() * -1);
          arrBricks[i][j].SetVisible(false);
        }
        arrBricks[i][j].Draw();
      }
    }
  }
}

void Bricks::Reset() {
  for (int i = 0; i < brickVerticalCount; i++) {
    for (int j = 0; j < brickHorizontalCount; j++) {
      arrBricks[i][j].SetVisible(true);
    }
  }
}

Bricks::~Bricks() {
  for (int i = 0; i < brickVerticalCount; i++) {
    delete[] arrBricks[i];
  }
  delete[] arrBricks;
}
