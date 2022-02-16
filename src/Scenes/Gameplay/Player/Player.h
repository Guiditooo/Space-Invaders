#ifndef PLAYER_H
#define PLAYER_H

#include "General/Enitity/Entity.h"

namespace game
{
	class Player : public Entity
 	{
	private:
		EntityColor entityColor; // ORANGE / BLUE / LIME / PINK / NONE
		TextureInfo extra;
	public:
		Player();
		~Player();

		void SetEntityType(EntityColor newEntityColor);
		void SetExtraTexture(Texture2D* extraTexture);

		EntityColor GetEntityType();

		void Update() override;
		void TurnNextColor();
		void NextColor();
	};
}

#endif // !PLAYER_H
