#include "Background.hpp"

Background::Background()
{
	scroll = 0;
	bg = Texture(BACKGROUND_TEXTURE);
}

void Background::Update()
{
	// 画像の高さの半分だけを描画するので
	// 描画に必要な切り抜き位置を更新
	int height = bg.height() / 2;
	scroll++;
	scroll %= height;
}

void Background::Draw() const
{
	const int width = bg.width();
	const int height = bg.height() / 2;
	bg(0, scroll, width, height).draw();
}
