#ifndef ENEMY_H
#define ENEMY_H

#include "General/Enitity/Entity.h"

namespace game
{
	class Enemy : public Entity
	{
	private:
		int enemyID;
		static int enemyCount;
	public:
		Enemy();
		~Enemy();
		
		int GetEnemyID();
		static void ResetEnemyCount();
		void Kill();

		void Update() override;
	};
}

#endif // !ENEMY_H
