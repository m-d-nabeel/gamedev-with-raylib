#pragma once

#include "../include/constants.h"
#include <functional>
#include <stdexcept>

// Convert PowerUpType to string
inline std::string PowerUpTypeToString(PowerUpType type) {
  switch (type) {
  case NONE:
    return "NONE";
  case SPEED_UP:
    return "SPEED_UP";
  case SPEED_DOWN:
    return "SPEED_DOWN";
  case SIZE_UP:
    return "SIZE_UP";
  case SIZE_DOWN:
    return "SIZE_DOWN";
  case MULTI_BALL:
    return "MULTI_BALL";
  }
}

// Convert string to PowerUpType
inline PowerUpType StringToPowerUpType(const std::string &str) {
  if (str == "NONE")
    return PowerUpType::NONE;
  if (str == "SPEED_UP")
    return PowerUpType::SPEED_UP;
  if (str == "SPEED_DOWN")
    return PowerUpType::SPEED_DOWN;
  if (str == "SIZE_UP")
    return PowerUpType::SIZE_UP;
  if (str == "SIZE_DOWN")
    return PowerUpType::SIZE_DOWN;
  if (str == "MULTI_BALL")
    return PowerUpType::MULTI_BALL;
  throw std::invalid_argument("Unknown PowerUpType string");
}

// Similarly for PowerUpState
inline std::string PowerUpStateToString(PowerUpState state) {
  switch (state) {
  case PowerUpState::INACTIVE:
    return "INACTIVE";
  case PowerUpState::ACTIVE:
    return "ACTIVE";
  default:
    throw std::invalid_argument("Unknown PowerUpState");
  }
}

inline PowerUpState StringToPowerUpState(const std::string &str) {
  if (str == "INACTIVE")
    return PowerUpState::INACTIVE;
  if (str == "ACTIVE")
    return PowerUpState::ACTIVE;
  throw std::invalid_argument("Unknown PowerUpState string");
}

// Defer implementation in C++ similar to Go language
// https://www.gingerbill.org/article/2015/08/19/defer-in-cpp/
template <typename F> struct privDefer {
  F f;
  privDefer(F f) : f(f) {
  }
  ~privDefer() {
    f();
  }
};

template <typename F> privDefer<F> defer_func(F f) {
  return privDefer<F>(f);
}

#define DEFER_1(x, y) x##y
#define DEFER_2(x, y) DEFER_1(x, y)
#define DEFER_3(x) DEFER_2(x, __COUNTER__)
#define defer(code) auto DEFER_3(_defer_) = defer_func([&]() { code; })
