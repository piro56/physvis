#pragma once

#include <iostream>
#include <vector>

#include "box2d/box2d.h"
#include <SFML/Graphics/RenderWindow.hpp>

#include "GameObject.hpp"
#include "PhysCalc.hpp"

/**
 * Holds main gameObjects data that will be shared
 * For example, PhysCalc and Renderer will both use gameObjects to render.
 */
class ObjectManager {
private:
  std::vector<GameObject *> gameObjects;
  sf::RenderWindow *window;

  void update_obj(GameObject *obj);

public:
  const float X_SCALE = 1;
  const float Y_SCALE = 1;

  ObjectManager(sf::RenderWindow *window);
  ~ObjectManager();

  void updateObjects();
  void renderObjects();
  void addObject(GameObject *object);

  void debugPrint();
};
