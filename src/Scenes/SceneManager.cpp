#include "SceneManager.h"

#include "Gameplay/Gameplay.h"
#include "Menu/Menu.h"
#include "Credits/Credits.h"

namespace game 
{

	void GeneralInit() // INITS THINGS THAT WILL START WITH THE GAME INIT, LIKE IMAGES AND MUSIC
	{
		font = LoadFontEx("res/assets/font/font.ttf", 100, 0, 100);

		gameplay::enemyExtraTexture = LoadTexture("res/assets/enemy/extra.png");
		gameplay::bulletExtraTexture = LoadTexture("res/assets/bullet/extra.png");
		gameplay::playerExtraTexture = LoadTexture("res/assets/player/extra.png");
		gameplay::enemyTexture = LoadTexture("res/assets/enemy/Alien6.png");
		gameplay::bulletTexture = LoadTexture("res/assets/bullet/Bullet6.png");
		gameplay::playerTexture = LoadTexture("res/assets/player/Starship7.png");

		button::buttonTexture = LoadTexture("res/assets/button/Button.png");

	}

	void GeneralUpdate() // UPGRADES THIGS THAT WILL BELONG AMONG ALL THE GAME, LIKE MUSIC PLAYERS
	{
		if (fix::fixed)
		{
			fix::mousePos = GetMousePosition();
		}
		else
		{
			fix::mousePos = { -1,-1 };
		}
		
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
		UnloadTexture(button::buttonTexture);
	}

	void CheckNextScene()
	{
		if (scene::actualScene != scene::nextScene) // WILL CHECK IF BOTH SCENES, ACTUAL AND NEXT ARE THE SAME OR NOT
		{
			switch (scene::actualScene) // DEINIT ACTUAL SCENE
			{
			case game::scene::SceneList::MENU:
				menu::Deinit();
				break;
			case game::scene::SceneList::CREDITS:
				credits::Deinit();
				break;
			case game::scene::SceneList::OPTIONS:
				break;
			case game::scene::SceneList::GAME:
				gameplay::Deinit();
				break;
			case game::scene::SceneList::NONE:
				break;
			default:
				break;
			}

			switch (scene::nextScene) // INIT NEXT SCENE
			{
			case game::scene::SceneList::MENU:
				menu::Init();
				break;
			case game::scene::SceneList::CREDITS:
				credits::Init();
				break;
			case game::scene::SceneList::OPTIONS:
				break;
			case game::scene::SceneList::GAME:
				gameplay::Init();
				break;
			case game::scene::SceneList::QUIT:
				fix::keepLooping = false;
				break;
			default:
				break;
			}

			scene::actualScene = scene::nextScene; // FINISHING SWITCH ACTUAL SCENE WITH THE NEXT SCENE

		}
	}

	void Update() // WILL DRAW EVERYTHING: GENERAL + SCENE
	{
		GeneralUpdate();

		switch (scene::actualScene)
		{
		case game::scene::SceneList::MENU:
			menu::Update();
			break;
		case game::scene::SceneList::CREDITS:
			credits::Update();
			break;
		case game::scene::SceneList::OPTIONS:
			break;
		case game::scene::SceneList::GAME:
			gameplay::Update();
			break;
		case game::scene::SceneList::NONE:
			break;
		default:
			break;
		}
		if(!fix::fixed)	fix::fixed = true;
	}

	void Draw() // WILL DRAW EVERYTHING: GENERAL + SCENE
	{
		BeginDrawing();
		ClearBackground(BLACK);

		GeneralDraw();

		switch (scene::actualScene)
		{
		case game::scene::SceneList::MENU:
			menu::Draw();
			break;
		case game::scene::SceneList::CREDITS:
			credits::Draw();
			break;
		case game::scene::SceneList::OPTIONS:
			break;
		case game::scene::SceneList::GAME:
			gameplay::Draw();
			break;
		case game::scene::SceneList::NONE:
			break;
		default:
			break;
		}

		EndDrawing();
	}

}