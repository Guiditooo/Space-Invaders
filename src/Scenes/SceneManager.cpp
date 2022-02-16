#include "SceneManager.h"

#include "Gameplay/Gameplay.h"
#include "Menu/Menu.h"

namespace game 
{

	SceneList actualScene = SceneList::NONE;
	SceneList nextScene = SceneList::GAME;

	void GeneralInit() // INITS THINGS THAT WILL START WITH THE GAME INIT, LIKE IMAGES AND MUSIC
	{
		font = LoadFont("res/assets/font/font.ttf");
		gameplay::enemyExtraTexture = LoadTexture("res/assets/enemy/extra.png");
		gameplay::bulletExtraTexture = LoadTexture("res/assets/bullet/extra.png");
		gameplay::playerExtraTexture = LoadTexture("res/assets/player/extra.png");
		gameplay::enemyTexture = LoadTexture("res/assets/enemy/Alien5.png");
		gameplay::bulletTexture = LoadTexture("res/assets/bullet/Bullet6.png");
		gameplay::playerTexture = LoadTexture("res/assets/player/Starship5.png");
	}

	void GeneralUpdate() // UPGRADES THIGS THAT WILL BELONG AMONG ALL THE GAME, LIKE MUSIC PLAYERS
	{
	}

	void GeneralDraw() // DRAWS EVERYTHING THAT BELONG AMONG ALL THE GAME, LIKE MENU BUTTONS
	{
	}

	void GeneralDeinit() // DEINIT ALL STARTED OUTSIDE OF SCENES
	{
		UnloadFont(font);
		UnloadTexture(gameplay::enemyTexture);
		UnloadTexture(gameplay::enemyExtraTexture);
		UnloadTexture(gameplay::bulletTexture);
		UnloadTexture(gameplay::bulletExtraTexture);
		UnloadTexture(gameplay::playerTexture);
		UnloadTexture(gameplay::playerExtraTexture);
	}

	void CheckNextScene()
	{
		if (actualScene != nextScene) // WILL CHECK IF BOTH SCENES, ACTUAL AND NEXT ARE THE SAME OR NOT
		{
			switch (actualScene) // DEINIT ACTUAL SCENE
			{
			case game::SceneList::MENU:
				menu::deinit();
				break;
			case game::SceneList::CREDITS:
				break;
			case game::SceneList::OPTIONS:
				break;
			case game::SceneList::GAME:
				gameplay::Deinit();
				break;
			case game::SceneList::NONE:
				break;
			default:
				break;
			}

			switch (nextScene) // INIT NEXT SCENE
			{
			case game::SceneList::MENU:
				menu::init();
				break;
			case game::SceneList::CREDITS:
				break;
			case game::SceneList::OPTIONS:
				break;
			case game::SceneList::GAME:
				gameplay::Init();
				break;
			case game::SceneList::NONE:
				break;
			default:
				break;
			}

			actualScene = nextScene; // FINISHING SWITCH ACTUAL SCENE WITH THE NEXT SCENE

		}
	}

	void Update() // WILL DRAW EVERYTHING: GENERAL + SCENE
	{
		GeneralUpdate();

		switch (actualScene)
		{
		case game::SceneList::MENU:
			menu::update();
			break;
		case game::SceneList::CREDITS:
			break;
		case game::SceneList::OPTIONS:
			break;
		case game::SceneList::GAME:
			gameplay::Update();
			break;
		case game::SceneList::NONE:
			break;
		default:
			break;
		}
	}

	void Draw() // WILL DRAW EVERYTHING: GENERAL + SCENE
	{
		BeginDrawing();
		ClearBackground(BLACK);

		GeneralDraw();

		switch (actualScene)
		{
		case game::SceneList::MENU:
			menu::draw();
			break;
		case game::SceneList::CREDITS:
			break;
		case game::SceneList::OPTIONS:
			break;
		case game::SceneList::GAME:
			gameplay::Draw();
			break;
		case game::SceneList::NONE:
			break;
		default:
			break;
		}

		EndDrawing();
	}

}