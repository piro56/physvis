// Copyright 2024
#pragma once

#include "PhysCalc.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class Renderer {
private:
  float X_SCALE;
  float Y_SCALE;

public:
  Renderer(sf::RenderWindow *window, PhysCalc *physics, float X_SCALE = 100,
           float Y_SCALE = 100);
  sf::RenderWindow *window;
  PhysCalc *physics;
};
