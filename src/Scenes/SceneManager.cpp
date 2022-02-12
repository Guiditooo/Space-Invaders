#include "SceneManager.h"

#include "Gameplay/Gameplay.h"

namespace game 
{

	SceneList actualScene = SceneList::NONE;
	SceneList nextScene = SceneList::GAME;

	void GeneralInit() // INITS THINGS THAT WILL START WITH THE GAME INIT, LIKE IMAGES AND MUSIC
	{

	}

	void GeneralUpdate() // UPGRADES THIGS THAT WILL BELONG AMONG ALL THE GAME, LIKE MUSIC PLAYERS
	{
	}

	void GeneralDraw() // DRAWS EVERYTHING THAT BELONG AMONG ALL THE GAME, LIKE MENU BUTTONS
	{
	}

	void GeneralDeinit() // DEINIT ALL STARTED OUTSIDE OF SCENES
	{

	}

	void CheckNextScene()
	{
		if (actualScene != nextScene) // WILL CHECK IF BOTH SCENES, ACTUAL AND NEXT ARE THE SAME OR NOT
		{
			switch (actualScene) // DEINIT ACTUAL SCENE
			{
			case game::SceneList::MENU:
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