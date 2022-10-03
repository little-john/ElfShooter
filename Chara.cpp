#include "Chara.hpp"
#include "AnimData.hpp"
#include "ArrowManager.hpp"

Chara::Chara(ArrowManager& arrowMng)
{
	if (arrMng == nullptr)return;

	coolDown = 0;
	state = Normal;
	hp = CharaMaxHP;

	arrMng = &arrowMng;

	hitSE = Audio(CHARA_HIT_SE);
	pos = Vec2(Scene::Center().x - CharaSize / 2, Scene::Height() - CharaSize);
	bounds = Rect(pos.x, pos.y, CharaSize, CharaSize);

	Array<AnimData> animations;
	animations << AnimData(CHARA_IDLE_TEXTURE, 1, true);
	animations << AnimData(CHARA_ATTACK_TEXTURE, 3, false);
	animations << AnimData(CHARA_LEFT_TEXTURE, 6, false);
	animations << AnimData(CHARA_RIGHT_TEXTURE, 6, false);
	anim = CharaAnim(animations, nullptr);
}

Chara::Chara(): arrMng(nullptr)
{
	// デフォルトコンストラクター
}

Chara::~Chara()
{
	arrMng = 0;
}

int Chara::GetHP()
{
	return hp;
}

void Chara::Damage()
{
	//　クールダウン中は再度ダメージを受けない
	if (coolDown > 0.0f)
	{
		coolDown -= Scene::DeltaTime();
		return;
	}

	state = Hit;
	coolDown = CoolDownTimePerHit;

	if (hp > 0)hp--;// HPが０以上なら−１する
	anim.ChangeAnim(0);
	hitSE.playOneShot();
}

Rect* Chara::GetBounds()
{
	return &bounds;
}

void Chara::Update()
{
	if (coolDown > 0.0f)
	{
		// クールダウン中は時間を０になるまで減らす以外何もしない
		coolDown -= Scene::DeltaTime();
	}
	else
	{
		const int ATTACK 	= 1;
		const int LEFT 		= 2;
		const int RIGHT 	= 3;

		state = Normal;
		// 移動
		if (KeyLeft.pressed())
		{
			pos.x -= CharaSpeed * Scene::DeltaTime();
			anim.ChangeAnim(LEFT);
		}
		else if (KeyRight.pressed())
		{
			pos.x += CharaSpeed * Scene::DeltaTime();
			anim.ChangeAnim(RIGHT);
		}

		if (KeyUp.pressed())
		{
			pos.y -= CharaSpeed * Scene::DeltaTime();
		}
		else if (KeyDown.pressed())
		{
			pos.y += CharaSpeed * Scene::DeltaTime();
		}

		// 画面外に出ないように制御
		pos.x = (pos.x) < 0 ? 0 : pos.x;
		pos.x = (pos.x + CharaSize) > Scene::Width() ? Scene::Width() - CharaSize : pos.x;

		// 攻撃
		if (KeySpace.down())
		{
			state = Attack;
			anim.ChangeAnim(ATTACK);
			coolDown = CoolDownTimePerAttack;

			// 通常
			arrMng->ShotNewArrow(pos);

			// 攻撃力アップ済み
			if (arrowCount == CharaArrowCountForPowerUp)
			{
				Vec2 leftArrow = pos + Vec2(-15.0f, 0.0f);
				Vec2 righttArrow = pos + Vec2(15.0f, 0.0f);
				arrMng->ShotNewArrow(leftArrow);
				arrMng->ShotNewArrow(righttArrow);
			}
		}
	}

	anim.Update();
	bounds.setPos(pos.x, pos.y);
}

void Chara::Draw() const
{
	// 影の描画
	Rect shadow = bounds;
	shadow.moveBy(0, -(CharaSize / 2));
	shadow(anim.GetCurrentAnim()).draw(Palette::Black);

	// ダメージ受けた時の描画（色点滅）
	if (state == Hit)
	{
		const double hue = (Scene::Time() * 120);
		bounds(anim.GetCurrentAnim()).draw(HSV(hue));
	}// 通常の描画
	else
	{
		bounds(anim.GetCurrentAnim()).draw();
	}
}

void Chara::Recover()
{
	hp++;
	hp = (hp > CharaMaxHP) ? CharaMaxHP : hp;
}

void Chara::PowerUp()
{
	arrowCount = CharaArrowCountForPowerUp;
}
