#pragma once
#include "Common.h"

// 宝石の画像ファイルパス
#define DIAMOND_TEXTURE U"sozai/others/gem.png"
#define DIA_HEIGHT 7
#define DIA_WIDTH 7
/*
* Diamond 宝石クラス
* 移動、描画、当たり判定領域を持ち
* 画面外に出たかどうかの処理もある
*/
class Diamond
{
	// 位置の座標
	Vec2 pos;
	// 移動速度
	float speed;
	// 当たり判定領域

protected:
	Rect bounds;
	// アニメーション
	class CharaAnim* anim;

public:
	Diamond(Vec2 sPos, float mSpeed);
	~Diamond();

	Rect* GetBounds();

	void Update();

	void Draw() const;

	bool IsOutOfScreen();

	virtual String GetTypeName();
};
