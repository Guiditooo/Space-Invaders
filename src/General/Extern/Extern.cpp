#include "Extern.h"

namespace game
{
	namespace screen
	{
		int width = 1000;
		int height = 900;
		int fpsRate = 60;
	}

	namespace scene
	{
		SceneList actualScene = SceneList::NONE;
		SceneList nextScene = SceneList::MENU;
	}
		

	namespace fix
	{
		bool fixed = false;
		Vector2 mousePos = { 0,0 };
		float frameTime = 0;
		bool keepLooping = true;
		float fixedMoveLeft = 3;
		float fixedMoveRight = 6.7f;
	}		  

	namespace gameplay
	{
		float bulletSpeed = 10.0f;
		float horizontalSpeed = 160.0f;
		float entityWidth = 65.0f;
		float entityHeight = 60.0f;
		float bulletWidth = entityWidth/5;
		float bulletHeight = entityHeight/2;
		float enemySpeedX = 20.0f;
		float enemySpeedY = 1.0f;
		float enemyCountByRow = 5.0f;
		float enemyCountByColumn = 4.0f;
		float enemySpacing = 20.0f;
		float enemySpawnPaddingX = static_cast<float>(screen::width/5);
		float enemySpawnPaddingY = static_cast<float>(screen::height/9);
		float enemyMinVerticalLimit = enemySpawnPaddingY;
		float enemyMaxVerticalLimit = (entityHeight + enemySpacing) * enemyCountByColumn + enemySpacing * 2;

		Texture2D enemyTexture;
		Texture2D enemyExtraTexture;
		Texture2D bulletTexture;
		Texture2D bulletExtraTexture;
		Texture2D playerTexture;
		Texture2D playerExtraTexture;

	}

	Color GetRandomColor(int min, int max) 
	{
		return { static_cast<unsigned char>(GetRandomValue(min, max)), static_cast<unsigned char>(GetRandomValue(min, max)), static_cast<unsigned char>(GetRandomValue(min,max)), static_cast<unsigned char>(GetRandomValue(200,255)) };
	}

	EntityColor GetEntityColor(Color color)
	{
		EntityColor ret;

		if (color.a == ORANGE.a && color.r == ORANGE.r && color.g == ORANGE.g && color.b == ORANGE.b)
		{
			ret = EntityColor::ENTITY_ORANGE;
		}
		else if (color.a == SKYBLUE.a && color.r == SKYBLUE.r && color.g == SKYBLUE.g && color.b == SKYBLUE.b)
		{
			ret = EntityColor::ENTITY_CYAN;
		}
		else if (color.a == LIME.a && color.r == LIME.r && color.g == LIME.g && color.b == LIME.b)
		{
			ret = EntityColor::ENTITY_LIME;
		}
		else if (color.a == PINK.a && color.r == PINK.r && color.g == PINK.g && color.b == PINK.b)
		{
			ret = EntityColor::ENTITY_PINK;
		}
		else if (color.a == WHITE.a && color.r == WHITE.r && color.g == WHITE.g && color.b == WHITE.b)
		{
			ret = EntityColor::ENTITY_WHITE;
		}
		else
		{
			ret = EntityColor::NONE;
		}

		return ret;
	}

	Color MakeTraslucid(Color oldColor)
	{
		oldColor.a = 70;
		return oldColor;
	}

	Font font;
	namespace button
	{
		Texture2D buttonTexture;
		float buttonWidth = static_cast<float>(screen::width / 10 * 4);
		float buttonHeight = static_cast<float>(screen::width / 10);
	}

}