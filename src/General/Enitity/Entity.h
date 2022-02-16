#ifndef ENTITY_H
#define ENTITY_H

#include "General/Vec2/vec2.h"
#include "General/Extern/Extern.h"

namespace game
{

	class Entity
	{
	private:
		bool active;
	protected:
		Color color;
		EntityType type;
		Texture2D* texture;
		Vec2 pos; // POSITION X,Y
		float width;
		float height;
	public:
		Entity(); // WORKS AS INIT
		~Entity(); // WORKS AS DEINIT

		void SetPosition(Vec2 newPos);
		void SetPosition(float x, float y);
		void SetEntityWidth(float newWidth);
		void SetEntityHeight(float newHeight);
		void SetEntityColor(Color newColor);
		void SetEntityType(EntityType newType);
		void SetTexture(Texture2D* newTexture);
		void SetActive();
		void SetInactive();

		Vec2 GetPosition();
		float GetEntityWidth();
		float GetEntityHeight();
		Color GetEntityColor();
		Texture2D* GetTexture();
		Rectangle GetRectangle();
		EntityType GetEntityType();
		bool IsActive();

		virtual void Draw(); //ALL ENTITIES WILL DRAW ITS UNIQUE TEXTURE IN THEIR POSITION (ALSO, IN DEBUG WILL SHOW THE HITBOX)
		virtual void Update() = 0; // EVERY ENTITY WILL UPGRADE BY DIFFERENT WAYS

		void MoveLeft();
		void MoveRight();

	};
}
#endif // !ENTITY_H