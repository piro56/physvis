#include "ObjectManager.hpp"

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
  float ydiff = window->getSize().y - obj->ypos - obj->height;
  obj->sfShape->setPosition(sf::Vector2f(obj->xpos * X_SCALE, ydiff * Y_SCALE));
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

void ObjectManager::debugPrint() {
  for (GameObject *obj : gameObjects) {
    std::cout << "\t" << obj->bodyId.index1 << "b2[" << obj->xpos << ", "
              << obj->ypos << ", r" << obj->rot_deg << "]\n";
  }
}
