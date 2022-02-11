#include "GameStarter.h"

namespace game
{
	namespace starter
	{

		void StartWindow()
		{
			InitWindow(screen::width, screen::height, "Space Invaders");
			SetTargetFPS(screen::fpsRate);
		}

		void EndWindow()
		{
			CloseWindow();
		}
	}

	void RunGame()
	{
		starter::StartWindow();
		//loop
		starter::EndWindow();
	}


}