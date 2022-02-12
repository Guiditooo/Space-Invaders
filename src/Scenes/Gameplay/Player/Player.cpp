#include "Player.h"

namespace game {

	Player::Player()
	{
		SetActive();
		this->SetEntityType(static_cast<EntityType>(0));
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
	
}
