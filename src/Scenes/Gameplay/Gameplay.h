#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include "Player/Player.h"
#include "Bullet/Bullet.h"
#include "Enemy/Enemy.h"

namespace game
{

	const int PLAYER_BULLETS = 10;
	const int ENEMY_COUNT = 20;

	namespace gameplay
	{

		void Init();
		void Update();
		void Draw();
		void Deinit();

	}

}

#endif // !GAMEPLAY_H
