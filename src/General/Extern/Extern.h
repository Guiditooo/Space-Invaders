#ifndef EXTERN_H
#define EXTERN_H

#include "raylib.h"

namespace game
{

	const int DIFFERENT_ENEMY_COUNT = 3;

	namespace gameplay
	{
		extern float bulletSpeed;
		extern float horizontalSpeed;
		extern float entityWidth;
		extern float entityHeight;
		extern float bulletWidth;
		extern float bulletHeight;
		extern float enemySpeedX;
		extern float enemySpeedY;
	}

	namespace screen
	{
		extern int width;
		extern int height;
		extern int fpsRate;
	}


	enum class SceneList
	{
		MENU,
		CREDITS,
		OPTIONS,
		GAME,
		NONE
	};

	enum class EntityType
	{
		ENTITY_ORANGE,
		ENTITY_CYAN,
		ENTITY_LIME,
		ENTITY_PINK,
		NONE
	};

	enum class BulletType
	{
		ENEMY,
		PLAYER
	};

	extern Texture2D enemy[DIFFERENT_ENEMY_COUNT];

}

#endif // !EXTERN_H