#include "Gameplay.h"
#include <iostream>

namespace game
{

	namespace gameplay
	{

		int level = STARTING_LEVEL;

		Player player;
		Bullet playerBullets[PLAYER_BULLET_COUNT];
		Bullet enemyBullets[ENEMY_BULLET_COUNT];
		Enemy enemy[ENEMY_COUNT];

		void Init()
		{
			ResetEnemies();
			player.SetPosition(static_cast<float>(screen::width / 2 - player.GetEntityWidth() / 2), static_cast<float>(screen::height) - static_cast<float>(100));
		}
		void Update() 
		{
			if (IsKeyPressed(KEY_S))
			{
				player.TurnNextColor();
			}

			if (IsKeyDown(KEY_D))
			{
				player.MoveRight();
			}
			else if (IsKeyDown(KEY_A))
			{
				player.MoveLeft();
			}

			if (IsKeyPressed(KEY_SPACE))
			{

				for (short i = 0; i < PLAYER_BULLET_COUNT; i++)
				{
					if (!playerBullets[i].IsActive())
					{
						playerBullets[i].SetActive();
						Vec2 posP = player.GetPosition();
						playerBullets[i].SetPosition(posP.x + player.GetEntityWidth() / 2 - playerBullets[i].GetEntityWidth() / 2, posP.y + player.GetEntityHeight() / 2 - playerBullets[i].GetEntityHeight());
						playerBullets[i].SetEntityType(player.GetEntityType());
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
 
			player.Draw(); //Player draws second

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
		void Deinit()
		{
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
			CheckEnemyBulletsAgainstPlayer();
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
		void CheckEnemyBulletsAgainstPlayer()
		{

		}
		void Deinit();

	}

}