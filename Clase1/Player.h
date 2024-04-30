#pragma once
#include "Entity.h"

class Player : public Entity
{
public:
	Player();
	~Player();
	void movePlayer();
	void drawPlayer();
private:

protected:
	int score;
	float speed;
	float gravity;
	bool isJumping;
};