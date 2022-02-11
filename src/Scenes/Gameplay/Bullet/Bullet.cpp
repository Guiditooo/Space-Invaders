#include "Bullet.h"

namespace game
{
	Bullet::Bullet()
	{
		type = BulletType::PLAYER;

		SetEntityWidth(20.0f);
		SetEntityHeight(50.0f);
	}
	Bullet::Bullet(BulletType newBulletType, Color newColor)
	{
		type = newBulletType;
		SetEntityColor(newColor);

		SetEntityWidth(20.0f);
		SetEntityHeight(50.0f);
	}

	Bullet::~Bullet()
	{

	}

	void Bullet::Update()
	{
		if (IsActive())
		{

			Vec2 p = this->GetPosition();

			if (type == BulletType::PLAYER)
			{
				SetPosition(p.x, p.y - gameplay::bulletSpeed);
				if (p.y + GetEntityHeight() < 0)
				{
					SetInactive();
				}
			}
			else
			{
				SetPosition(p.x, p.y + gameplay::bulletSpeed);
				if (p.y > screen::height)
				{
					SetInactive();
				}
			}

		}
	}

}

