#include "Bullet.h"

namespace game
{
	Bullet::Bullet()
	{
		bulletType = gameplay::BulletType::PLAYER;
		
		SetTexture(&gameplay::bulletTexture);

		SetEntityWidth(gameplay::bulletWidth);
		SetEntityHeight(gameplay::bulletHeight);

		entityColor = EntityColor::NONE;

	}
	Bullet::Bullet(gameplay::BulletType newBulletType, Color newColor)
	{
		entityColor = EntityColor::NONE;
		bulletType = newBulletType;
		SetEntityColor(newColor);

		SetEntityWidth(gameplay::bulletWidth);
		SetEntityHeight(gameplay::bulletHeight);

	}

	Bullet::~Bullet()
	{

	}

	void Bullet::Update()
	{
		if (IsActive())
		{

			Vec2 p = this->GetPosition();

			if (bulletType == gameplay::BulletType::PLAYER)
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

	EntityColor Bullet::GetEntityType()
	{
		return entityColor;
	}

	void Bullet::SetEntityType(EntityColor newEntityColor)
	{
		entityColor = newEntityColor;

		switch (newEntityColor)
		{
		case game::EntityColor::ENTITY_ORANGE:
			color = ORANGE;
			break;
		case game::EntityColor::ENTITY_CYAN:
			color = SKYBLUE;
			break;
		case game::EntityColor::ENTITY_LIME:
			color = LIME;
			break;
		case game::EntityColor::ENTITY_PINK:
			color = PINK;
			break;
		case game::EntityColor::NONE:
			color = WHITE;
			break;
		default:
			break;
		}
	}

	void Bullet::SetExtraTexture(Texture2D* extraTexture)
	{
		extra.texture = extraTexture;
		extra.color = this->GetEntityColor();
	}

}

