#include "Extern.h"

namespace game
{
	namespace screen
	{
		int width = 1000;
		int height = 900;
		int fpsRate = 60;
	}

	namespace gameplay
	{
		float bulletSpeed = 5.0f;
		float horizontalSpeed = 3.0f;
		float entityWidth = 65.0f;
		float entityHeight = 60.0f;
		float bulletWidth = entityWidth/4;
		float bulletHeight = entityHeight/2;
		float enemySpeedX = 1.0f;
		float enemySpeedY = 0.2f;
		float enemyCountByRow = 5.0f;
		float enemySpacing = 20.0f;
		float enemySpawnPaddingX = static_cast<float>(screen::width/5);
		float enemySpawnPaddingY = static_cast<float>(screen::height/9);
	}

	Texture2D differentEnemies[DIFFERENT_ENEMY_COUNT];

}