#ifndef ENEMY_H
#define ENEMY_H

#include "General/Enitity/Entity.h"

namespace game
{
	class Enemy : public Entity
	{
	private:
		static int enemyID;
	public:
		Enemy();
		~Enemy();
		int GetEnemyID();

		void Update() override;
	};
}

#endif // !ENEMY_H
