#pragma once
#include "Common.h"
# include "Background.hpp"
# include "Chara.hpp"
# include "ArrowManager.hpp"
# include "EnemyManager.hpp"
# include "ScoreManager.hpp"
# include "UIManager.hpp"

#define BGM U"sozai/bgm_loop.wav"
#define BGM_VOL 0.3

/*
* GameScene ゲーム画面
*/
class GameScene : public GameApp::Scene
{
	Chara chara;
	ScoreManager scoreManager;
	EnemyManager enemyManager;
	ArrowManager arrowManager;
	Background background;
	UIManager uiManager;

	Audio bgm;
	float spawnTimer;
	int spawnCount;

private:
	bool SpawnEnemy(float& timer, const int time, EnemyManager& mng);
	void HitEnemy(ArrowManager& arrMng, EnemyManager& enmMng);
	void HitPlayer(EnemyManager& enmMng, Chara& player);
	void CollectDiamond(Chara& player, ScoreManager& scrMng);
public:
	GameScene(const InitData& init);
	void update() override;
	void draw() const override;
};
