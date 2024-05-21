#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>
#include "game.h"
#include "utils.h"
#include "Player.h"
#include "Obstacle.h"

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

    Player player;
    player.setSize(Vector2f(200, 100));
    player.getShape()->setPosition(Vector2f(rectangleX, rectangleY));
    player.getShape()->setFillColor(Color::Green);
    player.setGravity(5);

    Obstacle obstacle;
    obstacle.setSize(Vector2f(50,300));
    obstacle.getShape()->setPosition(Vector2f(854, (GetScreenHeight()/2) + 50));
    obstacle.getShape()->setFillColor(Color::Blue);

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

        player.movePlayer(dt);
        obstacle.moveObstacle(dt);

        if (player.getShape()->getPosition().y + player.getShape()->getSize().y >= ground.getPosition().y)
        {
            player.getShape()->setPosition(Vector2f(player.getShape()->getPosition().x, ground.getPosition().y - player.getShape()->getSize().y)); 
        }
        
        if (obstacle.getShape()->getPosition().x + obstacle.getShape()->getSize().x < 0)
        {
            obstacle.getShape()->setPosition(854, (GetScreenHeight() / 2) + 50);
        }

        if (player.getShape()->getPosition().x + player.getShape()->getSize().x > obstacle.getShape()->getPosition().x)
        {
            player.playerHit();
        }

        window.clear();
        //window.draw(shape);
        window.draw(*player.getShape());
        window.draw(*obstacle.getShape());
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