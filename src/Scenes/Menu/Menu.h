#ifndef MENU_H
#define MENU_H

#include "General/Extern/Extern.h"
#include "General/Button/Button.h"

namespace game {

	namespace menu {

		const int BG_COLOR_MIN = 180;
		const int BG_COLOR_MAX = 255;
		const int BG_COLOR_CHANGE_TIMER = 2; // in seconds
		const int TITLE_COLOR_CHANGE_TIMER = 8; // in seconds

		const int baseTextHeight = 50; // 30px
		const int howManyButtons = 3;
		const int titleWords = 2;

		//extern Buttons buttons[howManyButtons];
		static Text title[titleWords];

		extern Texture2D BG;

		//static Sound buttonBeep;
		//static Music menuMusic;

		void Init();
		void Update();
		void Draw();
		void Deinit();

	}

}

#endif