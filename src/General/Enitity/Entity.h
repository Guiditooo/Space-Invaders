#ifndef ENTITY_H
#define ENTITY_H

#include "General/Vec2/vec2.h"
#include "General/Extern/Extern.h"

namespace game
{

	class Entity
	{
	private:
		Vec2 pos; // POSITION X,Y
		float width;
		float height;
		EntityType type; // ORANGE / BLUE / LIME / PINK
		Texture2D* texture;
		Color color;
		bool active;
	protected:
		void NextColor();

	public:
		Entity(); // WORKS AS INIT
		~Entity(); // WORKS AS DEINIT

		void SetPosition(Vec2 newPos);
		void SetPosition(float x, float y);
		void SetEntityType(EntityType newType);
		void SetEntityWidth(float newWidth);
		void SetEntityHeight(float newHeight);
		void SetEntityColor(Color newColor);
		void SetTexture(Texture2D* newTexture);
		void SetActive();
		void SetInactive();

		Vec2 GetPosition();
		EntityType GetEntityType();
		float GetEntityWidth();
		float GetEntityHeight();
		Color GetEntityColor();
		Texture2D* GetTexture();
		bool IsActive();

		void Draw(); //ALL ENTITIES WILL DRAW ITS UNIQUE TEXTURE IN THEIR POSITION (ALSO, IN DEBUG WILL SHOW THE HITBOX)
		virtual void Update() = 0; // EVERY ENTITY WILL UPGRADE BY DIFFERENT WAYS

		void MoveLeft();
		void MoveRight();

	};
}
#endif // !ENTITY_H