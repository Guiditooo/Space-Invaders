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
		const int GUI_SIZE = 40; 
		const Color GUI_COLOR = WHITE; 

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
		
		void ActualizeTimer();

		void RestartGame();

	}

}

#endif // !GAMEPLAY_H
