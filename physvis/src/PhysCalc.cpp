// Copyright 2024
#include "PhysCalc.hpp"
#include "MyShape.hpp"

const b2Vec2 PhysCalc::GRAVITY = b2Vec2{0.0f, -10.0f};

PhysCalc::PhysCalc() : world(GRAVITY), bodies() {}

PhysCalc::~PhysCalc() {
  for (MyShape *ms : bodies) {
    delete ms;
  }
}

void PhysCalc::initGroundBody(float width, float height) {
  b2BodyDef groundBodyDef;
  groundBodyDef.position.Set(0.0f, -10.0f);
  groundBody = world.CreateBody(&groundBodyDef);

  b2PolygonShape groundBox;
  groundBox.SetAsBox(width, height);
  groundBody->CreateFixture(&groundBox, 0.0f);

  MyShape *ms = new MyShape();
  ms->shape = new sf::RectangleShape(sf::Vector2f(width, height));
  ms->body = groundBody;
  ms->width = width;
  ms->height = height;
}

void PhysCalc::initDynamicBody(float width, float height) {
  // Create body (set position) and attach to world
  b2BodyDef dynamicBodyDef;
  dynamicBodyDef.type = b2_dynamicBody;
  dynamicBodyDef.position.Set(0.0f, 4.0f);
  dynamicBody = this->world.CreateBody(&dynamicBodyDef);

  // Shape definition (size)
  b2PolygonShape dynamicBox;
  dynamicBox.SetAsBox(width, height);

  // Fixture Definition
  b2FixtureDef fixtureDef;
  fixtureDef.shape = &dynamicBox;
  fixtureDef.density = 1.0f;
  fixtureDef.friction = 0.3f;
  dynamicBody->CreateFixture(&fixtureDef);
}

void PhysCalc::init() {
  this->initDynamicBody();
  this->initGroundBody();
}

void PhysCalc::step() { world.Step(TIMESTEP, VELOCITY_ITER, POS_ITER); }
