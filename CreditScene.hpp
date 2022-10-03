#pragma once
#include "Common.h"

struct CreditData
{
	String text;
	Color color;
};

/*
* CreditScene　クレジット画面
*/
class CreditScene : public GameApp::Scene
{
	Font creditLabel;
	Font creditDetail;
	Font backToTitleLabel;
	Array<CreditData> creditDatas;

public:
	CreditScene(const InitData& init);
	void update() override;
	void draw() const override;
};
