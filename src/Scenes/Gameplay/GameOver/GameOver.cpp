#include "GameOver.h"

namespace game
{
	namespace gameplay
	{

		Button returnToMM; //Back to menu button 
		Button restartButton; // Restart Button
		Texture2D GORestartButtonTx;//Game Over Restar Button Texture
		Texture2D GOMMButtonTx;//Game Over Main Menu Button TextureText gameOverTitle;
		Text gameOverTitle;
		Text scoreReachedText;
		Text levelReachedText;

		void InitGameOver()
		{

			gameOverTitle.size = static_cast<float>(screen::width) / 100 * 7;
			gameOverTitle.color = COLOR;
			
			scoreReachedText.size = COMPLETE_TITLE_SIZE;
			scoreReachedText.color = COLOR;
						
			levelReachedText.size = COMPLETE_TITLE_SIZE;
			levelReachedText.color = COLOR;
			
			SetGameOverPositions();

			GOMMButtonTx = LoadTexture("res/assets/button/Button.png");
			GORestartButtonTx = LoadTexture("res/assets/button/Button.png");

			restartButton.SetTexture(&GORestartButtonTx);
			restartButton.SetTextText(" Restart Game ");
			restartButton.SetTextSize(GUI_SIZE);
			restartButton.SetTextAlignement(txt::Alignement::CENTER_MID);
			restartButton.SetTextColor(COLOR);
			restartButton.SetEntityWidth(MeasureTextEx(font, &restartButton.GetText().tx[0], GUI_SIZE, TEXT_SPACING).x);
			restartButton.SetEntityHeight(MeasureTextEx(font, &restartButton.GetText().tx[0], GUI_SIZE, TEXT_SPACING).y * 1.5f);
			restartButton.SetSceneToCharge(scene::SceneList::NONE);
			restartButton.SetPosition(static_cast<float>(screen::width * 28 / 100) - restartButton.GetEntityWidth() / 2, screen::height / 2 + MeasureTextEx(font, &restartButton.GetText().tx[0], GUI_SIZE, TEXT_SPACING).y * 3);

			returnToMM.SetTexture(&GOMMButtonTx);
			returnToMM.SetTextText(" Main Menu ");
			returnToMM.SetTextSize(GUI_SIZE);
			returnToMM.SetTextAlignement(txt::Alignement::CENTER_MID);
			returnToMM.SetTextColor(COLOR);
			returnToMM.SetEntityWidth(restartButton.GetEntityWidth());
			returnToMM.SetEntityHeight(restartButton.GetEntityHeight());
			returnToMM.SetSceneToCharge(scene::SceneList::MENU);
			returnToMM.SetPosition(static_cast<float>(screen::width * 72 / 100) - returnToMM.GetEntityWidth() / 2, restartButton.GetPosition().y);
		
			
		}

		void UpgradeGameOver()
		{
			returnToMM.Update();
			restartButton.Update();
		}

		void DrawGameOver()
		{
				
			DrawTextEx(font, &gameOverTitle.tx[0], gameOverTitle.pos.ToVector2(), gameOverTitle.size, TEXT_SPACING, gameOverTitle.color);
			DrawTextEx(font, &scoreReachedText.tx[0], scoreReachedText.pos.ToVector2(), scoreReachedText.size, TEXT_SPACING, scoreReachedText.color);
			DrawTextEx(font, &levelReachedText.tx[0], levelReachedText.pos.ToVector2(), levelReachedText.size, TEXT_SPACING, levelReachedText.color);
							

			returnToMM.Draw();
			restartButton.Draw();
		}

		void DeinitGameOver()
		{
			UnloadTexture(GOMMButtonTx);
			UnloadTexture(GORestartButtonTx);
		}

		void SetGameOverPositions()
		{
			gameOverTitle.tx = "GAME OVER";
			gameOverTitle.pos.x = static_cast<float>(screen::width) / 2 - MeasureTextEx(font, &gameOverTitle.tx[0], gameOverTitle.size, TEXT_SPACING).x / 2;
			gameOverTitle.pos.y = static_cast<float>(screen::height) / 4;

			scoreReachedText.tx = "Score:  " + std::to_string(score);
			scoreReachedText.pos.x = static_cast<float>(screen::width) / 2 - MeasureTextEx(font, &scoreReachedText.tx[0], scoreReachedText.size, TEXT_SPACING).x / 2;
			scoreReachedText.pos.y = gameOverTitle.pos.y + MeasureTextEx(font, &gameOverTitle.tx[0], gameOverTitle.size, TEXT_SPACING).y + SPACE_BETWEEN_TEXTS;

			levelReachedText.tx = "Level Reached:  " + std::to_string(level);
			levelReachedText.pos.x = static_cast<float>(screen::width) / 2 - MeasureTextEx(font, &levelReachedText.tx[0], levelReachedText.size, TEXT_SPACING).x / 2;
			levelReachedText.pos.y = scoreReachedText.pos.y + MeasureTextEx(font, &scoreReachedText.tx[0], scoreReachedText.size, TEXT_SPACING).y + SPACE_BETWEEN_TEXTS;
		}

	}

}