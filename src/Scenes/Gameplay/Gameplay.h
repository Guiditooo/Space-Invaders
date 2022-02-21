#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include "Player/Player.h"
#include "Bullet/Bullet.h"
#include "Enemy/Enemy.h"
#include "GameOver/GameOver.h"

namespace game
{

	namespace gameplay
	{

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
		void CheckForLevelFinished();
		void CheckTimer();
		
		void ActualizeTimer();
		void ActualizeLevel();
		void ActualizeFinishedLevel();
		void ActualizeScore();

		void RestartGame();

	}

}

#endif // !GAMEPLAY_H
