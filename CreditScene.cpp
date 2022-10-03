#include "CreditScene.hpp"

CreditScene::CreditScene(const InitData& init): IScene(init)
{
	creditLabel = Font(50);
	creditDetail = Font(16);
	backToTitleLabel = Font(20);

	// 入手済み宝石の個数表示
	creditDatas << CreditData{ U"Total Diamond:{}"_fmt(getData().TotalDiamondGet), Palette::Orange };
	// 名前変更
	creditDatas << CreditData{U"Developed By BALA", Palette::Black};
	creditDatas << CreditData{U"https://www.senses-circuit.com/", Palette::Orange};
	creditDatas << CreditData{U"BGM：hitoshi by Senses Circuit", RandomColor()};
	creditDatas << CreditData{U"SE:hitoshi by Senses Circuit", RandomColor()};
	creditDatas << CreditData{U"SE:On-Jin ～音人～by Senses Circuit", RandomColor()};
}

void CreditScene::update()
{
	if (KeySpace.down())
	{
		// 宝石の数をリセット
		getData().TotalDiamondGet = 0;
		changeScene(U"Title");
	}
}

void CreditScene::draw() const
{
	Rect(0, 0, Scene::Width(), Scene::Height()).draw(Palette::Black);
	creditLabel(U"CREDIT").drawAt(Scene::Center().x, 50, Palette::White);

	const int creditDetailStartX = Scene::Center().x - 150;
	const int creditDetailStartY = Scene::Center().y - 200;
	RoundRect(creditDetailStartX, creditDetailStartY, 300, 400, 20).drawShadow(Vec2(5, 5), 20);
	RoundRect(creditDetailStartX, creditDetailStartY, 300, 400, 20).draw();

	const int paddingX = 24;
	const int paddingY = 24;

	int line = 0;
	for (auto creditData : creditDatas)
	{
		creditDetail(creditData.text).draw(creditDetailStartX + paddingX, creditDetailStartY + paddingY + (line * paddingY), creditData.color);
		++line;
	}
	backToTitleLabel(U"PRESS SPACE TO GO BACK TITLE").drawAt(Scene::Center().x, Scene::Height() - 50, HSV(Scene::Time()));
}
