#include "Arrow.hpp"

Arrow::Arrow(Vec2 sPos, float mSpeed)
{
	pos = sPos;
	speed = mSpeed;
	arrow = Texture(ARROW_TEXTURE);
	bounds = Rect(pos.x, pos.y, ArrowSize, ArrowSize);
}

void Arrow::Update()
{
	pos.y -= speed * Scene::DeltaTime();
	bounds.setPos(pos.x, pos.y);
}

bool Arrow::IsOutOfScreen()
{
	return (pos.y + CharaSize) < 0;
}

void Arrow::Draw() const
{
	Rect shadow = bounds;
	shadow.moveBy(0, -(ArrowSize / 2));

	shadow(arrow).draw(Palette::Black);
	bounds(arrow).draw();
}

Rect* Arrow::GetBounds()
{
	return &bounds;
}

bool Arrow::IsHitEnemy(Rect& enemy)
{
	return bounds.intersects(enemy);
}
