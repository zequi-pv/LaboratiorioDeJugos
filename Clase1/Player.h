#pragma once
#include "Entity.h"
#include <iostream>

using namespace std;

class Player : public Entity
{
public:
	Player();
	~Player();
	void movePlayer(Time dt);
	void drawPlayer();
private:

protected:
	int score;
	float speed;
	float acceleration;
	float gravity;
	bool isJumping;
};