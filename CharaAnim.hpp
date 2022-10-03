#pragma once
#include "Common.h"
#include "AnimData.hpp"

/*
* CharaAnim 連番管理クラス
* 複数の連番アニメーションを配列でもち
* アニメーションの更新と切り替えをできるように提供する
*/
class CharaAnim
{
	// 保持したいアニメーションデータの配列
	Array<AnimData> animations;
	// アニメーション更新用フレームカウンター
	int frame;
	// 表示中のアニメーションタイプ
	int animType;
	// アニメーション完了時に通知したいコールバック
	Callbacker* callbackInstance;

public:
	CharaAnim();
	CharaAnim(Array<AnimData>& animationData, Callbacker* instance);
	~CharaAnim();

	void Update();

	// アニメーションの変更
	// 引数の番号を使って、
	// 配列から変更したいアニメーションを取り出す
	void ChangeAnim(int targetType);

	TextureRegion GetCurrentAnim() const;
};
