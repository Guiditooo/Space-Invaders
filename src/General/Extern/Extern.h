#ifndef EXTERN_H
#define EXTERN_H

#include "raylib.h"

namespace game
{

	namespace gameplay
	{

		const int PLAYER_BULLET_COUNT = 10;
		const int ENEMY_BULLET_COUNT = 10;

		const int DIFFERENT_ENEMY_COUNT = 3;
		const int ENEMY_COUNT = 20;

		const int STARTING_LEVEL = 1;

		extern float bulletSpeed;
		extern float horizontalSpeed; //Player speed moving among X
		extern float entityWidth;
		extern float entityHeight;
		extern float bulletWidth;
		extern float bulletHeight;
		extern float enemySpeedX; //Velocity of the enemy moving among X
		extern float enemySpeedY; //Velocity of the enemy moving among Y
		extern float enemyCountByRow; //Default is 5;
		extern float enemySpacing; //Space between enemies
		extern float enemySpawnPaddingX; //From X = 0
		extern float enemySpawnPaddingY; //From Y = 0

		extern Texture2D differentEnemies[gameplay::DIFFERENT_ENEMY_COUNT];
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

	

}

#endif // !EXTERN_H