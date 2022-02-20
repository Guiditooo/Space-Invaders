#include "Gameplay.h"

#include <iostream>

#include "General/Button/Button.h"

namespace game
{

	namespace gameplay
	{

		int level = STARTING_LEVEL;

		bool tutorial;
		Text tutorialTitle;
		Text tutorialExit;
		Text tutorialKeys[TUTORIAL_KEYS];
		Text tutorialObjetive1;
		Text tutorialObjetive2;
		Enemy tutorialEnemy[TUTORIAL_COUNT];
		Texture2D tutorialEnemyTX;
		Texture2D tutorialEnemyExtraTX;
		Bullet tutorialBullet[TUTORIAL_COUNT];
		Texture2D tutorialBulletTX;
		Texture2D tutorialBulletExtraTX;
		Player tutorialPlayer[TUTORIAL_COUNT];
		Texture2D tutorialPlayerTX;
		Texture2D tutorialPlayerExtraTX;
		Button tutorialButton;

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

#pragma region TUTORIAL

			tutorial = true;

			tutorialTitle.tx = "TUTORIAL";
			tutorialTitle.color = WHITE;
			tutorialTitle.size = static_cast<float>(screen::width / 100 * 7);
			tutorialTitle.pos.x = static_cast<float>(screen::width/2 - MeasureTextEx(font, &tutorialTitle.tx[0], tutorialTitle.size, TEXT_SPACING).x/2);
			//tutorialTitle.pos.y = static_cast<float>(MeasureTextEx(font, &tutorialTitle.tx[0], tutorialTitle.size, TEXT_SPACING).y/2);
			tutorialTitle.pos.y = 0;

			tutorialExit.tx = "Press A, S, D, P or SPACE to START!";
			tutorialExit.color = WHITE;
			tutorialExit.size = static_cast<float>(screen::width / 100 * 4);
			tutorialExit.pos.x = static_cast<float>(screen::width / 2 - MeasureTextEx(font, &tutorialExit.tx[0], tutorialExit.size, TEXT_SPACING).x / 2);
			//tutorialTitle.pos.y = static_cast<float>(MeasureTextEx(font, &tutorialTitle.tx[0], tutorialTitle.size, TEXT_SPACING).y/2);
			tutorialExit.pos.y = static_cast<float>(screen::height - MeasureTextEx(font, &tutorialTitle.tx[0], tutorialTitle.size, TEXT_SPACING).y);

			tutorialKeys[static_cast<int>(TK::TUTO_A)].tx = "Press A to move left";
			tutorialKeys[static_cast<int>(TK::TUTO_S)].tx = "Press S to switch to next color";
			tutorialKeys[static_cast<int>(TK::TUTO_D)].tx = "Press D to move right";
			tutorialKeys[static_cast<int>(TK::TUTO_P)].tx = "Press P to pause/unpause";
			tutorialKeys[static_cast<int>(TK::TUTO_SPACE)].tx = "Press SPACE to shoot";

			for (short i = 0; i < TUTORIAL_KEYS; i++)
			{
				tutorialKeys[i].color = WHITE;
				tutorialKeys[i].size = static_cast<float>(screen::width / 100 * 4);
				tutorialKeys[i].pos.x = static_cast<float>(screen::width / 20);
				tutorialKeys[i].pos.y = tutorialTitle.pos.y + MeasureTextEx(font, &tutorialTitle.tx[0], tutorialTitle.size, TEXT_SPACING).y + MeasureTextEx(font,&tutorialKeys[i].tx[0],tutorialKeys->size,TEXT_SPACING).y * i;
			}

			tutorialObjetive1.tx = "Objetive: shot coloriens with the same color";
			tutorialObjetive1.color = RED;
			tutorialObjetive1.size = static_cast<float>(screen::width / 100 * 3);
			tutorialObjetive1.pos.x = static_cast<float>(screen::width / 2 - MeasureTextEx(font, &tutorialObjetive1.tx[0], tutorialObjetive1.size, TEXT_SPACING).x / 2);
			//tutorialObjetive.pos.y = static_cast<float>(MeasureTextEx(font, &tutorialObjetive.tx[0], tutorialObjetive.size, TEXT_SPACING).y/2);
			tutorialObjetive1.pos.y = tutorialKeys[static_cast<int>(TK::TUTO_SPACE)].pos.y + MeasureTextEx(font, &tutorialKeys[0].tx[0], tutorialKeys[0].size, TEXT_SPACING).y*5/2;

			tutorialObjetive2.tx = "to get most points on 1 minute.";
			tutorialObjetive2.color = RED;
			tutorialObjetive2.size = static_cast<float>(screen::width / 100 * 3);
			tutorialObjetive2.pos.x = static_cast<float>(screen::width / 2) - MeasureTextEx(font, &tutorialObjetive2.tx[0], tutorialObjetive2.size, TEXT_SPACING).x / 2 + 40;
			//tutorialObjetive.pos.y = static_cast<float>(MeasureTextEx(font, &tutorialObjetive.tx[0], tutorialObjetive.size, TEXT_SPACING).y/2);
			tutorialObjetive2.pos.y = tutorialObjetive1.pos.y + MeasureTextEx(font, &tutorialObjetive1.tx[0], tutorialObjetive1.size, TEXT_SPACING).y;

#pragma region ENEMY

			tutorialEnemyTX = LoadTexture("res/assets/enemy/Alien6.png");
			tutorialEnemyExtraTX = LoadTexture("res/assets/enemy/extra.png");
			tutorialEnemyExtraTX.width = 100;
			tutorialEnemyExtraTX.height = 100;

