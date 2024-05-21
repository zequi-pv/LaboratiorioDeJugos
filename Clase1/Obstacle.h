#pragma once
#include <iostream>
#include "Entity.h"

using namespace std;

class Obstacle : public Entity
{
public:
	Obstacle();
	~Obstacle();
	void moveObstacle(Time dt);
private:

};

