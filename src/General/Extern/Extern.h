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
		const int STARTING_TIMER = 60;
		const int STARTING_SCORE = 0;

		extern float bulletSpeed;
		extern float horizontalSpeed; //Player speed moving among X
		extern float entityWidth;
		extern float entityHeight;
		extern float bulletWidth;
		extern float bulletHeight;
		extern float enemySpeedX; //Velocity of the enemy moving among X
		extern float enemySpeedY; //Velocity of the enemy moving among Y
		extern float enemyMinVerticalLimit; // delimits the movement in Y axis
		extern float enemyMaxVerticalLimit;
		extern float enemyCountByRow; //Default is 5;
		extern float enemySpacing; //Space between enemies
		extern float enemySpawnPaddingX; //From X = 0
		extern float enemySpawnPaddingY; //From Y = 0

		extern int level;
		extern int score;
		extern bool gameOver;

		const int TUTORIAL_COUNT = 4;
		const int TUTORIAL_KEYS = 5;
		const int GUI_SIZE = 40;
		const int COMPLETE_TITLE_SIZE = 55;
		const int COMPLETE_CONTINUE_SIZE = 40;
		const Color COLOR = WHITE;
		const int SCORE_ADD_PER_LVL = 10;
		const int SCORE_REMOVE_PER_LVL = 5;
		const int TIME_ADDED_BY_COMPLETION = 15;

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

		namespace parallax
		{
			const int PARALLAX_COUNT = 4;
			const int PARALLEL_IMAGES = 2;

			const float PARALLAX_SPEED_UP = 3.0f;
			const float PARALLAX_SPEED_DOWN = 6.0f;
			const float PARALLAX_SPEED_LEFT = 9.0f;
			const float PARALLAX_SPEED_RIGHT = 15.0f;

			enum class ParallaxDirection
			{
				P_UP,
				P_DOWN,
				P_LEFT,
				P_RIGHT
			};
		}

	}

	namespace screen
	{
		extern int width;
		extern int height;
		extern int fpsRate;
	}

	namespace scene
	{
		enum class SceneList
		{
			MENU,
			CREDITS,
			OPTIONS,
			GAME,
			QUIT,
			NONE
		};
		
		extern SceneList actualScene;
		extern SceneList nextScene;
	}

	namespace fix
	{
		extern bool fixed;
		extern Vector2 mousePos;
		extern float frameTime;
		extern bool keepLooping;
		extern float fixedMoveLeft;
		extern float fixedMoveRight;
	}

	enum class EntityColor
	{
		ENTITY_ORANGE,
		ENTITY_CYAN,
		ENTITY_LIME,
		ENTITY_PINK,
		ENTITY_WHITE,
		NONE
	};

	enum class EntityType
	{
		BUTTON,
		NONE
	};

	Color GetRandomColor(int min, int max);
	EntityColor GetEntityColor(Color color);
	Color MakeTraslucid(Color oldColor);

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
	
	namespace button
	{
		extern Texture2D buttonTexture;
		extern float buttonWidth;
		extern float buttonHeight;

		const int MENU_BUTTONS_COUNT = 3;
		const int MENU_BUTTONS_SEPARATION = 40;
		const float MENU_BUTTONS_STARTING_POS_Y = static_cast<float>(screen::height * 4 / 9);

		enum class MenuButtons
		{
			PLAY,
			CREDITS,
			EXIT
		};

	}

}

#endif // !EXTERN_H