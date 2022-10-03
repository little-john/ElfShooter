#include "stdafx.h"
#include "PowerUp.hpp"
#include "AnimData.hpp"
#include "CharaAnim.hpp"

PowerUp::PowerUp(Vec2 pos, float speed) : Diamond(pos, speed)
{
	bounds = Rect(pos.x, pos.y, POWERUP_WIDTH, POWERUP_HEIGHT);

	Array<AnimData> animations;
	animations << AnimData(POWERUP_TEXTURE, 1, true);
	anim = new CharaAnim(animations, nullptr);
}

String PowerUp::GetTypeName()
{
	return U"POWERUP";
}
