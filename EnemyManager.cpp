#include "EnemyManager.hpp"
#include "ScoreManager.hpp"

EnemyManager::EnemyManager() {}
EnemyManager::EnemyManager(ScoreManager* sMng)
{
	scoreMng = sMng;
	enemyHitSE = Audio(ENEMY_HIT_SE);
}

EnemyManager::~EnemyManager()
{
	for (auto enemy : enemys)
	{
		delete enemy;
	}
	enemys.clear();
	scoreMng = 0;
}

void EnemyManager::SpawnNewEenemy()
{
	Vec2 pos = RandomVec2(Scene::Width() - CharaSize);
	pos.y = -CharaSize;
	enemys << new Enemy(pos, Random(EnemyMinSpeed, EnemyMaxSpeed));
}

void EnemyManager::DamageEnemy(size_t index)
{
	enemyHitSE.playOneShot();
	enemys[index]->Damage();
}

void EnemyManager::Update()
{
	for (auto it = enemys.begin(); it != enemys.end();)
	{
		Enemy* enemy = (*it);
		// 敵が画面外　OR 死んだら
		if (enemy->IsOutOfScreen() || enemy->IsDead())
		{
			if (Random() >= 0.8)// 2割の確率で宝石の生成
			{
				scoreMng->AppearNewDiamond(enemy->GetPos());
			}

			delete enemy;
			it = enemys.erase(it);
		}
		else
		{
			enemy->Update();
			++it;
		}
	}
}

void EnemyManager::Draw() const
{
	for (auto it = enemys.begin(); it != enemys.end();)
	{
		(*it)->Draw();
		++it;
	}
}

Array<Enemy*>* EnemyManager::GetAllEnemies()
{
	return &enemys;
}
