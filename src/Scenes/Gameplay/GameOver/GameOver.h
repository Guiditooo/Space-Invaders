#ifndef GAMEOVER_H
#define GAMEOVER_H

#include "General/Button/Button.h"

namespace game
{
	namespace gameplay
	{

		const int SPACE_BETWEEN_TEXTS = 40;

		extern Button returnToMM; //Back to menu button 
		extern Button restartButton; // Restart Button
		extern Texture2D GORestartButtonTx;//Game Over Restar Button Texture
		extern Texture2D GOMMButtonTx;//Game Over Main Menu Button Texture
		extern Text gameOverTitle;
		extern Text scoreReachedText;
		extern Text levelReachedText;

		void InitGameOver();
		void UpgradeGameOver();
		void DrawGameOver();
		void DeinitGameOver();

		void SetGameOverPositions();

	}
}

#endif // !GAMEOVER_H
