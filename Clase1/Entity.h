#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Entity
{
public:
	Entity();
	~Entity();
	Vector2f getSize();
	void setSize(Vector2f newSize);
	Vector2f getPosition();
	void setPosition(Vector2f newPosition);
	void setTexture(Texture newTexture);
private:
	
protected:
	Vector2f size;
	Vector2f position;
	Texture texEntity;
};