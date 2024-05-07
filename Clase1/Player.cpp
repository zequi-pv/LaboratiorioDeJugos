#include "Player.h"

Player::Player()
{
    speed = 0.0f;
    acceleration = 0.0f;
    gravity = 200.0f;
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

    if (keyboard.isKeyPressed(Keyboard::D))
    {
        rectangleX = position.x + 50.0f * dt.asSeconds();
        newPosition = { rectangleX, position.y };
        position = newPosition;
        entityShape.setPosition(newPosition); 
        cout << newPosition.x << endl;
    }

    if (keyboard.isKeyPressed(Keyboard::W))
    {
        acceleration = 0.0f;
        speed = gravity / 2;
        rectangleY = position.y - 50 * dt.asSeconds();
        newPosition = { position.x, rectangleY };
        position = newPosition;
        entityShape.setPosition(newPosition);

        

       /* Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                isJumping = true;
        }*/
        //rectangleY = position.y * -9.81 * dt.asSeconds();
        
        
    }
    else
    {
        if (true)
        {

        }

        acceleration += gravity * dt.asSeconds();
        speed -= acceleration * dt.asSeconds();
        position.y -= speed * dt.asSeconds();
    }

    if (keyboard.isKeyPressed(Keyboard::A))
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
    }
}

void Player::drawPlayer()
{
	
}