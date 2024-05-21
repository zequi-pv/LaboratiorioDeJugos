#pragma once
#include "Entity.h"
#include "utils.h" 
#include <iostream>

using namespace std;

class Player : public Entity
{
public:
	Player();
	~Player();
	void movePlayer(Time dt);
	void drawPlayer();
	void setGravity(float newGravity);
private:

protected:
	int score;
	Vector2f speed;
	Vector2f acceleration;
	float gravity;
	bool isJumping;
};