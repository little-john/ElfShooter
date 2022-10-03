#include "TitleScene.hpp"

TitleScene::TitleScene(const InitData& init): IScene(init)
{
	gameTitleLabel = Font(50);
	clickToStartLabel = Font(20);
}

void TitleScene::update()
{
	if (KeySpace.down())
	{
		changeScene(U"Game");
	}
}

void TitleScene::draw() const
{
	Rect(0, 0, Scene::Width(), Scene::Height()).draw();

	Line(0, 50, Scene::Center().x + 100, 50).draw(3, Palette::Red);
	Line(Scene::Center().x + 100, 50, Scene::Center().x - 100, Scene::Height() - 50).draw(3, Palette::Red);
	Line(Scene::Width(), Scene::Height() - 50, Scene::Center().x - 100, Scene::Height() - 50).draw(3, Palette::Blue);

	gameTitleLabel(U"ELF SHOOTER").drawAt(Scene::Center()).stretched(40, 0).shearedX(20).draw();
	gameTitleLabel(U"ELF SHOOTER").drawAt(Scene::Center(), Palette::Orange).stretched(40, 0).shearedX(20).drawFrame(2, Palette::Black);

	const double hue = (Scene::Time() * 90);
	clickToStartLabel(U"PRESS SPACE TO START").drawAt(Scene::Center() + Vec2(0, 100), HSV(hue));
}
