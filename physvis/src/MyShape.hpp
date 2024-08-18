#pragma once
#include "box2d/box2d.h"
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Shape.hpp>
struct MyShape {
  b2Body *body;
  sf::RectangleShape *shape;
  float width;
  float height;
};
