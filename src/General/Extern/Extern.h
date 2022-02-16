#ifndef EXTERN_H
#define EXTERN_H

#include "General/Vec2/Vec2.h"
#include <string>

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

		extern Texture2D enemyTexture;
		extern Texture2D enemyExtraTexture;
		extern Texture2D bulletTexture;
		extern Texture2D bulletExtraTexture;
		extern Texture2D playerTexture;
		extern Texture2D playerExtraTexture;

		enum class BulletType
		{
			ENEMY,
			PLAYER
		};

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
		QUIT,
		NONE
	};

	enum class EntityColor
	{
		ENTITY_ORANGE,
		ENTITY_CYAN,
		ENTITY_LIME,
		ENTITY_PINK,
		NONE
	};

	enum class EntityType
	{
		BUTTON,
		NONE
	};

	Color getRandomColor(int min, int max);

	namespace txt
	{
		enum class Alignement
		{
			LEFT_TOP,
			LEFT_MID,
			LEFT_BOT,
			CENTER_TOP,
			CENTER_MID,
			CENTER_BOT,
			RIGHT_TOP,
			RIGHT_MID,
			RIGHT_BOT
		};
	}

	struct Text
	{
		std::string tx = "";
		Vec2 pos = Vec2(0,0);
		float size = 5;
		Color color = BLACK;
		txt::Alignement alignement = txt::Alignement::CENTER_MID;
	};

	struct TextureInfo
	{
		Texture2D* texture;
		Color color;
		Vector2 position = { 0,0 };
	};

	extern Font font; //General game font
	const float TEXT_SPACING = 2.0f;

}

#endif // !EXTERN_H