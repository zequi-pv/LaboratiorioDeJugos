#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>
#include "game.h"
#include "utils.h"

using namespace sf;

void Game::runGame() 
{
    RenderWindow window(sf::VideoMode(854, 480), "Labo de jugos");
    //CircleShape shape(100.f);
    RectangleShape rectangle;
    RectangleShape ground;
    Keyboard keyboard;
    Time dt;
    Clock clock;
    float rectangleX = (GetScreenWidth() / 2 - 350);
    float rectangleY = (GetScreenHeight() / 2) + 60;
    rectangle.setSize(Vector2f(200,100));
    rectangle.setFillColor(Color::Green);
    rectangle.setPosition(rectangleX, rectangleY);
    ground.setSize(Vector2f(854, 100));
    ground.setFillColor(Color::White);
    ground.setPosition(0,400);
    bool isJumping = false;

    //shape.setFillColor(Color::Green);

    while (window.isOpen())
    {
        dt = clock.restart();

        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        if (keyboard.isKeyPressed(Keyboard::D))
        {
            rectangleX += 50 * dt.asSeconds();
            rectangle.setPosition(rectangleX, rectangleY);
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

        window.clear();
        //window.draw(shape);
        window.draw(rectangle);
        window.draw(ground);
        window.display();
    }
}

Game::Game()
{
}

Game::~Game()
{
}