#ifndef ENEMY_H
#define ENEMY_H

#include "General/Enitity/Entity.h"

namespace game
{

	namespace enemy
	{
		enum class LateralMove
		{
			TO_LEFT,
			TO_RIGHT
		};
		enum class VerticalMove
		{
			TO_UP,
			TO_DOWN
		};

	}

	using namespace enemy;

	class Enemy : public Entity
	{
	private:
		int enemyID;
		static int enemyCount;
		EntityColor entityColor; // ORANGE / BLUE / LIME / PINK / NONE
		TextureInfo extra;
		VerticalMove VM;
		LateralMove LM;

		void MoveLeft() override;
		void MoveRight() override;
		void MoveUp();
		void MoveDown();

	public:
		Enemy();
		~Enemy();

		void SetEntityType(EntityColor newEntityColor);
		void SetExtraTexture(Texture2D* extraTexture);

		EntityColor GetEntityType();

		void Update() override;
		void Draw() override;

		void Kill();
		void ResetEnemy();
		int GetEnemyID();
		static void ResetEnemyCount();

		void GoLeft();
		void GoRight();
		void GoUp();
		void GoDown();

		LateralMove GetLateralMovement();
		VerticalMove GetVerticalMovement();

	};
}

#endif // !ENEMY_H
