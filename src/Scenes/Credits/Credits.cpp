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
		Button closeButton;

		TextureInfo background;
		Texture2D BG;

		int time;
		float timer;

		void Init()
		{

			BG = LoadTexture("res/assets/backgrounds/MenuBG1.png");

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
		}

		void Deinit()
		{
			if (background.texture != nullptr) UnloadTexture(*background.texture);
		}

	}

}