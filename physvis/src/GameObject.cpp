#include "GameObject.hpp"

GameObject::GameObject(b2WorldId worldId, float width, float height, float xpos,
                       float ypos, bool dynamic, float density, float friction,
                       float rotation_radians) {
  bodyDef = b2DefaultBodyDef();
  if (dynamic) {
    bodyDef.type = b2_dynamicBody;
  }
  bodyDef.position = (b2Vec2){xpos, ypos};
  bodyId = b2CreateBody(worldId, &bodyDef);
  b2Shape = b2MakeBox(height, width);
  shapeDef = b2DefaultShapeDef();
  if (dynamic) {
    shapeDef.density = density;
    shapeDef.friction = friction;
    shapeDef.restitution = 1.0f;
  }
  b2CreatePolygonShape(bodyId, &shapeDef, &b2Shape);

  this->width = width;
  this->height = height;
  this->xpos = xpos;
  this->ypos = ypos;
  this->rot_deg = rad_to_deg(rotation_radians);
}

void GameObject::attachShape(sf::Shape *shape) {
  this->sfShape = shape;
  shape->setPosition(sf::Vector2f(this->xpos, this->ypos));
}