			for (short i = 0; i < TUTORIAL_COUNT; i++)
			{
				tutorialEnemy[i].SetEntityType(static_cast<EntityColor>(i));
				tutorialEnemy[i].SetTexture(&tutorialEnemyTX);
				tutorialEnemy[i].SetEntityWidth(100.0f);
				tutorialEnemy[i].SetEntityHeight(100.0f);
				tutorialEnemy[i].SetExtraTexture(&tutorialEnemyExtraTX);
				float initialX = (screen::width - tutorialEnemy[i].GetEntityWidth() * TUTORIAL_COUNT) / (TUTORIAL_COUNT + 1);
				tutorialEnemy[i].SetPosition(initialX + (tutorialEnemy[i].GetEntityWidth() + initialX) * i, static_cast<float>(screen::height/2));
			}

#pragma endregion

#pragma region BULLET

			tutorialBulletTX = LoadTexture("res/assets/bullet/Bullet6.png");
			tutorialBulletExtraTX = LoadTexture("res/assets/bullet/extra.png");
			tutorialBulletExtraTX.width = static_cast<int>(bulletWidth*3);
			tutorialBulletExtraTX.height = static_cast<int>(bulletHeight*3);

			for (short i = 0; i < TUTORIAL_COUNT; i++)
			{
				tutorialBullet[i].SetActive();
				tutorialBullet[i].SetEntityType(static_cast<EntityColor>(i));
				tutorialBullet[i].SetTexture(&tutorialBulletTX);
				tutorialBullet[i].SetEntityWidth(bulletWidth * 2);
				tutorialBullet[i].SetEntityHeight(bulletHeight * 2);
				tutorialBullet[i].SetExtraTexture(&tutorialBulletExtraTX);
				tutorialBullet[i].SetPosition(tutorialEnemy[i].GetPosition().x + tutorialEnemy[i].GetEntityWidth() / 2 - tutorialBullet[i].GetEntityWidth() / 2, tutorialEnemy[i].GetPosition().y + tutorialEnemy[i].GetEntityHeight() + 50.0f);
			}
#pragma endregion

#pragma region PLAYER

			tutorialPlayerTX = LoadTexture("res/assets/player/Starship7.png");
			tutorialPlayerExtraTX = LoadTexture("res/assets/player/extra.png");
			tutorialPlayerExtraTX.width = static_cast<int>(entityWidth / 65 * 100);
			tutorialPlayerExtraTX.height = static_cast<int>(entityWidth);

			for (short i = 0; i < TUTORIAL_COUNT; i++)
			{
				tutorialPlayer[i].SetEntityType(static_cast<EntityColor>(i));
				tutorialPlayer[i].SetTexture(&tutorialPlayerTX);
				tutorialPlayer[i].SetEntityWidth(entityWidth / 65 * 100);
				tutorialPlayer[i].SetEntityHeight(entityWidth);
				tutorialPlayer[i].SetExtraTexture(&tutorialPlayerExtraTX);
				tutorialPlayer[i].SetPosition(tutorialEnemy[i].GetPosition().x + tutorialEnemy[i].GetEntityWidth() / 2 - tutorialPlayer[i].GetEntityWidth() / 2, tutorialBullet[i].GetPosition().y + tutorialBullet[i].GetEntityHeight() + 50.0f);
			}
#pragma endregion

#pragma endregion

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

			if (IsKeyPressed(KEY_ESCAPE))
			{
				scene::nextScene = scene::SceneList::MENU;
			}

			if (tutorial)
			{
				if (IsKeyPressed(KEY_SPACE) || IsKeyPressed(KEY_A) || IsKeyPressed(KEY_S) || IsKeyPressed(KEY_D) || IsKeyPressed(KEY_P))
				{
					tutorial = false;
				}
			}
			else
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

				if (IsKeyPressed(KEY_P))
				{
					paused = !paused;
				}

			}

		}
		void Draw()
		{

			if (tutorial)
			{
				DrawTextEx(font, &tutorialTitle.tx[0], tutorialTitle.pos.ToVector2(), tutorialTitle.size, TEXT_SPACING, tutorialTitle.color);
				
				for (short i = 0; i < TUTORIAL_KEYS; i++)
				{
					DrawTextEx(font, &tutorialKeys[i].tx[0], tutorialKeys[i].pos.ToVector2(), tutorialKeys[i].size, TEXT_SPACING, tutorialKeys[i].color);
				}

				DrawTextEx(font, &tutorialObjetive1.tx[0], tutorialObjetive1.pos.ToVector2(), tutorialObjetive1.size, TEXT_SPACING, tutorialObjetive1.color);

				DrawTextEx(font, &tutorialObjetive2.tx[0], tutorialObjetive2.pos.ToVector2(), tutorialObjetive2.size, TEXT_SPACING, tutorialObjetive2.color);
				
				for (short i = 0; i < TUTORIAL_COUNT; i++)
				{
					tutorialEnemy[i].Draw();
					tutorialBullet[i].Draw();
					tutorialPlayer[i].Draw();
				}

				DrawTextEx(font, &tutorialExit.tx[0], tutorialExit.pos.ToVector2(), tutorialExit.size, TEXT_SPACING, tutorialExit.color);
			}
			else
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

		}
		void Deinit()
		{
			UnloadTexture(pauseBackgroundTX);
			for (short i = 0; i < PLAYER_BULLET_COUNT; i++)
			{
				if(playerBullets[i].IsActive())	playerBullets[i].SetInactive();
			}
			UnloadTexture(tutorialEnemyTX);
			UnloadTexture(tutorialEnemyExtraTX);
			UnloadTexture(tutorialPlayerTX);
			UnloadTexture(tutorialPlayerExtraTX);
			UnloadTexture(tutorialBulletTX);
			UnloadTexture(tutorialBulletExtraTX);
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