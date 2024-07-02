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

	rectangleX = entityShape.getPosition().x - 150.0f * dt.asSeconds();
	newPosition = { rectangleX, entityShape.getPosition().y };
	entityShape.setPosition(newPosition);
}