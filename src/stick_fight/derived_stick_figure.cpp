#pragma once

#include "../../include/stick_fight/derived_stick_figure.h"
#include <filesystem>
#include <iostream>
#include <raylib.h>

// -------------------------SWORD STICK FIGURE-------------------------
SwordStickFigure::SwordStickFigure() {
  std::filesystem::path path = "assets/StickFigure/Sword sprites";
  LoadTextures(path);
  figType = SWORD;
  if (stickFigures.empty()) {
    std::cerr << "Error: No textures loaded for SwordStickFigure." << std::endl;
  }
};

// -------------------------FIGHTER STICK FIGURE-------------------------
FighterStickFigure::FighterStickFigure() {
  std::filesystem::path path = "assets/StickFigure/Fighter sprites";
  LoadTextures(path);
  figType = FIGHTER;
  if (stickFigures.empty()) {
    std::cerr << "Error: No textures loaded for FighterStickFigure." << std::endl;
  }
};

// -------------------------PISTOL STICK FIGURE-------------------------
PistolStickFigure::PistolStickFigure() {
  std::filesystem::path path = "assets/StickFigure/Pistol sprites";
  LoadTextures(path);
  figType = PISTOL;
  if (stickFigures.empty()) {
    std::cerr << "Error: No textures loaded for PistolStickFigure." << std::endl;
  }
};
