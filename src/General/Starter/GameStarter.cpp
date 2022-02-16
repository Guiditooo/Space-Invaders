#include "GameStarter.h"
#include "Scenes/SceneManager.h"

namespace game
{
	namespace starter
	{

		void StartWindow()
		{
			InitWindow(screen::width, screen::height, "Space Invaders");
			SetTargetFPS(screen::fpsRate);
			GeneralInit();
		}

		void EndWindow()
		{
			GeneralDeinit();
			CloseWindow();
		}
	}

	void RunGame()
	{
		starter::StartWindow();
		do
		{
			CheckNextScene();
			Update();
			Draw();
		} while (!WindowShouldClose());
		starter::EndWindow();
	}


}