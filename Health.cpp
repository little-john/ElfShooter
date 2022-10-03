#include "stdafx.h"
#include "Health.hpp"
#include "AnimData.hpp"
#include "CharaAnim.hpp"

Health::Health(Vec2 pos, float speed) : Diamond(pos, speed)
{
	// 画像が小さいので2倍拡大させる
	const int scaleUpOffset = 2;
	bounds = Rect(pos.x, pos.y, HEALTH_WIDTH * scaleUpOffset, HEALTH_HEIGHT * scaleUpOffset);

	Array<AnimData> animations;
	animations << AnimData(HEALTH_TEXTURE, 1, true);
	anim = new CharaAnim(animations, nullptr);
}

String Health::GetTypeName()
{
	return U"HEALTH";
}
