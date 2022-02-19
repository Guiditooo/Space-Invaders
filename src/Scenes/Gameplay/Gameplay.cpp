#include "Gameplay.h"

#include <iostream>

#include "General/Button/Button.h"

namespace game
{

	namespace gameplay
	{

		int level = STARTING_LEVEL;

		Player player;
		Bullet playerBullets[PLAYER_BULLET_COUNT];
		Bullet enemyBullets[ENEMY_BULLET_COUNT];
		Enemy enemy[ENEMY_COUNT];

		bool paused;
		TextureInfo pauseBackground;
		Texture2D pauseBackgroundTX;
		Text pauseTitle;
		Text pauseText;
		Button pauseButton;

		void Init()
		{
			paused = false;

			pauseTitle.tx = "PAUSED";
			pauseTitle.size = static_cast<float>(screen::width / 100 * 7);
			pauseTitle.color = RAYWHITE;
			pauseTitle.pos = Vec2(screen::width/2 - MeasureTextEx(font,&pauseTitle.tx[0],pauseTitle.size,TEXT_SPACING).x / 2, screen::height / 2 - MeasureTextEx(font, &pauseTitle.tx[0], pauseTitle.size, TEXT_SPACING).y * 2);

			pauseText.tx = "P to Unpause";
			pauseText.size = static_cast<float>(screen::width / 25);
			pauseText.color = RAYWHITE;
			pauseText.pos = Vec2(screen::width / 2 - MeasureTextEx(font, &pauseText.tx[0], pauseText.size, TEXT_SPACING).x / 2, screen::height / 2 - MeasureTextEx(font, &pauseText.tx[0], pauseText.size, TEXT_SPACING).y * 1.65f);

			pauseButton.SetTexture(&button::buttonTexture);
			pauseButton.SetTextText("MAIN MENU");
			pauseButton.SetTextSize(static_cast<float>(screen::width / 20));
			pauseButton.SetTextAlignement(txt::Alignement::CENTER_MID);
			pauseButton.SetEntityHeight(MeasureTextEx(font, "MAIN MENU", static_cast<float>(screen::width / 25), TEXT_SPACING).y*2);
			pauseButton.SetEntityWidth(MeasureTextEx(font, "MAIN MENU", static_cast<float>(screen::width / 25), TEXT_SPACING).x + pauseButton.GetEntityHeight()*3/2);
			pauseButton.SetPosition(screen::width / 2 - pauseButton.GetEntityWidth() / 2, static_cast<float>(screen::height / 2) );
			pauseButton.SetSceneToCharge(scene::SceneList::MENU);
			pauseButton.SetTextColor(RAYWHITE);

			pauseBackgroundTX = LoadTexture("res/assets/button/Button.png");
			pauseBackground.texture = &pauseBackgroundTX;
			pauseBackground.texture->height = static_cast<int>((pauseButton.GetPosition().y - pauseTitle.pos.y)*2);
			pauseBackground.texture->width = static_cast<int>(screen::width / 2);
			pauseBackground.position.x = static_cast<float>(screen::width / 2 - pauseBackground.texture->width / 2);
			pauseBackground.position.y = static_cast<float>(screen::height / 2 - static_cast<float>(pauseBackground.texture->height) / (1.72f));
			pauseBackground.color = WHITE;


			ResetEnemies();
			player.SetPosition(static_cast<float>(screen::width / 2 - player.GetEntityWidth() / 2), static_cast<float>(screen::height) - static_cast<float>(100));
		}
		void Update() 
		{
			if (!paused)
			{
				if (IsKeyPressed(KEY_S))
				{
					player.TurnNextColor();
				}

				if (IsKeyDown(KEY_D))
				{
					if (player.GetPosition().x + player.GetEntityWidth() < screen::width) player.MoveRight();
				}
				else if (IsKeyDown(KEY_A))
				{
					if (player.GetPosition().x > 0) player.MoveLeft();
				}

				if (IsKeyPressed(KEY_SPACE))
				{

					for (short i = 0; i < PLAYER_BULLET_COUNT; i++)
					{
						if (!playerBullets[i].IsActive())
						{
							playerBullets[i].SetActive();
							Vec2 posP = player.GetPosition();
							playerBullets[i].SetPosition(posP.x + player.GetEntityWidth() / 2 - playerBullets[i].GetEntityWidth() / 3, posP.y + player.GetEntityHeight() / 2 - playerBullets[i].GetEntityHeight());
							playerBullets[i].SetEntityType(player.GetEntityType());
							break;
						}
					}
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
			else
			{
				pauseButton.Update();
			}

			if (IsKeyReleased(KEY_ESCAPE) || IsKeyPressed(KEY_P))
			{
				paused = !paused;
			}

		}
		void Draw()
		{
			//Background (with parallax included) draws first at all
 
			for (short i = 0; i < PLAYER_BULLET_COUNT; i++) //Player bullets draws second
			{
				playerBullets[i].Draw();
			}

			player.Draw(); //Player draws third
			
			//Enemy Bullets draws before enemies #ONGOING

			for (short i = 0; i < ENEMY_COUNT; i++) //Enemy draws after player
			{
				enemy[i].Draw();
			}
			
			if (paused)
			{
				DrawTexture(*pauseBackground.texture, static_cast<int>(pauseBackground.position.x), static_cast<int>(pauseBackground.position.y), pauseBackground.color);
				DrawTextEx(font, &pauseTitle.tx[0], pauseTitle.pos.ToVector2(), pauseTitle.size, TEXT_SPACING, pauseTitle.color);
				DrawTextEx(font, &pauseText.tx[0], pauseText.pos.ToVector2(), pauseText.size, TEXT_SPACING, pauseText.color);
				pauseButton.Draw();
			}


		}
		void Deinit()
		{
			UnloadTexture(pauseBackgroundTX);
			for (short i = 0; i < PLAYER_BULLET_COUNT; i++)
			{
				if(playerBullets[i].IsActive())	playerBullets[i].SetInactive();
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

	}

}