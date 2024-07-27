#include "../include/brick_breaker/brick.h"
#include "../include/constants.h"
#include <string>
#include <vector>
#include <raylib.h>

const std::vector<std::string> bricks = {
    "src/resources/Bricks/Brick 1 - 128x128.png",
    "src/resources/Bricks/Brick 2 - 128x128.png",
    "src/resources/Bricks/Brick 3 - 128x128.png",
    "src/resources/Bricks/Brick 4 - 128x128.png",
    "src/resources/Bricks/Brick 5 - 128x128.png",
    "src/resources/Bricks/Brick 6 - 128x128.png",
    "src/resources/Bricks/Brick 7 - 128x128.png",
    "src/resources/Bricks/Brick 8 - 128x128.png",
    "src/resources/Bricks/Brick 9 - 128x128.png",
    "src/resources/Bricks/Brick 10 - 128x128.png",
    "src/resources/Bricks/Brick 11 - 128x128.png",
    "src/resources/Bricks/Brick 12 - 128x128.png",
    "src/resources/Bricks/Brick 13 - 128x128.png",
    "src/resources/Bricks/Brick 14 - 128x128.png",
    "src/resources/Bricks/Brick 15 - 128x128.png",
    "src/resources/Bricks/Brick 16 - 128x128.png",
    "src/resources/Bricks/Brick 17 - 128x128.png",
    "src/resources/Bricks/Brick 18 - 128x128.png",
    "src/resources/Bricks/Brick 19 - 128x128.png",
    "src/resources/Bricks/Brick 20 - 128x128.png",
    "src/resources/Bricks/Brick 21 - 128x128.png",
    "src/resources/Bricks/Brick 22 - 128x128.png",
    "src/resources/Bricks/Brick 23 - 128x128.png",
};

Brick::Brick() {
  width            = BRICK_WIDTH;
  height           = BRICK_HEIGHT;
  x                = 100;
  y                = 100;
  color            = BLANK;
  visible          = true;
  Image brickImage = LoadImage(bricks[GetRandomValue(0, bricks.size() - 1)].c_str());
  ImageCrop(&brickImage, Rectangle{0, 0, width, height});
  texture = LoadTextureFromImage(brickImage);
  UnloadImage(brickImage);
}

void Brick::Draw() {
  DrawTexture(texture, x, y, color);
}

void Brick::SetPosition(float x, float y) {
  this->x = x;
  this->y = y;
}

void Brick::SetColor(Color c) {
  color = c;
}

bool Brick::IsCollidingWithBall(Ball &ball) {
  Rectangle brickRectangle = {x, y, BRICK_WIDTH, BRICK_HEIGHT};
  return CheckCollisionCircleRec(ball.GetPosition(), BALL_RADIUS, brickRectangle);
}

void Brick::SetVisible(bool visible) {
  this->visible = visible;
}

bool Brick::IsVisible() {
  return visible;
}

float Brick::GetX() {
  return x;
}

float Brick::GetY() {
  return y;
}

Color Brick::GetColor() {
  return color;
}