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
			if (fix::keepLooping)
			{
				Update();
				Draw();
			}
		} while (fix::keepLooping);
		starter::EndWindow();
	}


}