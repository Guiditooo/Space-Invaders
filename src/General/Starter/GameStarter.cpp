#include "GameStarter.h"
#include "Scenes/SceneManager.h"

namespace game
{
	namespace starter
	{

		void StartWindow()
		{
			InitWindow(screen::width, screen::height, "Coloriens");
			SetTargetFPS(screen::fpsRate);
			SetExitKey(KEY_F12);
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