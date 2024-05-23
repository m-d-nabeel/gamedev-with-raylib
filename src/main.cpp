#include "ball.h"
#include "brick.h"
#include <raylib.h>

int main() {
  Color darkGreen = Color{20, 160, 133, 255};

  const int screenWidth = 800;
  const int screenHeight = 600;

  Ball ball = Ball();

  InitWindow(screenWidth, screenHeight, "Learning CPP with Raylib");
  SetTargetFPS(60);

  Brick arrBricks[3][5];

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 5; j++) {
      arrBricks[i][j].SetPosition(100 + j * 120, 100 + i * 40);
      arrBricks[i][j].SetSize(100, 30);
      arrBricks[i][j].SetVisible(true);
      if (i == 0)
        arrBricks[i][j].SetColor(DARKGREEN.r, DARKGREEN.g, DARKGREEN.b,
                                 DARKGREEN.a);
      else if (i == 1)
        arrBricks[i][j].SetColor(RED.r, RED.g, RED.b, RED.a);
      else if (i == 2)
        arrBricks[i][j].SetColor(YELLOW.r, YELLOW.g, YELLOW.b, YELLOW.a);
    }
  }

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(Color{20, 20, 20, 255});
    ball.Update();
    ball.Draw();

    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 5; j++) {
        if (arrBricks[i][j].IsVisible()) {
          if (CheckCollisionCircleRec(
                  Vector2{ball.GetX(), ball.GetY()}, ball.GetRadius(),
                  Rectangle{arrBricks[i][j].GetX(), arrBricks[i][j].GetY(),
                            arrBricks[i][j].GetWidth(),
                            arrBricks[i][j].GetHeight()})) {
            ball.SetSpeedY(ball.GetSpeedY() * -1);
            arrBricks[i][j].SetVisible(false);
          }
          arrBricks[i][j].Draw();
        }
      }
    }
    EndDrawing();
  }

  CloseWindow();
  return 0;
}