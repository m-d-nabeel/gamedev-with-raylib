#include "../include/game.h"
#include "../include/constants.h"
#include "../include/utils.h"
#include "raylib.h"
#include <cstdio>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>

constexpr bool DEB_ENV = false;

Game::Game() {
  gameState            = PLAYING;
  hBricksCount         = DEB_ENV ? 1 : (INIT_SWIDTH + BRICK_PADDING) / (BRICK_WIDTH + BRICK_PADDING);
  vBricksCount         = DEB_ENV ? 1 : (INIT_SHEIGHT / 2) / (BRICK_HEIGHT + BRICK_PADDING);
  bricks               = Bricks(hBricksCount, vBricksCount);
  bat                  = Bat();
  ball                 = Ball();
  isFullScreen         = false;
  score                = 0;
  lives                = 3;
  level                = 1;
  powerUpType          = NONE;
  powerUpState         = INACTIVE;
  gameSaveEvent        = NULL_EVENT;
  heartTexture         = LoadTexture("assets/heart.png");
  heartTexture.width   = 25;
  heartTexture.height  = 25;
  allBricksBrokenSound = LoadSound("assets/Sounds/allBricksBrokenSound.wav");
}

void Game::ResetGame() {
  score        = 0;
  lives        = 3;
  level        = 1;
  powerUpType  = NONE;
  powerUpState = INACTIVE;
  ball.Reset();
  bat.Reset();
  bricks.Reset();
}

void Game::UpdateGame() {
  if (gameState == GAME_OVER || gameState == PAUSED || gameState == GAME_WON) {
    return;
  }
  if (ball.IsCollidingWithBottomWall()) {
    lives--;
    gameState = LIVE_LOST;
    if (lives == 0) {
      gameState = GAME_OVER;
      return;
    }
    ball.Reset();
    bat.Reset();
    return;
  }
  if (bricks.IsAllBricksDestroyed()) {
    PlaySound(allBricksBrokenSound);
    gameState = GAME_WON;
    return;
  }
  bat.HandleKeyboardInput(ball, gameState);
  bricks.Update(ball, score);
  ball.Update();
  bat.HandleCollisionWithBall(ball);
}

void Game::DrawGame() {
  ClearBackground(Color{3, 7, 18, 0});
  // GAMEPLAY INFORMATION DISPLAY
  DrawRectangleGradientV(0, 0, GetScreenWidth(), TOP_PADDING, Color{17, 24, 39, 255}, BLACK);
  const char *scoreText = TextFormat("Score: %i", score);
  const char *levelText = TextFormat("Level: %i", level);
  const int fontSize    = 20;
  DrawText(scoreText, GetScreenWidth() / 2 - MeasureText(scoreText, fontSize) / 2 - 10, 10, fontSize, GRAY);
  DrawText(levelText, 0, 10, fontSize, GRAY);
  for (int i = 0; i < lives; i++) {
    DrawTexture(heartTexture, GetScreenWidth() - 30 - 30 * i, 10, WHITE);
  }
  // END OF GAMEPLAY INFORMATION DISPLAY

  if (gameState != PLAYING && gameState != LIVE_LOST) {
    DrawCenteredText("Press R to restart", 20, LIGHTGRAY);
    DrawCenteredText("Press ESC to exit", 20, LIGHTGRAY, 20);
  }

  bricks.Draw();
  ball.Draw();
  bat.Draw();

  switch (gameState) {
  case PLAYING:
    DrawCenteredText("Press SPACE to pause ", 20, GRAY, 40);
    break;
  case PAUSED:
    DisplayPauseMenu();
    break;
  case GAME_OVER:
    DrawCenteredText("Game Over", 60, RED, -60);
    break;
  case GAME_WON:
    DrawCenteredText("You Won", 60, GREEN, -60);
    break;
  case LEVEL_COMPLETE:
    DrawCenteredText("Level Complete", 50, GREEN, -50);
    break;
  case LIVE_LOST:
    DrawCenteredText("Life Lost", 50, RED, -50);
    DrawCenteredText("Press ENTER to continue", 20, GRAY, 20);
    break;
  }
}

void Game::HandleKeyboardInput() {
  if (IsKeyPressed(KEY_R)) {
    ResetGame();
    gameState = PLAYING;
  }
  if (IsKeyPressed(KEY_SPACE)) {
    if (gameState == PLAYING) {
      gameState = PAUSED;
    } else if (gameState == PAUSED) {
      gameState = PLAYING;
    }
  }
  if (IsKeyPressed(KEY_F11)) {
    int monitor = GetCurrentMonitor();
    SetWindowSize(GetMonitorWidth(monitor), GetMonitorHeight(monitor));
    isFullScreen = true;
  }
}

void Game::LoopLogic() {
  HandleKeyboardInput();
  UpdateGame();
  BeginDrawing();
  DrawGame();
  EndDrawing();
  if (isFullScreen) {
    ToggleFullscreen();
    isFullScreen = false;
    RedrawBricks();
    ball.SetDefaultSpeed(ball.GetDefaultSpeed() * 1.25f);
  }
}

