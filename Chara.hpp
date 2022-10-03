#pragma once
#include "Common.h"
#include "CharaAnim.hpp"

// SEや画像ファイルパス
#define CHARA_HIT_SE U"sozai/chara_hit.mp3"
#define CHARA_IDLE_TEXTURE U"sozai/chara/idle.png"
#define CHARA_ATTACK_TEXTURE U"sozai/chara/attack.png"
#define CHARA_LEFT_TEXTURE U"sozai/chara/walk_left.png"
#define CHARA_RIGHT_TEXTURE U"sozai/chara/walk_right.png"

/*
* Chara プレイヤーキャラクラス
* 移動、描画、当たり判定領域を持ち
* クールダウンタイムや状態を保ちます。
*
* 左右キーで移動、スペースキーで矢を撃ちます
* ダメージ受ける時や矢を撃った直後はクールダウン時間分
* 操作できなくなります。
*/
class Chara
{
	// 描画するアニメーションデータ
	CharaAnim anim;
	// 当たり判定領域
	Rect bounds;
	// 位置の座標
	Vec2 pos;
	// クールダウン時間
	float coolDown;
	// 矢の管理処理への参照
	class ArrowManager* arrMng;
	// 敵に攻撃されたじのSE
	Audio hitSE;
	// 体力
	int hp;
	// 1回の攻撃で打つ矢の数
	int arrowCount = 1;
	// 状態
	enum State
	{
		Normal,   // 通常
		Attack,   // 攻撃した
		Hit       // ダメージ食らった
	};
	State state;

public:
	Chara();
	Chara(ArrowManager& arrowMng);
	~Chara();
	// 当たり判定領域を返す
	Rect* GetBounds();
	void Update();
	void Draw() const;
	// 体力を返す
	int GetHP();
	// ダメージを受ける
	void Damage();
	// 回復する
	void Recover();
	// 攻撃力アップ
	void PowerUp();
};
