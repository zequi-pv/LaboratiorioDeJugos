#include "Player.h"

Player::Player()
{
}

Player::~Player()
{
}

void Player::movePlayer(Player& player, Time dt)
{
    Keyboard keyboard;

    if (keyboard.isKeyPressed(Keyboard::D))
    {
        player.getPosition().x += 50 * dt.asSeconds();
        player.setPosition(rectangleX, rectangleY);
    }

    if (keyboard.isKeyPressed(Keyboard::W))
    {
        rectangleY -= 50 * dt.asSeconds();
        rectangle.setPosition(rectangleX, rectangleY);
        isJumping = true;
    }

    if (keyboard.isKeyPressed(Keyboard::A))
    {
        rectangleX -= 50 * dt.asSeconds();
        rectangle.setPosition(rectangleX, rectangleY);
    }

    if (keyboard.isKeyPressed(Keyboard::S))
    {
        rectangleY += 50 * dt.asSeconds();
        rectangle.setPosition(rectangleX, rectangleY);
    }
}

void Player::drawPlayer()
{
	
}