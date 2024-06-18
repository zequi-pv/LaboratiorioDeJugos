#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Button
{
public:
	Button();
	~Button();

private:
	RenderWindow window;
	Font font;
	Texture texture;
	Sprite background;
	Text text;
};

Button::Button()
{

}

Button::~Button()
{
}