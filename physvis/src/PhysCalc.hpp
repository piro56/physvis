#pragma once
#include <box2d/box2d.h>

class PhysCalc {
  const float GRAVITY = -10.0f;
  const float TIMESTEP = 0.1f;
  const float SUBSTEP_COUNT = 4;
  b2WorldDef worldDef;

public:
  PhysCalc();
  ~PhysCalc();

  b2WorldId worldId;
  void init();
  void step();
};
