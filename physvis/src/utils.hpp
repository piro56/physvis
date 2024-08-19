#pragma once
#include <math.h>

static constexpr float rad_to_deg(float rad) { return rad * 180.0f / M_PI; };
static constexpr float deg_to_rad(float deg) { return deg * M_PI / 180.0f; };
