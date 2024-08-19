#pragma once

#include "GameObject.hpp"
#include "ObjectManager.hpp"
#include "PhysCalc.hpp"
#include "Renderer.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class Game {
private:
  sf::RenderWindow *window;
  Renderer *renderer;
  PhysCalc *physics;
  ObjectManager *objManager;

public:
  Game();
  ~Game();
  void init();
  void run();
};
