#include "CharaAnim.hpp"

CharaAnim::CharaAnim(): animations(Array<AnimData>()), callbackInstance(nullptr)
{
	//　デフォルトコンストラクター
}

CharaAnim::CharaAnim(Array<AnimData>& animationData, Callbacker* callbacker)
{
	frame = 0;
	animType = 0;
	animations = animationData;
	callbackInstance = callbacker;
}

CharaAnim::~CharaAnim()
{
	callbackInstance = 0;
}

void CharaAnim::Update()
{
	frame++;

	if (frame % AnimSampleFrame == 0)
	{
		animations[animType].UpdateAnim();

		if (animations[animType].IsFinish())
		{
			ChangeAnim(0);

			if (callbackInstance != nullptr)
			{
				callbackInstance->NoArgCallback();
				callbackInstance = nullptr;
			}
		}
	}

	frame %= MaxFrame;
}

void CharaAnim::ChangeAnim(int targetType)
{
	if (animType == targetType)return;
	animType = targetType;
	frame = 0;
	animations[animType].Reset();
}

TextureRegion CharaAnim::GetCurrentAnim() const
{
	return animations[animType].GetDrawTexture();
}
