#pragma once
#include "Common.h"

// 背景画像のファイルパス
#define BACKGROUND_TEXTURE U"sozai/background.png"

/*
* Background　背景描画ようクラス
*/
class Background
{
	//　縦スクロールさせるための位置
	int scroll;
	//　メモリ上に展開される背景画像
	Texture bg;

public:
	Background();
	void Update();
	void Draw() const;
};
