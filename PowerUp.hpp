#pragma once
#include "Diamond.hpp"

#define POWERUP_TEXTURE U"sozai/others/powerup.png"
#define POWERUP_HEIGHT 32
#define POWERUP_WIDTH 32

class PowerUp : public Diamond
{
public:
	PowerUp(Vec2 pos, float speed);
	String GetTypeName() override;
};
