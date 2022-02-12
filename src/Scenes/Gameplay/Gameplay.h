#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include "Player/Player.h"
#include "Bullet/Bullet.h"
#include "Enemy/Enemy.h"

namespace game
{

	namespace gameplay
	{

		extern int level;

		void Init();
		void Update();
		void Draw();
		void Deinit();

		void ResetEnemies();

		void CheckCollitions();
		void CheckPlayerBulletsAgainstEnemies();
		void CheckEnemyBulletsAgainstPlayer();

	}

}

#endif // !GAMEPLAY_H
