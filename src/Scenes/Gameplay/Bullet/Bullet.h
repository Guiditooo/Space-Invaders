#ifndef BULLET_H
#define BULLET_H

#include "General/Enitity/Entity.h"

namespace game
{

	class Bullet : public Entity
	{
	private:
		gameplay::BulletType bulletType;
		EntityColor entityColor; // ORANGE / BLUE / LIME / PINK / NONE
		TextureInfo extra;
	public:
		Bullet();
		Bullet(gameplay::BulletType newBulletType, Color newColor);
		~Bullet();
		void Update() override;

		void SetEntityType(EntityColor newEntityColor);
		void SetExtraTexture(Texture2D* extraTexture);

		EntityColor GetEntityType();
	};

}

#endif // !BULLET_H
