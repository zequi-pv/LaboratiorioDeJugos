#include "Entity.h"

Entity::Entity()
{
}

Entity::~Entity()
{
}

Vector2f Entity::getSize()
{
	return size;
}

void Entity::setSize(Vector2f newSize)
{
	size = newSize;
	entityShape.setSize(newSize);
}

RectangleShape* Entity::getShape()
{
	return &entityShape;
}

//Vector2f Entity::getPosition()
//{
//	return position;
//}
//
//void Entity::setPosition(Vector2f newPosition)
//{
//	position = newPosition;
//	entityShape.setPosition(position.x, position.y);
//}

void Entity::setTexture(Texture newTexture)
{
	texEntity = newTexture;
}