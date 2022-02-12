#include "Enemy.h"

namespace game
{

	int Enemy::enemyID = 0;

	Enemy::Enemy()
	{
		SetActive();
		this->SetEntityType(static_cast<EntityType>(GetRandomValue(0, 3)));
		enemyID++;
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
		Vec2 p = this->GetPosition();
		
		//SetPosition(p.x + gameplay::enemySpeedX, p.y + gameplay::enemySpeedY); MOVIMIENTO

	}


}