// Copyright 2024
#include "Game.hpp"
#include "Renderer.hpp"
#include "imgui-SFML.h"

#include <cassert>

#include <SFML/Graphics/RectangleShape.hpp>

// CONSTRUCTOR DESTRUCTOR
Game::Game() : window(sf::VideoMode(200, 200), "Window") {}

Game::~Game() { delete this->physics; }
// END CONSTRUCTOR

// INIT
void Game::initShapes() {
  circle = sf::CircleShape(100.f);
  circle.setFillColor(sf::Color::Red);

  dynBody = sf::RectangleShape(sf::Vector2f(10.f, 10.f));
  groundBody = sf::RectangleShape(sf::Vector2f(10.f, 10.f));

  renderer = new Renderer(&window, physics);
}

void Game::init() {
  this->physics = new PhysCalc();
  this->physics->init();
  this->initShapes();

  // IMGUI Init
  window.setFramerateLimit(60);
  ImGui::SFML::Init(this->window);
}
// END INIT

// DRAW

void Game::drawShapes() { this->drawSimpleShapes(); }

void Game::drawSimpleShapes() {
  assert(physics != nullptr);

  const b2Vec2 dynPos = physics->dynamicBody->GetPosition();
  const float dynAngleRad = physics->dynamicBody->GetAngle();
  const b2Vec2 staticPos = physics->groundBody->GetPosition();
  const float staticAngleRad = physics->groundBody->GetAngle();

  dynBody.setPosition(sf::Vector2f(dynPos.x, dynPos.y));
  groundBody.setPosition(sf::Vector2f(staticPos.x, staticPos.y));

  renderer->render();
}

// END DRAW

void Game::run() {
  sf::Clock deltaClock;
  while (this->window.isOpen()) {
    sf::Event event;

    while (window.pollEvent(event)) {
      ImGui::SFML::ProcessEvent(window, event);
      if (event.type == sf::Event::Closed) {
        window.close();
      }
    }
    ImGui::SFML::Update(window, deltaClock.restart());
    ImGui::ShowDemoWindow();

    window.clear();
    drawSimpleShapes();
    ImGui::SFML::Render(window);
    window.display();
  }
}
