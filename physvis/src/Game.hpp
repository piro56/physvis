// Copyright 2024
#pragma once

// #include "box2d/box2d.h"
#include "./PhysCalc.hpp"
#include "box2d/box2d.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

class Game {
private:
  sf::RenderWindow window;
  sf::CircleShape circle;

  sf::RectangleShape dynBody;
  sf::RectangleShape groundBody;

  PhysCalc *physics;

  void initShapes();

public:
  Game();
  ~Game();

  void init();

  void run();

  void drawShapes();
  void drawSimpleShapes();
};
