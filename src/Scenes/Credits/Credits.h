#ifndef MENU_CREDITS
#define MENU_CREDITS

#include "General/Extern/Extern.h"

using namespace std;

namespace game 
{

	namespace credits 
	{

		static Sound buttonBeep;
		static Music creditMusic;

		void init();
		void update();
		void draw();
		void deinit();

	}

}

#endif