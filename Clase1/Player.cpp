#include "Player.h"

Player::Player()
{
    speed = { 0.0f,100.0f };
    acceleration.x = 0.0f;
    acceleration.y = 0.0f;
    isJumping = false;
}

Player::~Player()
{
}

void Player::movePlayer(Time dt)
{
    Keyboard keyboard;
    Vector2f newPosition;
    float rectangleX;
    float rectangleY;

    /*if (keyboard.isKeyPressed(Keyboard::D))
    {
        rectangleX = position.x + 50.0f * dt.asSeconds();
        newPosition = { rectangleX, position.y };
        position = newPosition;
        entityShape.setPosition(newPosition); 
        cout << newPosition.x << endl;
    }*/
    float posX = entityShape.getPosition().x;
    float posY = entityShape.getPosition().y;

    if (keyboard.isKeyPressed(Keyboard::W))
    {

        posY -= speed.y * dt.asSeconds();

        entityShape.setPosition(posX, posY);
        isJumping = true;
        
        cout << "Salto" << endl;   
        /*acceleration.y = 0.0f;
        speed = gravity / 2;
        rectangleY = position.y - 50 * dt.asSeconds();
        newPosition = { position.x, rectangleY };
        position = newPosition;
        entityShape.setPosition(newPosition);*/

        /*speed.y = -10;

        if (position.y < 100)
        {
            speed.y += gravity;
        }
        else if (position.y > 100)
        {
            position.y = (GetScreenHeight() / 2) + 60;
        }*/

        /*speed.x += acceleration.x;
        speed.y += acceleration.y;

        position.x += speed.x;
        position.y += speed.y;*/

       /* Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                isJumping = true;
        }*/
        //rectangleY = position.y * -9.81 * dt.asSeconds();
        
        
    }

    if (isJumping == true)
    {
        posY += gravity * dt.asSeconds();
        entityShape.setPosition(posX, posY);
        cout << gravity << endl;

        if (posY >= 400)
        {
            isJumping = false;
        }
    }

    /*if (keyboard.isKeyPressed(Keyboard::A))
    {
        rectangleX = position.x - 50 * dt.asSeconds();
        newPosition = { rectangleX, position.y };
        position = newPosition;
        entityShape.setPosition(newPosition);
    }

    if (keyboard.isKeyPressed(Keyboard::S))
    {
        rectangleY = position.y + 50 * dt.asSeconds();
        newPosition = { position.x, rectangleY };
        position = newPosition;
        entityShape.setPosition(newPosition);
    }*/
}

bool Player::getIsAlive()
{
    return isAlive;
}

void Player::playerHit()
{
    isAlive = false;
}

void Player::setGravity(float newGravity)
{
    gravity = newGravity;
}

void Player::drawPlayer()
{
	
}