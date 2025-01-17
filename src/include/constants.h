#pragma once

#include "raylib.h"
#include <cstddef>

constexpr int FRAME_RATE         = 60;
constexpr float INIT_SWIDTH      = 1200.0f;
constexpr float INIT_SHEIGHT     = 900.0f;
constexpr int BRICK_WIDTH        = 100;
constexpr int BRICK_HEIGHT       = 30;
constexpr int BALL_RADIUS        = 15;
constexpr int BRICK_PADDING      = 2 * BALL_RADIUS + 5;
constexpr int BALL_START_SPEED_X = 10;
constexpr int BALL_START_SPEED_Y = 10;
constexpr int BAT_SPEED          = 10;
constexpr float BAT_WIDTH        = 200.0f;
constexpr float BAT_HEIGHT       = 20.0f;
constexpr int SPEEDUP            = 2;
constexpr int BORDER_THICKNESS   = 10;
constexpr int TOP_PADDING        = 50;

inline float GetScreenWidthFloat() {
  return static_cast<float>(GetScreenWidth());
}
inline float GetScreenHeightFloat() {
  return static_cast<float>(GetScreenHeight());
}

enum GameState {
  PLAYING,
  PAUSED,
  GAME_OVER,
  GAME_WON,
  LEVEL_COMPLETE,
  LIVE_LOST,
};

enum GameEvents {
  SAVE_EVENT,
  LOAD_EVENT,
  EXIT_EVENT,
  NULL_EVENT,
};

enum BrickType {
  NORMAL,
  TOUGH,
  UNBREAKABLE,
};
enum PowerUpType {
  SPEED_UP,
  SPEED_DOWN,
  SIZE_UP,
  SIZE_DOWN,
  MULTI_BALL,
  NONE,
};
enum PowerUpState {
  ACTIVE,
  INACTIVE,
};
enum PowerUpDuration {
  SHORT = 50,
  LONG  = 100,
};
