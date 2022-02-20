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

		const int TUTORIAL_COUNT = 4;
		const int TUTORIAL_KEYS = 5;
		enum class TK
		{
			TUTO_A,
			TUTO_S,
			TUTO_D,
			TUTO_P,
			TUTO_SPACE
		};

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
