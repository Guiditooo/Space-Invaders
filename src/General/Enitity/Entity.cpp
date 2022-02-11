#include "Entity.h"

namespace game
{
	
	game::Entity::Entity()
	{
		pos.x = static_cast<float>(screen::width) / 2;
		pos.y = 0;
		width = 100;
		height = 100;
		type = EntityType::ENTITY_ORANGE; // BLACK OR WHITE OR NONE
		color = ORANGE;
		texture = nullptr;
		active = false;
	}

	game::Entity::~Entity()
	{

	}



	void game::Entity::SetPosition(Vec2 newPos)
	{
		pos = newPos;
	}

	void Entity::SetPosition(float x, float y)
	{
		pos.x = x;
		pos.y = y;
	}

	void game::Entity::SetEntityType(EntityType newType)
	{
		type = newType;
	}

	void game::Entity::SetEntityWidth(float newWidth)
	{
		width = newWidth;
		if (texture != nullptr) texture->width = static_cast<int>(newWidth);

	}

	void game::Entity::SetEntityHeight(float newHeight)
	{
		height = newHeight;
		if (texture != nullptr) texture->height = static_cast<int>(newHeight);
	}

	void Entity::SetEntityColor(Color newColor)
	{
		color = newColor;
	}

	void Entity::NextColor()
	{
		type = static_cast<EntityType>(static_cast<int>(type) + 1);
		if (type == EntityType::NONE)
		{
			type = static_cast<EntityType>(0);
		}

		switch (type)
		{
		case game::EntityType::ENTITY_ORANGE:
			color = ORANGE;
			break;
		case game::EntityType::ENTITY_CYAN:
			color = SKYBLUE;
			break;
		case game::EntityType::ENTITY_LIME:
			color = LIME;
			break;
		case game::EntityType::ENTITY_PINK:
			color = PINK;
			break;
		case game::EntityType::NONE:
			color = WHITE;
			break;
		default:
			break;
		}

	}

	void game::Entity::SetTexture(Texture2D* newTexture)
	{
		texture = newTexture;
		texture->width = static_cast<int>(width);
		texture->height = static_cast<int>(height);
	}

	void Entity::SetActive()
	{
		active = true;
	}

	void Entity::SetInactive()
	{
		active = false;
	}

	Vec2 game::Entity::GetPosition()
	{
		return pos;
	}

	EntityType game::Entity::GetEntityType()
	{
		return type;
	}

	float game::Entity::GetEntityWidth()
	{
		return width;
	}

	float game::Entity::GetEntityHeight()
	{
		return height;
	}

	Color Entity::GetEntityColor()
	{
		return color;
	}

	Texture2D* game::Entity::GetTexture()
	{
		return texture;
	}

	bool Entity::IsActive()
	{
		return active;
	}

	void game::Entity::Draw()
	{
		if (IsActive())
		{
			if (texture != nullptr)
			{
				DrawTexture(*texture, static_cast<int>(pos.x), static_cast<int>(pos.y), color);
			}
			else
			{
				DrawRectangle(static_cast<int>(pos.x), static_cast<int>(pos.y), static_cast<int>(width), static_cast<int>(height), color);
			}
		}
	}

	void Entity::MoveLeft()
	{
		Vec2 p = this->GetPosition();
		this->SetPosition(p.x - gameplay::horizontalSpeed, p.y);
	}
	void Entity::MoveRight()
	{
		Vec2 p = this->GetPosition();
		this->SetPosition(p.x + gameplay::horizontalSpeed, p.y);
	}

}