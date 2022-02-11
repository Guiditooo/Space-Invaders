#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include "Player/Player.h"
#include "Bullet/Bullet.h"

namespace game
{

	const int PLAYER_BULLETS = 10;

	namespace gameplay
	{

		void Init();
		void Update();
		void Draw();
		void Deinit();

	}

}

#endif // !GAMEPLAY_H
