#pragma once
#include "Common.h"


// 前方宣言
class Chara;
class Diamond;
class ScoreManager;

/*
* UIManager　UI表示ようのクラス
*/
class UIManager
{
	// 取得中の宝石個数表示用
	Font label;
	// 宝石
	Diamond* diamond;
	// スコアーマネジャー（宝石配列）への参照
	ScoreManager* score;
	// Charaへの参照
	Chara* player;
public:
	UIManager(ScoreManager*, Chara*);
	UIManager();
	~UIManager();
	void Update();
	void Draw() const;
};
