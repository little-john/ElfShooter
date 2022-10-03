# include <Siv3D.hpp>
# include "TitleScene.hpp"
# include "CreditScene.hpp"
# include "GameScene.hpp"

void Main()
{
	Scene::SetBackground(Palette::Black);
	Window::SetTitle(U"Shooting Game");
	Window::Resize(640, 640);

	GameApp manager;
	manager.add<TitleScene>(U"Title");
	manager.add<GameScene>(U"Game");
	manager.add<CreditScene>(U"Credit");

	while (System::Update())
	{
		if (not manager.update())
		{
			break;
		}
	}
}
