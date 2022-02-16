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

		//Buttons buttons[howManyButtons];
		Vector2 mousePoint = {0,0};

		int hoveredOption = 0;
		int hoveredOptionPast = 0;

		TextureInfo background;

		Text Title;
		Button btn;

		//TextureInfo pieceBlack;
		//TextureInfo pieceWhite;


		void init() {
			
			BG = LoadTexture("res/assets/backgrounds/MenuBG1.png");
			
			background.texture = &BG;
			background.texture->width = screen::width;
			background.texture->height = screen::height;

			timer = 0;

			int a = 9;
			a--;

			title->size = 120;
			title->tx = "Coloriens";
			title->color = WHITE;
			Vector2 measure = MeasureTextEx(font, &title->tx[0], title->size, TEXT_SPACING);
			title->pos = Vec2(screen::width / 2 - measure.x / 2, measure.y * 4 / 3);

			btn = Button();

			//Music
			//menuMusic = LoadMusicStream("res/assets/Music/menu.mp3");
			//PlayMusicStream(menuMusic);
			//SetMusicVolume(menuMusic, 0.1f);
			//
			//stTimeLoop = true;
			//
			//buttonBeep = LoadSound("res/assets/Sounds/buttonClic.ogg");
			//SetSoundVolume(buttonBeep, 0.3f);

			//title[1].tx = "CHESS";
			/*
			for (short i = 0; i < titleLenght; i++)
			{
				title[i].size = screen::height / 13;
				title[i].pos.x = screen::width / 2 - MeasureTextEx(font, &title[i].tx[0], title->size, 1).x / 2;
				title[i].pos.y = screen::height * (2 + i) / 13 + 5 * i;
				title[i].color = GetRandomColor(200,255);

			}
			*/

			/*
			for (short i = 0; i < howManyButtons; i++) {

				Buttons btn;
				std::string text;

				switch ((config::scenes::Scene)(i+1)) {

				case config::scenes::Scene::CONFIG:
					text = "PLAY";
					break;
				case config::scenes::Scene::CREDITS:
					text = "CREDITS";
					break;
				case config::scenes::Scene::QUIT:
					text = "EXIT";
					break;

				}

				btn.txt.tx = text;

				btn.square.width = (float)MeasureTextEx(font, &btn.txt.tx[0], baseTextHeight, 1).x;
				btn.square.height = (float)baseTextHeight;
				btn.square.x = (float)(config::screen::width / 2 - MeasureTextEx(font,&btn.txt.tx[0], btn.square.height,1).x/2);
				btn.square.y = config::screen::height * 19 / 40 + config::screen::height * i * 2 / 25;

				btn.color = BLACK;

				buttons[i] = btn;
				
			}
			*/
		}

		void update() 
		{
			
			if (timer != 0.0f) {
				if (static_cast<int>(timer) % BG_COLOR_CHANGE_TIMER == 0)
				{
					timer = 1;
					background.color = GetRandomColor(BG_COLOR_MIN, BG_COLOR_MAX);
				}
			}
			timer += GetFrameTime();
			

			

			/*
			if (stTimeLoop) 
			{
				mousePoint = { 0,0 };
				stTimeLoop = false;
			}
			else 
			{
				mousePoint = GetMousePosition();
			}

			if (playMusic)
			{
				UpdateMusicStream(menuMusic);
			}

			for (int i = 0; i < howManyButtons; i++) 
			{

				if (CheckCollisionPointRec(menu::mousePoint, buttons[i].square)) 
				{

					if (!buttons[i].selected) 
					{
						if (playSounds)
						{
							PlaySound(buttonBeep);
						}
						buttons[i].selected = true;

					}

					if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) 
					{

						config::scenes::next_scene = static_cast<config::scenes::Scene>(i + 1);

					}

				}
				else 
				{
					buttons[i].selected = false;
				}

			}

			*/

		}

		void draw() 
		{
			//Color color;
			
			DrawTexture(*background.texture, 0, 0, background.color);

			DrawTextEx(font, &title->tx[0], title->pos.ToVector2(), static_cast<float>(title->size), TEXT_SPACING, title->color);

			//
			//btn.Draw();

			/*
			for (short i = 0; i < titleLenght; i++) 
			{
				DrawTextEx(font, &title[i].tx[0], title[i].pos, title->size, 1, title[i].color);
			}

			for (short i = 0; i < howManyButtons; i++) 
			{
				Buttons btn = buttons[i];
				int heightCorrect = btn.square.height;

				if (btn.selected) 
				{
					color = LIME;
					btn.square.height *= plusSelected;
					btn.square.width = MeasureText(&btn.txt.tx[0], baseTextHeight);
					btn.square.x = config::screen::width / 2 - MeasureText(&btn.txt.tx[0], btn.square.height) / 2;
					btn.square.y = config::screen::height * 19 / 40 + config::screen::height * i * 2 / 25 - (btn.square.height - heightCorrect) / 2;
					//                      BASE                   +                VARIACION           - DIFERENCIA ENTRE LETRA GRANDE Y CHICA
				}
				else 
				{
					color = btn.color;
				}

				DrawTextEx(font, &(btn.txt.tx)[0], { btn.square.x, btn.square.y }, btn.square.height, 1, color);

			}

			DrawTextureEx(pieceWhite.texture, pieceWhite.position, 1, 1, WHITE);
			DrawTextureEx(pieceBlack.texture, pieceBlack.position, 1, 1, BROWN);
			*/

		}

		void deinit() 
		{
			if(background.texture != nullptr)
			UnloadTexture(*background.texture);
			/*
			UnloadTexture(bgTexture);
			UnloadSound(buttonBeep);
			UnloadMusicStream(menuMusic);
			*/
		}


	}

}