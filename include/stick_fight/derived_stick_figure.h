#pragma once

#include "base_stick_figure.h"
#include <vector>
#include <raylib.h>

class SwordStickFigure : public StickFigure {
public:
  SwordStickFigure();
  ~SwordStickFigure() = default;
};

class FighterStickFigure : public StickFigure {
public:
  FighterStickFigure();
  ~FighterStickFigure() = default;
};

class PistolStickFigure : public StickFigure {
public:
  PistolStickFigure();
  ~PistolStickFigure() = default;
};
