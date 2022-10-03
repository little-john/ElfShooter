#pragma once
#include "Common.h"

// 矢の撃つSEのファイルパス
#define ARROW_SHOT_SE U"sozai/shot.mp3"

class Arrow; // 前方宣言

/*
* ArrowManager 矢の生成と、生成した矢を配列でもち
* 消されるまで、更新と描画処理を管理するクラス
*/
class ArrowManager
{
	// 生成した矢の保持する配列
	Array<Arrow*> arrows;
	// 矢の撃つSEファイル
	Audio shotSE;

public:
	ArrowManager();
	~ArrowManager();

	// 引数の位置座標に新し矢を生成させる
	void ShotNewArrow(Vec2 pos);

	// 配列中の矢の更新処理を呼び出す
	void Update();

	// 配列中の矢の描画処理を呼び出す
	void Draw() const;

	// 引数の配列の位置（番号）の矢を消す
	void BreakArrow(size_t index);

	// 矢の配列を返す
	Array<Arrow*>* GetAllArrow();
};
