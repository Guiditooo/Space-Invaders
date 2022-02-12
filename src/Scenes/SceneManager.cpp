#include "SceneManager.h"

namespace game 
{
	SceneList actualScene = SceneList::NONE;
	SceneList nextScene = SceneList::MENU;

	void GeneralInit() // INITS THINGS THAT WILL START WITH THE GAME INIT, LIKE IMAGES AND MUSIC
	{
		differentEnemies[0] = LoadTexture("");
		differentEnemies[1] = LoadTexture("");
		differentEnemies[2] = LoadTexture("");
	}

	void GeneralUpdate() // UPGRADES THIGS THAT WILL BELONG AMONG ALL THE GAME, LIKE MUSIC PLAYERS
	{
	}

	void GeneralDraw() // DRAWS EVERYTHING THAT BELONG AMONG ALL THE GAME, LIKE MENU BUTTONS
	{
	}

	void GeneralDeinit() // DEINIT ALL STARTED OUTSIDE OF SCENES
	{
		for (short i = 0; i < DIFFERENT_ENEMY_COUNT; i++)
		{
			UnloadTexture(differentEnemies[i]);
		}
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
			break;
		case game::SceneList::NONE:
			break;
		default:
			break;
		}
	}

	void Draw() // WILL DRAW EVERYTHING: GENERAL + SCENE
	{
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
			break;
		case game::SceneList::NONE:
			break;
		default:
			break;
		}
	}

}