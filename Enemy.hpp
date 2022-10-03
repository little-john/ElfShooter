#pragma once
#include "Common.h"

#define ENEMY1 U"sozai/enemy_1/walk.png"
#define ENEMY2 U"sozai/enemy_2/walk.png"
#define ENEMY3 U"sozai/enemy_3/walk.png"
#define ENEMY_DEAD U"sozai/others/death.png"

/*
* Enemy　敵のクラス
* 移動、描画、当たり判定領域を持ち
* 画面外に出たかどうかやキャラと接触したかの処理もある
* キャラとの違いとして、ダメージ受けたら、爆発エフェクトを再生し、
* エフェクトが描画終わってから削除されます
*/
class Enemy : public Callbacker
{
public:
	// 状態
	enum State
	{
		Normal,
		Hit
	};

private:
	// 位置座標
	Vec2 pos;
	// 移動速度
	float speed;
	// 当たり判定領域
	Rect bounds;
	// アニメーションへの参照
	class CharaAnim* anim;
	// 死んだかどうか
	bool isDead;
	// 状態
	State state;

public:
	Enemy(Vec2 sPos, float mSpeed);
	virtual ~Enemy();
	void NoArgCallback() override;

	Rect* GetBounds();

	State GetState();

	void Update();

	void Draw() const;

	void Damage();

	bool IsOutOfScreen();

	bool IsHit(Rect target);

	bool IsDead();

	Vec2 GetPos();

private:
	void OnDead();
};
