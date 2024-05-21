#include "Obstacle.h"

Obstacle::Obstacle()
{
}

Obstacle::~Obstacle()
{
}

void Obstacle::moveObstacle(Time dt)
{
	Vector2f newPosition;
	float rectangleX;
	float rectangleY;

	rectangleX = position.x - 50.0f * dt.asSeconds();
	newPosition = { rectangleX, position.y };
	entityShape.setPosition(newPosition);
}