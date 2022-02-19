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
		bool keepLooping = true;
	}

	namespace gameplay
	{
		float bulletSpeed = 10.0f;
		float horizontalSpeed = 160.0f;
		float entityWidth = 65.0f;
		float entityHeight = 60.0f;
		float bulletWidth = entityWidth/5;
		float bulletHeight = entityHeight/2;
		float enemySpeedX = 1.0f;
		float enemySpeedY = 0.2f;
		float enemyCountByRow = 5.0f;
		float enemySpacing = 20.0f;
		float enemySpawnPaddingX = static_cast<float>(screen::width/5);
		float enemySpawnPaddingY = static_cast<float>(screen::height/9);

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