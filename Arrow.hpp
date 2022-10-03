#pragma once
#include "Common.h"

// 矢の画像ファイルのパス
#define ARROW_TEXTURE U"sozai/chara/arrow.png"

/*
* Arrow　矢のクラス
* 移動、描画、当たり判定領域を持ち
* 画面外に出たかどうかや敵と接触したかの処理もある
*/
class Arrow
{
	// 矢の位置座よう
	Vec2 pos;
	// 矢の移動速度
	float speed;
	// 矢のメモリに展開される画像
	Texture arrow;
	// 矢の当たり判定領域（長方形）
	Rect bounds;

public:
	Arrow(Vec2 sPos, float mSpeed);

	void Update();

	// 画面外に出たかどうか
	bool IsOutOfScreen();

	void Draw() const;

	// 矢の当たり判定領域を返す
	Rect* GetBounds();

	// 引数の敵の領域と接触したかどうか
	bool IsHitEnemy(Rect& enemy);
};