void Game::DisplayPauseMenu() {
  EndDrawing();

  Rectangle pauseMenuRect = {(float)GetScreenWidth() / 2 - 250, (float)GetScreenHeight() / 2 - 250, 500, 500};
  int selectedOption      = 0;
  Sound navigateSound     = LoadSound("assets/Sounds/wallHit.wav");
  Sound selectSound       = LoadSound("assets/Sounds/brickBreak.wav");

  defer({
    UnloadSound(navigateSound);
    UnloadSound(selectSound);
    printf("INFO: DEFER: Sounds unloaded successfully\n");
    BeginDrawing();
  });

  while (!WindowShouldClose() && gameState == PAUSED) {
    if (IsKeyPressed(KEY_DOWN)) {
      selectedOption++;
      PlaySound(navigateSound);
      if (selectedOption > 4)
        selectedOption = 0;
    }
    if (IsKeyPressed(KEY_UP)) {
      selectedOption--;
      PlaySound(navigateSound);
      if (selectedOption < 0)
        selectedOption = 4;
    }
    if (IsKeyPressed(KEY_ENTER)) {
      PlaySound(selectSound);
      switch (selectedOption) {
      case 0:
        gameState = PLAYING;
        return;
      case 1:
        gameState = PLAYING;
        ResetGame();
        return;
      case 2:
        gameState = PLAYING;
        ResetGame();
        LoadGameProgress();
        return;
      case 3:
        SaveGameProgress();
        break;
      case 4:
        gameSaveEvent = EXIT_EVENT;
        return;
      }
    }
    BeginDrawing();
    DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), Color{0, 0, 0, 100});
    DrawRectangleGradientEx(pauseMenuRect, Color{17, 24, 39, 255}, BLACK, Color{17, 24, 39, 255}, BLACK);
    DrawCenteredText("Resume", 30, selectedOption == 0 ? RED : WHITE, -100);
    DrawCenteredText("Restart", 30, selectedOption == 1 ? RED : WHITE, -50);
    DrawCenteredText("Load Game", 30, selectedOption == 2 ? RED : WHITE);
    DrawCenteredText("Save Game", 30, selectedOption == 3 ? RED : WHITE, 50);
    DrawCenteredText("Exit", 30, selectedOption == 4 ? RED : WHITE, 100);
    DrawCenteredText("HOTKEYS: [Esc - Exit] [SPACE - Pause/Resume]", 20, GRAY, 150);
    DrawCenteredText("[R - Restart] [L - Load Game] [S - Save Game]", 20, GRAY, 175);
    EndDrawing();
    if (IsKeyPressed(KEY_R)) {
      PlaySound(selectSound);
      gameState = PLAYING;
      ResetGame();
      return;
    }
    if (IsKeyPressed(KEY_L)) {
      PlaySound(selectSound);
      gameState = PLAYING;
      ResetGame();
      LoadGameProgress();
      return;
    }
    if (IsKeyPressed(KEY_S)) {
      PlaySound(selectSound);
      SaveGameProgress();
    }
    if (IsKeyPressed(KEY_ESCAPE)) {
      PlaySound(selectSound);
      gameSaveEvent = EXIT_EVENT;
      return;
    }
    if (IsKeyPressed(KEY_SPACE)) {
      PlaySound(selectSound);
      gameState = PLAYING;
      return;
    }
  }
}

void Game::DrawCenteredText(const char *text, int fontSize, Color color, int paddingY) {
  float screenWidth  = GetScreenWidth();
  float screenHeight = GetScreenHeight();
  float textWidth    = MeasureText(text, fontSize);
  float textHeight   = fontSize;
  float posX         = screenWidth / 2 - textWidth / 2;
  float posY         = screenHeight / 2 - textHeight / 2 + paddingY;
  DrawText(text, static_cast<int>(posX), static_cast<int>(posY), fontSize, color);
}

void Game::RedrawBricks() {
  ball = Ball();
  bat  = Bat();
  bricks.RenderForCurrWindow();
}

void Game::SaveGameProgress() {
  if (std::filesystem::exists("data")) {
    std::filesystem::path saveDataPath    = "data/savedata.txt";
    std::filesystem::path oldSaveDataPath = "data/savedata_old.txt";
    if (std::filesystem::exists(saveDataPath)) {
      std::filesystem::remove(oldSaveDataPath);
      std::filesystem::rename(saveDataPath, "data/savedata_old.txt");
    }
    std::ofstream saveDataFile(saveDataPath);
    saveDataFile << score << std::endl;
    saveDataFile << lives << std::endl;
    saveDataFile << level << std::endl;
    saveDataFile << PowerUpTypeToString(powerUpType) << std::endl;
    saveDataFile << PowerUpStateToString(powerUpState) << std::endl;
    saveDataFile << "Destroyed Brick Cordinate : " << std::endl;
    for (int i = 0; i < hBricksCount; i++) {
      for (int j = 0; j < vBricksCount; j++) {
        if (bricks.IsBrickDestroyed(i, j)) {
          saveDataFile << i << " " << j << std::endl;
        }
      }
    }
    saveDataFile.close();
  } else {
    std::filesystem::create_directory("data");
    SaveGameProgress();
  }
}

void Game::LoadGameProgress() {
  if (std::filesystem::exists("data/savedata.txt")) {
    std::ifstream saveDataFile("data/savedata.txt");
    std::string pUpType = "", pUpState = "";
    saveDataFile >> score;
    saveDataFile >> lives;
    saveDataFile >> level;
    saveDataFile >> pUpType;
    saveDataFile >> pUpState;
    powerUpType  = StringToPowerUpType(pUpType);
    powerUpState = StringToPowerUpState(pUpState);
    std::string line;
    // ignore the next line
    std::getline(saveDataFile, line);
    while (std::getline(saveDataFile, line)) {
      while (std::getline(saveDataFile, line)) {
        int x, y;
        std::istringstream iss(line);
        iss >> x >> y;
        bricks.SetBrickDestroyed(x, y);
      }
    }
    saveDataFile.close();
  }
}

bool Game::IsGameEvent(GameEvents gameEvent) {
  return gameSaveEvent == gameEvent;
}