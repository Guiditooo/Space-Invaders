#ifndef PLAYER_H
#define PLAYER_H

#include "General/Enitity/Entity.h"

namespace game
{
	class Player : public Entity
 	{
	private:
		
	public:
		Player();
		~Player();
		void Update() override;
		void TurnNextColor();
	};
}

#endif // !PLAYER_H
