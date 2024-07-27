#include "../include/stick_fight/derived_stick_figure.h"
#include <filesystem>
#include <iostream>
#include <raylib.h>

// -------------------------SWORD STICK FIGURE-------------------------
SwordStickFigure::SwordStickFigure() {
  std::filesystem::path path = "src/resources/StickFigure/Sword sprites";
  LoadTextures(path, "Idle");
  if (stickFigures.empty()) {
    std::cerr << "Error: No textures loaded for SwordStickFigure." << std::endl;
  }
};

// -------------------------FIGHTER STICK FIGURE-------------------------
FighterStickFigure::FighterStickFigure() {
  std::filesystem::path path = "src/resources/StickFigure/Fighter sprites";
  LoadTextures(path, "Idle");
  if (stickFigures.empty()) {
    std::cerr << "Error: No textures loaded for FighterStickFigure." << std::endl;
  }
};

// -------------------------PISTOL STICK FIGURE-------------------------
PistolStickFigure::PistolStickFigure() {
  std::filesystem::path path = "src/resources/StickFigure/Pistol sprites";
  LoadTextures(path, "Idle");
  if (stickFigures.empty()) {
    std::cerr << "Error: No textures loaded for PistolStickFigure." << std::endl;
  }
};
