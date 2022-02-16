#include "Player.h"

namespace game {

	Player::Player()
	{
		SetActive();
		this->SetEntityType(static_cast<EntityColor>(0));

		this->SetTexture(&gameplay::playerTexture);

		entityColor = EntityColor::NONE;
		TurnNextColor();
	}
	Player::~Player() 
	{

	}

	void Player::Update()
	{
		
	}
	void Player::TurnNextColor()
	{
		NextColor();
	}

	EntityColor Player::GetEntityType()
	{
		return entityColor;
	}

	void Player::SetEntityType(EntityColor newEntityColor)
	{
		entityColor = newEntityColor;

		switch (newEntityColor)
		{
		case game::EntityColor::ENTITY_ORANGE:
			color = ORANGE;
			break;
		case game::EntityColor::ENTITY_CYAN:
			color = SKYBLUE;
			break;
		case game::EntityColor::ENTITY_LIME:
			color = LIME;
			break;
		case game::EntityColor::ENTITY_PINK:
			color = PINK;
			break;
		case game::EntityColor::NONE:
			color = WHITE;
			break;
		default:
			break;
		}
	}

	void Player::SetExtraTexture(Texture2D* extraTexture)
	{
		extra.texture = extraTexture;
	}

	void Player::NextColor()
	{
		entityColor = static_cast<EntityColor>(static_cast<int>(entityColor) + 1);
		if (static_cast<int>(entityColor) >= static_cast<int>(EntityColor::NONE))
		{
			entityColor = static_cast<EntityColor>(0);
		}

		switch (entityColor)
		{
		case game::EntityColor::ENTITY_ORANGE:
			color = ORANGE;
			break;
		case game::EntityColor::ENTITY_CYAN:
			color = SKYBLUE;
			break;
		case game::EntityColor::ENTITY_LIME:
			color = LIME;
			break;
		case game::EntityColor::ENTITY_PINK:
			color = PINK;
			break;
		case game::EntityColor::NONE:
			color = WHITE;
			break;
		default:
			break;
		}

	}
	
}
