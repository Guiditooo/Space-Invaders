#include <iostream>

#include "Enemy.h"

namespace game
{

	int Enemy::enemyCount = 0;

	Enemy::Enemy()
	{
		SetActive();

		this->SetTexture(&gameplay::enemyTexture);
		SetExtraTexture(&gameplay::enemyExtraTexture);

		entityColor = EntityColor::NONE;

		ResetEnemy();
		enemyID = enemyCount;
		enemyCount++;

		LM = LateralMove::TO_LEFT;
		VM = VerticalMove::TO_DOWN;

	}

	Enemy::~Enemy()
	{
		enemyID--;
	}

	int Enemy::GetEnemyID()
	{
		return enemyID;
	}

	void Enemy::Update()
	{
		if (VM == VerticalMove::TO_UP)
		{
			MoveUp();
		}
		else
		{
			MoveDown();
		}

		if (LM == LateralMove::TO_RIGHT)
		{
			MoveRight();
		}
		else
		{
			MoveLeft();
		}
	}

	void Enemy::Kill()
	{
		SetInactive();
		enemyCount--;
	}

	void Enemy::ResetEnemyCount()
	{
		enemyCount = 0;
	}

	void Enemy::GoLeft()
	{
		LM = LateralMove::TO_LEFT;
	}

	void Enemy::GoRight()
	{
		LM = LateralMove::TO_RIGHT;
	}

	void Enemy::GoUp()
	{
		VM = VerticalMove::TO_UP;
	}

	void Enemy::GoDown()
	{
		VM = VerticalMove::TO_DOWN;
	}

	LateralMove Enemy::GetLateralMovement()
	{
		return LM;
	}

	VerticalMove Enemy::GetVerticalMovement()
	{
		return VM;
	}

	void Enemy::MoveLeft()
	{
		Vec2 p = this->GetPosition();
		this->SetPosition(p.x - (gameplay::enemySpeedX * fix::frameTime), p.y);
	}

	void Enemy::MoveRight()
	{
		Vec2 p = this->GetPosition();
		this->SetPosition(p.x + (gameplay::enemySpeedX * fix::frameTime), p.y);
	}

	void Enemy::MoveUp()
	{
		Vec2 p = this->GetPosition();
		this->SetPosition(p.x, p.y - (gameplay::enemySpeedX * fix::frameTime));
	}

	void Enemy::MoveDown()
	{
		Vec2 p = this->GetPosition();
		this->SetPosition(p.x, p.y + (gameplay::enemySpeedX * fix::frameTime));
	}

	void Enemy::ResetEnemy()
	{

		this->SetEntityType(static_cast<EntityColor>(GetRandomValue(0, 3)));

		Vec2 p = this->GetPosition();

		float paddingX = ((screen::width - 2 * gameplay::enemySpawnPaddingX) - this->GetEntityWidth() * gameplay::enemyCountByRow) / (gameplay::enemyCountByRow - 1) + this->GetEntityWidth();
		int column = static_cast<int>(enemyCount % (static_cast<int>(gameplay::ENEMY_COUNT / gameplay::enemyCountByRow) + 1));

		int row = static_cast<int>(enemyCount / gameplay::enemyCountByRow);

		SetPosition(gameplay::enemySpawnPaddingX + (paddingX * column), gameplay::enemySpawnPaddingY + ((this->GetEntityHeight() + gameplay::enemySpacing) * row));

	}

	EntityColor Enemy::GetEntityType()
	{
		return entityColor;
	}

	void Enemy::SetEntityType(EntityColor newEntityColor)
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

	void Enemy::SetExtraTexture(Texture2D* extraTexture)
	{
		extra.texture = extraTexture;
		extra.texture->width = static_cast<int>(this->GetEntityWidth());
		extra.texture->height = static_cast<int>(this->GetEntityHeight());
	}

	void Enemy::Draw()
	{
		if (IsActive())
		{
			if (texture != nullptr)
			{
				DrawTexture(*texture, static_cast<int>(pos.x), static_cast<int>(pos.y), color);
			}
			else
			{
				DrawRectangle(static_cast<int>(pos.x), static_cast<int>(pos.y), static_cast<int>(width), static_cast<int>(height), color);
			}
			if (extra.texture != nullptr)
			{
				DrawTexture(*extra.texture, static_cast<int>(pos.x), static_cast<int>(pos.y), WHITE);
			}
		}
	}

}