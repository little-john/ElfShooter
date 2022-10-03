#pragma once
#include "Common.h"
#include "Enemy.hpp"

#define ENEMY_HIT_SE U"sozai/enemy_hit.mp3"

/*
* EnemyManager 敵の生成と、生成した敵を配列でもち
* 消されるまで、更新と描画処理を管理するクラス
*/
class EnemyManager
{
	// 敵のダメージSE
	Audio enemyHitSE;
	// スコアーへの参照（ランダムで宝石を生成するよう）
	class ScoreManager* scoreMng;
	// 生成した敵の配列
	Array<Enemy*> enemys;

public:
	EnemyManager();
	~EnemyManager();
	EnemyManager(ScoreManager* sMng);

	// 敵の生成処理
	void SpawnNewEenemy();

	void Update();

	void Draw() const;

	void DamageEnemy(size_t index);

	Array<Enemy*>* GetAllEnemies();
};
