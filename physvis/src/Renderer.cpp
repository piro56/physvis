#include "Renderer.hpp"

Renderer::Renderer(sf::RenderWindow *window, PhysCalc *physics, float xscale,
                   float yscale) {
  this->window = window;
  this->physics = physics;
  this->X_SCALE = xscale;
  this->Y_SCALE = yscale;
}

void Renderer::render() {
  for (MyShape *shape : physics->bodies) {
    if (shape->shape == nullptr) {
      continue;
    }
    window->draw(*shape->shape);
  }
}
