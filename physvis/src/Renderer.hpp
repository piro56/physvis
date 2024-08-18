// Copyright 2024
#pragma once

#include "PhysCalc.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
class Renderer {
private:
  float X_SCALE;
  float Y_SCALE;

  PhysCalc *physics;
  sf::RenderWindow *window;

public:
  Renderer(sf::RenderWindow *window, PhysCalc *physics, float X_SCALE = 100,
           float Y_SCALE = 100);

  void render();
};
