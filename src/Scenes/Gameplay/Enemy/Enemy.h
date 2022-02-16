#ifndef ENEMY_H
#define ENEMY_H

#include "General/Enitity/Entity.h"

namespace game
{
	class Enemy : public Entity
	{
	private:
		int enemyID;
		static int enemyCount;
		EntityColor entityColor; // ORANGE / BLUE / LIME / PINK / NONE
		TextureInfo extra;
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

	};
}

#endif // !ENEMY_H
