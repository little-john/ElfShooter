#pragma once

#include <Siv3D.hpp>
#include "Callbacker.h"

// 画面間データを受渡するためのデータ構造
// HINT:クレジット画面で使えるかも！
struct GlobalData
{
	int TotalDiamondGet;
};

using GameApp = SceneManager<String, GlobalData>;

// キャラー関連定数
const int CharaSize                 = 32;
const int CharaMaxHP                = 10;
const int CharaSpeed                = 256;
const float CoolDownTimePerAttack   = 0.25f;
const float CoolDownTimePerHit      = 0.5f;
const int CharaArrowCountForPowerUp = 3;

// 矢関連定数
const int ArrowSize                 = 32;
const int ArrowMinSpeed             = 300;
const int ArrowMaxSpeed             = 400;

// 敵関連定数
const int EnemySize                 = 32;
const int EnemyMinSpeed             = 100;
const int EnemyMaxSpeed             = 200;
const double EnemySpawnTimeSpan     = 3.0f;
const int MinEnemyPerSpawn          = 5;
const int MaxEnemyPerSpawn          = 20;

// アニメーション関連定数
const int MaxFrame                  = 60;
const int AnimSampleFrame           = 12;
