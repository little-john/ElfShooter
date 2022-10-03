#include "ArrowManager.hpp"
#include "Arrow.hpp"

ArrowManager::ArrowManager()
{
	shotSE = Audio(ARROW_SHOT_SE);
};

ArrowManager::~ArrowManager()
{
	for (auto arrow : arrows)
	{
		delete arrow;
	}

	arrows.clear();
}

void ArrowManager::ShotNewArrow(Vec2 pos)
{
	// 矢の速度は最低速〜最大速でランダムに選ぶ
	arrows << new Arrow(pos, Random(ArrowMinSpeed, ArrowMaxSpeed));
	shotSE.playOneShot();
}

void ArrowManager::Update()
{
	for (auto it = arrows.begin(); it != arrows.end();)
	{
		auto arrow = *it;
		arrow->Update();

		if (arrow->IsOutOfScreen()) // 画面外に出たら
		{
			delete arrow;
			it = arrows.erase(it); // 矢を消す（配列から削除）
		}
		else
		{
			++it;
		}
	}
}

Array<Arrow*>* ArrowManager::GetAllArrow()
{
	return &arrows;
}

void ArrowManager::BreakArrow(size_t index)
{
	size_t arraySize = arrows.size();
	if (arraySize < 0)return;
	if (index >= arraySize)return;

	delete arrows[index];
	arrows.remove_at(index);
}

void ArrowManager::Draw() const
{
	for (auto arrow : arrows)
	{
		arrow->Draw();
	}
}
