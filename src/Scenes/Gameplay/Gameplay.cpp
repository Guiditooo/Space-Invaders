#include "Gameplay.h"

namespace game
{

	namespace gameplay
	{
		Player p;
		Bullet playerBullets[PLAYER_BULLETS];
		Enemy e;

		void Init()
		{
			p.SetPosition(static_cast<float>(screen::width / 2 - p.GetEntityWidth() / 2), static_cast<float>(screen::height) - static_cast<float>(100));
		}
		void Update() 
		{
			if (IsKeyPressed(KEY_S))
			{
				p.TurnNextColor();
			}

			if (IsKeyDown(KEY_D))
			{
				p.MoveRight();
			}
			else if (IsKeyDown(KEY_A))
			{
				p.MoveLeft();
			}

			if (IsKeyPressed(KEY_SPACE))
			{

				for (short i = 0; i < PLAYER_BULLETS; i++)
				{
					if (!playerBullets[i].IsActive())
					{
						playerBullets[i].SetActive();
						Vec2 posP = p.GetPosition();
						playerBullets[i].SetPosition(posP.x + p.GetEntityWidth() / 2 - playerBullets[i].GetEntityWidth() / 2, posP.y + p.GetEntityHeight() / 2 - playerBullets[i].GetEntityHeight());
						playerBullets[i].SetEntityColor(p.GetEntityColor());
						break;
					}
				}

			}

			if (IsKeyPressed(KEY_R)) //Reset enemy just to watch if it changes color
			{
				e = Enemy();
			}

			e.Update();
			
			for (short i = 0; i < PLAYER_BULLETS; i++)
			{
				playerBullets[i].Update();
			}


		}
		void Draw()
		{
			p.Draw();
			for (short i = 0; i < PLAYER_BULLETS; i++)
			{
				playerBullets[i].Draw();
			}
			e.Draw();
		}
		void Deinit();

	}

}