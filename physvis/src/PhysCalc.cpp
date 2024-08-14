// Copyright 2024
#include "PhysCalc.hpp"

const b2Vec2 PhysCalc::GRAVITY = b2Vec2{0.0f, -10.0f};

PhysCalc::PhysCalc() : world(GRAVITY) {}

void PhysCalc::initGroundBody() {
  b2BodyDef groundBodyDef;
  groundBodyDef.position.Set(0.0f, -10.0f);
  groundBody = world.CreateBody(&groundBodyDef);

  b2PolygonShape groundBox;
  groundBox.SetAsBox(50.0f, 10.0f);
  groundBody->CreateFixture(&groundBox, 0.0f);
}

void PhysCalc::initDynamicBody() {
  // Create body (set position) and attach to world
  b2BodyDef dynamicBodyDef;
  dynamicBodyDef.type = b2_dynamicBody;
  dynamicBodyDef.position.Set(0.0f, 4.0f);
  dynamicBody = this->world.CreateBody(&dynamicBodyDef);

  // Shape definition (size)
  b2PolygonShape dynamicBox;
  dynamicBox.SetAsBox(1.0f, 1.0f);

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
