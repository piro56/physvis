#pragma once

#include <SFML/Graphics/RenderWindow.hpp>

class Renderer {
private:
  sf::RenderWindow *window;

public:
  Renderer(sf::RenderWindow *window);
  ~Renderer();

  void init();
};
