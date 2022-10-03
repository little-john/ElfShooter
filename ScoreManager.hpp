#pragma once
#include "Common.h"

class Diamond;
class Chara;

class ScoreManager
{
	Array<Diamond*> diamonds;
	Audio collectSE;
	int collectedDiamonds;

public:
	ScoreManager();
	~ScoreManager();

	int GetCollectedDiamonds();

	void AppearNewDiamond(Vec2 pos);

	void Update();

	void Draw() const;

	void CollectDiamond(size_t index);

	bool IsGainScore(Chara& player);
};
