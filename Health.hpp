#pragma once
#include "Diamond.hpp"

#define HEALTH_TEXTURE U"sozai/others/health.png"
#define HEALTH_HEIGHT 16
#define HEALTH_WIDTH 16

class Health : public Diamond
{
public:
	Health(Vec2 pos, float speed);
	String GetTypeName() override;
};

