#ifndef BULLET_H
#define BULLET_H

#include "General/Enitity/Entity.h"

namespace game
{

	class Bullet : public Entity
	{
	private:
		BulletType type;

	public:
		Bullet();
		Bullet(BulletType newBulletType, Color newColor);
		~Bullet();
		void Update() override;
	};

}

#endif // !BULLET_H
