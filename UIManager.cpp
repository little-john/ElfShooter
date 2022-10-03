#include "UIManager.hpp"
#include "Diamond.hpp"
#include "ScoreManager.hpp"
#include "Chara.hpp"

UIManager::UIManager() {}

UIManager::UIManager(ScoreManager* scoreMng, Chara* player)
{
	label = Font(32);
	score = scoreMng;
	this->player = player;
	diamond = new Diamond(Vec2(Scene::Width() - 156, 28), 0);
}

UIManager::~UIManager()
{
	score = 0;
	player = 0;
}

void UIManager::Update()
{
	diamond->Update();
}

void UIManager::Draw() const
{
	// HPゲージの表示（下地）
	RoundRect(24, 24, 320, 32, 16).draw(Palette::Gray);

	// HPゲージの表示
	int maxHPWidth = 320;
	float hpRatio = (player->GetHP() * 1.0f) / (CharaMaxHP * 1.0f);
	Color hpGaugeColor = Palette::Lime;
	if (hpRatio < 0.2f)hpGaugeColor = Palette::Pink;
	else if (hpRatio <= 0.5f)hpGaugeColor = Palette::Orange;
	RoundRect(24, 24, hpRatio * maxHPWidth, 32, 16).draw(hpGaugeColor);

	// 取得済み宝石の表示（下地）
	RoundRect(Scene::Width() - 156, 24, 128, 32, 16).draw(Palette::Brown);

	// 宝石の描画
	diamond->Draw();

	// 個数の描画
	label(U"x{}"_fmt(score->GetCollectedDiamonds())).draw(Scene::Width() - 100, 16, Palette::Pink);
}
