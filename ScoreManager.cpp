#include "ScoreManager.hpp"
#include "Diamond.hpp"
#include "Health.hpp"
#include "PowerUp.hpp"
#include "Chara.hpp"

ScoreManager::ScoreManager()
{
	collectSE = Audio(U"sozai/collect.mp3");
	collectedDiamonds = 0;
}

ScoreManager::~ScoreManager()
{
	for (auto diamond : diamonds)
	{
		delete diamond;
	}

	diamonds.clear();
}

void ScoreManager::AppearNewDiamond(Vec2 pos)
{
	float itemRate = Random();

	if (itemRate > 0.9f) // 1割り
	{
		diamonds << new PowerUp(pos, Random(EnemyMinSpeed, EnemyMaxSpeed));
	}
	else if (itemRate > 0.7f)// 2割り
	{
		diamonds << new Health(pos, Random(EnemyMinSpeed, EnemyMaxSpeed));
	}
	else // 7割り
	{
		diamonds << new Diamond(pos, Random(EnemyMinSpeed, EnemyMaxSpeed));
	}
	
}

void ScoreManager::Update()
{
	for (auto it = diamonds.begin(); it != diamonds.end();)
	{
		auto diamond = *it;
		diamond->Update();

		if (diamond->IsOutOfScreen())
		{
			delete diamond;
			it = diamonds.erase(it);
		}
		else
		{
			++it;
		}
	}
}

void ScoreManager::Draw() const
{
	for (auto diamond : diamonds)
	{
		diamond->Draw();
	}
}

void ScoreManager::CollectDiamond(size_t index)
{
	size_t arraySize = diamonds.size();
	if (arraySize < 0)return;
	if (index >= arraySize)return;

	collectSE.playOneShot();
	delete diamonds[index];
	diamonds.remove_at(index);
	collectedDiamonds++;
}

bool ScoreManager::IsGainScore(Chara& player)
{
	bool isScoreGained = false;

	for (int d = 0; d < (int)diamonds.size(); d++)
	{
		if (diamonds[d]->GetBounds()->intersects(*player.GetBounds()))
		{
			auto hitObject = diamonds[d];

			// 回復アイテムの場合
			if (hitObject->GetTypeName() == U"HEALTH")
			{
				collectSE.playOneShot();
				delete diamonds[d];
				diamonds.remove_at(d);
				player.Recover();
			}
			else if (hitObject->GetTypeName() == U"POWERUP")
			{
				collectSE.playOneShot();
				delete diamonds[d];
				diamonds.remove_at(d);
				player.PowerUp();
			}
			else
			{
				CollectDiamond(d);
				isScoreGained = true;
			}
			
		}
	}

	return isScoreGained;
}

int ScoreManager::GetCollectedDiamonds()
{
	return collectedDiamonds;
}
