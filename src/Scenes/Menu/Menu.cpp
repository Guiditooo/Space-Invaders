#include "Menu.h"
#include <iostream> 
#include <string>

namespace game {

	namespace menu {

		const int timeToShowLetters = 3;

		Texture2D BG;

		bool continueInGame = true;
		bool playedButtonSound = false;
		bool stTimeLoop;

		int time;
		float timer;

		int hoveredOption = 0;
		int hoveredOptionPast = 0;

		TextureInfo background;

		Text Title;

		Text btnText[button::MENU_BUTTONS_COUNT];
		Button btn[button::MENU_BUTTONS_COUNT];


		void Init() {
			
			BG = LoadTexture("res/assets/backgrounds/MenuBG1.png");
			
			background.texture = &BG;
			background.texture->width = screen::width;
			background.texture->height = screen::height;

			timer = 0;

			title->size = 120;
			title->tx = "Coloriens";
			title->color = WHITE;
			Vector2 measure = MeasureTextEx(font, &title->tx[0], title->size, TEXT_SPACING);
			title->pos = Vec2(screen::width / 2 - measure.x / 2, measure.y * 4 / 3);
			
			btnText[static_cast<int>(button::MenuButtons::PLAY)].tx = "PLAY";
			btnText[static_cast<int>(button::MenuButtons::CREDITS)].tx = "CREDITS";
			btnText[static_cast<int>(button::MenuButtons::EXIT)].tx = "EXIT";

			for (short i = 0; i < button::MENU_BUTTONS_COUNT; i++)
			{

				btnText[i].color = WHITE;
				btnText[i].size = 70;

				btn[i] = Button();
				btn[i].SetText(btnText[i]);
				btn[i].SetEntityWidth(button::buttonWidth);
				btn[i].SetEntityHeight(button::buttonHeight);
				btn[i].SetPosition(screen::width / 2 - btn[i].GetEntityWidth() / 2, button::MENU_BUTTONS_STARTING_POS_Y + (button::MENU_BUTTONS_SEPARATION + btn->GetEntityHeight()) * i);

			}
			
			btn[static_cast<int>(button::MenuButtons::PLAY)].SetSceneToCharge(scene::SceneList::GAME);
			btn[static_cast<int>(button::MenuButtons::CREDITS)].SetSceneToCharge(scene::SceneList::CREDITS);
			btn[static_cast<int>(button::MenuButtons::EXIT)].SetSceneToCharge(scene::SceneList::QUIT);
			

		}

		void Update() 
		{
			
			if (timer != 0.0f) {
				if (static_cast<int>(timer) % BG_COLOR_CHANGE_TIMER == 0)
				{
					timer = 1;
					background.color = GetRandomColor(BG_COLOR_MIN, BG_COLOR_MAX);
				}
			}
			timer += GetFrameTime();
			

			for (short i = 0; i < button::MENU_BUTTONS_COUNT; i++)
			{
				btn[i].Update();
			}


		}

		void Draw() 
		{
			//Color color;
			
			DrawTexture(*background.texture, 0, 0, background.color);

			DrawTextEx(font, &title->tx[0], title->pos.ToVector2(), static_cast<float>(title->size), TEXT_SPACING, title->color);

			for (short i = 0; i < button::MENU_BUTTONS_COUNT; i++)
			{
				btn[i].Draw();
			}
			


		}

		void Deinit() 
		{
			if(background.texture != nullptr) UnloadTexture(*background.texture);
		}


	}

}