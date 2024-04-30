#pragma once
#include "Entity.h"

class Player : public Entity
{
public:
	Player();
	~Player();

private:

protected:
	int score;
	float speed;
	bool isJumping;
};

Player::Player()
{
}

Player::~Player()
{
}