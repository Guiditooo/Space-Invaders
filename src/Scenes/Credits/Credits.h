#ifndef MENU_CREDITS
#define MENU_CREDITS

#include "General/Extern/Extern.h"

namespace game 
{

	namespace credits 
	{

		const int BG_COLOR_MIN = 70;
		const int BG_COLOR_MAX = 130;
		const int BG_COLOR_CHANGE_TIMER = 2; // in seconds

		void Init();
		void Update();
		void Draw();
		void Deinit();

	}

}

#endif