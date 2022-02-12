#include <iostream>

#include "Enemy.h"

namespace game
{

	int Enemy::enemyCount = 0;

	Enemy::Enemy()
	{
		SetActive();
		this->SetEntityType(static_cast<EntityType>(GetRandomValue(0, 3)));

		Vec2 p = this->GetPosition();

		float paddingX = ((screen::width - 2 * gameplay::enemySpawnPaddingX) - this->GetEntityWidth() * gameplay::enemyCountByRow) / (gameplay::enemyCountByRow - 1) + this->GetEntityWidth();
		int column = static_cast<int>(enemyCount % (static_cast<int>(ENEMY_COUNT / gameplay::enemyCountByRow)+1));

		int row = static_cast<int>(enemyCount / gameplay::enemyCountByRow);

		SetPosition(gameplay::enemySpawnPaddingX + (paddingX * column), gameplay::enemySpawnPaddingY + ((this->GetEntityHeight() + gameplay::enemySpacing) * row));

		enemyID = enemyCount;
		enemyCount++;

		p = this->GetPosition();

		//std::cout << "\n Padding: (( " << screen::width << " - 2 * "<< gameplay::enemySpawnPaddingX << " - " << this->GetEntityWidth() << " * " << gameplay::enemyCountByRow << " ) / "<<gameplay::enemyCountByRow;
		//std::cout << "\n\n Enemy #" << enemyID << " is in:  " << p.x << " ~ " << p.y << " .";

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
		//Vec2 p = this->GetPosition();
		
		//SetPosition(p.x + gameplay::enemySpeedX, p.y + gameplay::enemySpeedY); MOVIMIENTO

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


}