// Copyright 2024
#pragma once
#include <vector>

#include "MyShape.hpp"
#include "box2d/box2d.h"

class PhysCalc {
private:
  static const b2Vec2 GRAVITY;
  static const uint VELOCITY_ITER = 8;
  static const uint POS_ITER = 3;

  b2World world;

  void initGroundBody();
  void initDynamicBody();

public:
  b2Body *groundBody;
  b2Body *dynamicBody;
  std::vector<MyShape *> bodies;

  static const constexpr float TIMESTEP = 1.0f / 60.0f;
  PhysCalc();
  ~PhysCalc();
  void init();
  void step();
};
