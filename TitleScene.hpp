#pragma once
#include "Common.h"

/*
* TitleScene タイトル画面
*/
class TitleScene : public GameApp::Scene
{
	Font gameTitleLabel;
	Font clickToStartLabel;
public:
	TitleScene(const InitData& init);
	void update() override;
	void draw() const override;
};
