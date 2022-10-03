#include "GameScene.hpp"
#include "Arrow.hpp"

GameScene::GameScene(const InitData& init): IScene(init)
{
	enemyManager = EnemyManager(&scoreManager);
	chara = Chara(arrowManager);
	uiManager = UIManager(&scoreManager, &chara);

	spawnTimer = 0;
	spawnCount = 0;

	bgm = Audio(BGM);
	bgm.setVolume(BGM_VOL);
	bgm.setLoop(true);
	bgm.play();
}

void GameScene::update()
{
	spawnTimer += Scene::DeltaTime();
	spawnCount += (SpawnEnemy(spawnTimer, spawnCount, enemyManager)) ? 1 : 0;
	spawnCount %= 10;

	background.Update();
	chara.Update();
	arrowManager.Update();
	enemyManager.Update();
	scoreManager.Update();
	uiManager.Update();

	HitEnemy(arrowManager, enemyManager);
	HitPlayer(enemyManager, chara);
	CollectDiamond(chara, scoreManager);

	// ゲーム終了-> クレジットに遷移
	if (chara.GetHP() <= 0 || KeyE.down())
	{
		bgm.stop();
		// 入手宝石の個数をセット
		getData().TotalDiamondGet = scoreManager.GetCollectedDiamonds();
		changeScene(U"Credit");
	}
}

void GameScene::draw() const
{
	background.Draw();
	chara.Draw();
	arrowManager.Draw();
	enemyManager.Draw();
	scoreManager.Draw();
	uiManager.Draw();
}

bool GameScene::SpawnEnemy(float& timer, const int time, EnemyManager& mng)
{
	if (timer >= EnemySpawnTimeSpan)
	{
		timer = 0;

		int offset = 2 * time;
		int spawnCont = Random(MinEnemyPerSpawn + offset , MaxEnemyPerSpawn + offset);

		for (int i = 0; i < spawnCont; i++)
		{
			mng.SpawnNewEenemy();
		}
		return true;
	}

	return false;
}

void GameScene::HitEnemy(ArrowManager& arrMng, EnemyManager& enmMng)
{
	auto arrows = *arrMng.GetAllArrow();
	auto enemies = *enmMng.GetAllEnemies();

	for (int a = 0; a < (int)arrows.size(); a++)
	{
		for (int i = 0; i < (int)enemies.size(); i++ )
		{
			Enemy::State checkState = enemies[i]->GetState();
			if ( checkState != Enemy::State::Normal)continue;
			if (arrows[a]->IsHitEnemy(*(enemies[i])->GetBounds()))
			{
				arrMng.BreakArrow(a);
				enmMng.DamageEnemy(i);
				break;
			}
		}
	}
}

void GameScene::HitPlayer(EnemyManager& enmMng, Chara& player)
{
	auto enemies = *enmMng.GetAllEnemies();

	for (int e = 0; e < (int)enemies.size(); e++)
	{
		Enemy* enemy = enemies[e];
		if (enemy->GetBounds()->intersects(*player.GetBounds()))
		{
			player.Damage();
		}
	}
}

void GameScene::CollectDiamond(Chara& player, ScoreManager& scrMng)
{
	scrMng.IsGainScore(player);
}
