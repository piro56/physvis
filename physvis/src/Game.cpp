#include "Game.hpp"
#include "ObjectManager.hpp"
#include "box2d/box2d.h"
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Sleep.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <cmath>
#include <unistd.h>

Game::Game() { window = nullptr; }
Game::~Game() {
  delete window;
  delete renderer;
  delete physics;
}

void Game::init() {
  window = new sf::RenderWindow(sf::VideoMode(800, 600), "Hello World");
  physics = new PhysCalc();
  renderer = new Renderer(window);
  objManager = new ObjectManager(window);

  physics->init();
  renderer->init();
}

void Game::run() {

  GameObject *groundBody =
      new GameObject(physics->worldId, 1000, 10, 10.0f, 10.0f, false);
  groundBody->attachShape(new sf::RectangleShape(sf::Vector2f(1000, 10)));
  GameObject *dynObj =
      GameObject::SimpleDynamic(physics->worldId, 10, 10, 5, 50);

  objManager->addObject(groundBody);
  objManager->addObject(dynObj);

  while (window->isOpen()) {
    sf::Event event;
    while (window->pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window->close();
      }
      if (event.type == sf::Event::KeyPressed) {
        std::cout << "Press.\n";
        b2Body_ApplyForce(dynObj->bodyId, (b2Vec2){101, 10000.0},
                          (b2Vec2){dynObj->xpos, dynObj->ypos + 1}, true);
      }
    }
    window->clear(sf::Color::Black);
    objManager->debugPrint();
    physics->step();

    objManager->updateObjects();
    objManager->renderObjects();
    window->display();
    sf::sleep(sf::Time(sf::milliseconds(10)));
  }
}
