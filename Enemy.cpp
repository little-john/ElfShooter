#include "Enemy.hpp"
#include "AnimData.hpp"
#include "CharaAnim.hpp"

Enemy::Enemy(Vec2 sPos, float mSpeed)
{
	pos = sPos;
	isDead = false;
	state = State::Normal;
	speed = mSpeed * Scene::DeltaTime();

	float sizeOffset = Random(1.0f, 1.5f);
	bounds = Rect(pos.x, pos.y, EnemySize * sizeOffset, EnemySize * sizeOffset);

	Array<AnimData> animations;

	float enemyRate = Random();

	if (enemyRate > 0.7f) // 3割で敵１
		animations << AnimData(ENEMY1, 4, true);
	else if (enemyRate > 0.3f) // 3割で敵２
		animations << AnimData(ENEMY2, 4, true);
	else // 3割で敵3
		animations << AnimData(ENEMY3, 4, true);

	animations << AnimData(ENEMY_DEAD, 6, false);

	anim = new CharaAnim(animations, this);
}

void Enemy::NoArgCallback()
{
	OnDead();
}

Rect* Enemy::GetBounds()
{
	return &bounds;
}

void Enemy::Update()
{
	pos.y += speed;
	bounds.setPos(pos.x, pos.y);
	anim->Update();
}

void Enemy::Draw() const
{
	Rect shadow = bounds;
	shadow.moveBy(0, -(EnemySize / 2));

	shadow(anim->GetCurrentAnim()).draw(Palette::Black);
	bounds(anim->GetCurrentAnim()).draw();
}

bool Enemy::IsOutOfScreen()
{
	return pos.y + (CharaSize / 2) > Scene::Height();
}

bool Enemy::IsHit(Rect target)
{
	return bounds.intersects(target);
}

void Enemy::Damage()
{
	const int DAMAGE = 1;

	speed = 0;
	state = State::Hit;
	anim->ChangeAnim(DAMAGE);
}

bool Enemy::IsDead()
{
	return isDead;
}

void Enemy::OnDead()
{
	isDead = true;
}

Enemy::~Enemy()
{
	delete anim;
}

Enemy::State Enemy::GetState()
{
	return state;
}

Vec2 Enemy::GetPos()
{
	return pos;
}
