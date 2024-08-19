#include "ObjectManager.hpp"
#include "box2d/box2d.h"
#include <SFML/Graphics/RenderWindow.hpp>

ObjectManager::ObjectManager(sf::RenderWindow *window) {
  this->window = window;
}

ObjectManager::~ObjectManager() {
  for (GameObject *obj : gameObjects) {
    delete obj;
  }
}

void ObjectManager::update_obj(GameObject *obj) {
  b2Vec2 pos = b2Body_GetPosition(obj->bodyId);
  obj->xpos = pos.x;
  obj->ypos = pos.y;
  b2Rot rot = b2Body_GetRotation(obj->bodyId);
  obj->rot_deg = rad_to_deg(b2Rot_GetAngle(rot));
  obj->sfShape->setPosition(
      sf::Vector2f(obj->xpos * X_SCALE, obj->ypos * Y_SCALE));
  obj->sfShape->setRotation(obj->rot_deg);
}

void ObjectManager::updateObjects() {
  for (GameObject *obj : gameObjects) {
    this->update_obj(obj);
  }
}

void ObjectManager::renderObjects() {
  for (GameObject *obj : gameObjects) {
    window->draw(*obj->sfShape);
  }
}

void ObjectManager::addObject(GameObject *object) {
  this->gameObjects.push_back(object);
  update_obj(object);
}
