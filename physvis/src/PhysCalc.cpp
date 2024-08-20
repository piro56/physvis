#include "PhysCalc.hpp"
#include "box2d/types.h"

PhysCalc::PhysCalc() {}

PhysCalc::~PhysCalc() {}

void PhysCalc::init() {
  worldDef = b2DefaultWorldDef();
  worldDef.gravity = (b2Vec2){0.2f, GRAVITY};
  worldId = b2CreateWorld(&worldDef);
}

void PhysCalc::step() { b2World_Step(worldId, TIMESTEP, SUBSTEP_COUNT); }
