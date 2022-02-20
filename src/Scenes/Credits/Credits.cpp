#include "Credits.h"

#include "General/Button/Button.h"

namespace game 
{

	namespace credits 
	{

		const int howManyCreditLines = 4;
		const int textSize = 30;
		const int textPadding = 30;

		const int buttonSize = 60;
		
		Text title;
		Text creditsText;
		Text creditsLib;
		Button closeButton;

		TextureInfo background;
		Texture2D BG;

		int time;
		float timer;

		void Init()
		{

			title.tx = "CREDITS";
			title.color = WHITE;
			title.size = static_cast<float>(screen::width / 10);
			title.pos.x = static_cast<float>(screen::width / 2 - MeasureTextEx(font, &title.tx[0], title.size, TEXT_SPACING).x/2);
			title.pos.y = MeasureTextEx(font, &title.tx[0], title.size, TEXT_SPACING).y;

			creditsText.tx = "Created by Guido Tello";
			creditsText.color = WHITE;
			creditsText.size = static_cast<float>(screen::width / 100 * 5);
			creditsText.pos.x = static_cast<float>(screen::width / 2 - MeasureTextEx(font, &creditsText.tx[0], creditsText.size, TEXT_SPACING).x / 2);
			creditsText.pos.y = screen::height/2 - MeasureTextEx(font, &creditsText.tx[0], creditsText.size, TEXT_SPACING).y;

			creditsLib.tx = "Created using Raylib";
			creditsLib.color = WHITE;
			creditsLib.size = static_cast<float>(screen::width / 100 * 5);
			creditsLib.pos.x = static_cast<float>(screen::width / 2 - MeasureTextEx(font, &creditsLib.tx[0], creditsLib.size, TEXT_SPACING).x / 2);
			creditsLib.pos.y = screen::height / 2 + MeasureTextEx(font, &creditsText.tx[0], creditsText.size, TEXT_SPACING).y;

			BG = LoadTexture("res/assets/backgrounds/MenuBG2.png");

			background.texture = &BG;
			background.texture->width = screen::width;
			background.texture->height = screen::height;

			closeButton.SetEntityWidth(buttonSize);
			closeButton.SetEntityHeight(buttonSize);
			closeButton.SetPosition(Vec2(screen::width - closeButton.GetEntityWidth() * 2, closeButton.GetEntityHeight()));
			closeButton.SetTextText("X");
			closeButton.SetTextSize(40);
			closeButton.SetTextColor(WHITE);
			closeButton.SetTextAlignement(txt::Alignement::CENTER_MID);
			closeButton.SetSceneToCharge(scene::SceneList::MENU);
			closeButton.SetTexture(&button::buttonTexture);
		}

		void Update()
		{

			if (IsKeyPressed(KEY_ESCAPE))
			{
				scene::nextScene = scene::SceneList::MENU;
			}

			if (timer != 0.0f) {
				if (static_cast<int>(timer) % BG_COLOR_CHANGE_TIMER == 0)
				{
					timer = 1;
					background.color = GetRandomColor(BG_COLOR_MIN, BG_COLOR_MAX);
				}
			}
			timer += GetFrameTime();

			closeButton.Update();
		}

		void Draw()
		{
			DrawTexture(*background.texture, 0, 0, background.color);
			closeButton.Draw();
			DrawTextEx(font, &title.tx[0], title.pos.ToVector2(), title.size, TEXT_SPACING, title.color);
			DrawTextEx(font, &creditsLib.tx[0], creditsLib.pos.ToVector2(), creditsLib.size, TEXT_SPACING, creditsLib.color);
			DrawTextEx(font, &creditsText.tx[0], creditsText.pos.ToVector2(), creditsText.size, TEXT_SPACING, creditsText.color);
		}

		void Deinit()
		{
			if (background.texture != nullptr) UnloadTexture(*background.texture);
		}

	}

}