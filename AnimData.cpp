#include "AnimData.hpp"

AnimData::AnimData(String texture, int frames, bool isLoop)
{
	loop = isLoop;
	currentFrame = 0;
	maxFrame = frames;
	animTexture = Texture(texture);
	frameWidth = animTexture.width() / frames;
}

void AnimData::Reset()
{
	currentFrame = 0;
}

void AnimData::UpdateAnim()
{
	if (loop)
	{
		currentFrame ++;
		currentFrame %= maxFrame;
	}
	else
	{
		if (currentFrame < maxFrame)currentFrame ++;
	}
}

bool AnimData::IsFinish()
{
	if (loop)return false;
	return currentFrame >= maxFrame;
}

TextureRegion AnimData::GetDrawTexture() const
{
	return animTexture(currentFrame * frameWidth, 0, frameWidth , animTexture.height() );
}
