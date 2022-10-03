#include "Diamond.hpp"
#include "AnimData.hpp"
#include "CharaAnim.hpp"

Diamond::Diamond(Vec2 sPos, float mSpeed)
{
	pos = sPos;
	speed = mSpeed * Scene::DeltaTime();

	// 画像が小さいので４倍拡大させる
	const int scaleUpOffset = 4;
	bounds = Rect(pos.x, pos.y, DIA_WIDTH * scaleUpOffset, DIA_HEIGHT * scaleUpOffset);

	Array<AnimData> animations;
	animations << AnimData(DIAMOND_TEXTURE, 4, true);
	anim = new CharaAnim(animations, nullptr);
}

Diamond::~Diamond()
{
	delete anim;
}

Rect* Diamond::GetBounds()
{
	return &bounds;
}

void Diamond::Update()
{
	pos.y += speed;
	bounds.setPos(pos.x, pos.y);
	anim->Update();
}

void Diamond::Draw() const
{
	bounds(anim->GetCurrentAnim()).draw();
}

bool Diamond::IsOutOfScreen()
{
	return pos.y + bounds.size.y > Scene::Height();
}

String Diamond::GetTypeName()
{
	return U"GEM";
}
