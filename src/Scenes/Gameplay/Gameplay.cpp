#include "Gameplay.h"

namespace game
{

	namespace gameplay
	{
		Player p;
		Bullet playerBullets[PLAYER_BULLET_COUNT];
		Enemy enemy[ENEMY_COUNT];

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

				for (short i = 0; i < PLAYER_BULLET_COUNT; i++)
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
				ResetEnemies();
			}

			CheckCollitions();

			for (short i = 0; i < ENEMY_COUNT; i++)
			{
				if (enemy[i].IsActive())
				{
					enemy[i].Update();
				}
			}
			
			for (short i = 0; i < PLAYER_BULLET_COUNT; i++)
			{
				playerBullets[i].Update();
			}


		}
		void Draw()
		{
			//Background (with parallax included) draws first at all
 
			p.Draw(); //Player draws second

			for (short i = 0; i < ENEMY_COUNT; i++) //Enemy draws second
			{
				enemy[i].Draw();
			}

			//Enemy Bullets draws third #ONGOING

			for (short i = 0; i < PLAYER_BULLET_COUNT; i++) //Player bullets draws at last
			{
				playerBullets[i].Draw();
			}
		}
		void ResetEnemies()
		{
			enemy->ResetEnemyCount();
			for (short i = 0; i < ENEMY_COUNT; i++)
			{
				enemy[i] = Enemy();
			}
		}

		void CheckCollitions()
		{
			CheckPlayerBulletsAgainstEnemies();
		}

		void CheckPlayerBulletsAgainstEnemies()
		{
			for (short i = 0; i < PLAYER_BULLET_COUNT; i++)
			{
				if (playerBullets[i].IsActive())
				{
					for (short j = 0; j < ENEMY_COUNT; j++)
					{
						if (enemy[j].IsActive())
						{
							if (CheckCollisionRecs(playerBullets[i].GetRectangle(), enemy[j].GetRectangle()))
							{
								
								if (playerBullets[i].GetEntityType() == enemy[j].GetEntityType())
								{
									enemy[j].Kill();
								}

								playerBullets[i].SetInactive();

							}
						}
					}
				}
			}
		}
		void Deinit();

	}

}