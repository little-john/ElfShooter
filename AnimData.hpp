#pragma once
#include "Common.h"

/*
* AnimData　連番画像からアニメーションさせるために
* 画像の切り抜き領域を計算、切り抜いた画像を返すデータ構造
*/
struct AnimData
{
	// 表示中の画像
	int currentFrame;
	// 最大画像の枚数
	int maxFrame;
	// 画像ファイルの長さ
	int frameWidth;
	// メモリに展開する画像データ
	Texture animTexture;
	// ループ再生するかどうか
	bool loop;

public:

	AnimData(String texture, int frames, bool isLoop);

	// 表示中の画像を０番目に戻す
	void Reset();

	// 表示中の画像を更新
	// （１つ右へ移動、ループ時は最右にきたら０番に戻す）
	void UpdateAnim();

	// アニメーション再生が終了したかどうか
	bool IsFinish();

	// 描画する切り抜き領域を返す
	TextureRegion GetDrawTexture() const;
};