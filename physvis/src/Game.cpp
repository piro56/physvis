#include "Game.hpp"
#include "ObjectManager.hpp"
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
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
  renderer = new Renderer(window);
  physics = new PhysCalc();
  objManager = new ObjectManager(window);

  renderer->init();
  physics->init();
}

void Game::run() {

  GameObject *groundBody =
      new GameObject(physics->worldId, 50, 10, 1.0f, 1.0f, false);
  groundBody->attachShape(new sf::RectangleShape(sf::Vector2f(50, 10)));
  GameObject *dynamicBody = new GameObject(physics->worldId, 10, 5, 2, 100,
                                           true, 0.0f, 0.0f, M_PI / 2);
  dynamicBody->attachShape(new sf::RectangleShape(sf::Vector2f(10, 5)));
  dynamicBody->sfShape->setFillColor(sf::Color::Red);

  objManager->addObject(groundBody);
  objManager->addObject(dynamicBody);

  while (window->isOpen()) {
    sf::Event event;
    while (window->pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window->close();
      }
    }
    window->clear(sf::Color::Transparent);
    objManager->debugPrint();
    physics->step();
    objManager->updateObjects();
    objManager->renderObjects();
    window->display();
    sleep(1);
  }
}
