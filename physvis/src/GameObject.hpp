#pragma once
#include <SFML/Graphics/RectangleShape.hpp>
#include <box2d/box2d.h>
constexpr float HALF_PI = M_PI / 2.0f;

#include "utils.hpp"
struct GameObject {
public:
private:
  b2Polygon b2Shape;
  b2ShapeDef shapeDef;
  b2BodyDef bodyDef;

public:
  b2BodyId bodyId;
  float width;
  float height;
  float xpos;
  float ypos;
  float rot_deg;

  sf::Shape *sfShape;

  GameObject(b2WorldId worldId, float width, float height, float xpos,
             float ypos, bool dynamic = true, float density = 0.3f,
             float friction = 0.3f, float rotation_radians = 0.0f);
  static GameObject *SimpleDynamic(b2WorldId world, float width, float height,
                                   float xpos, float ypos, float rot = HALF_PI);
  void attachShape(sf::Shape *shape);
};
