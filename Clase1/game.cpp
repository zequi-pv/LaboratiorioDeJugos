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
    bool isGameRunning = true;

    int currentOption = 0;
    int firstOption = GameScreen::GAMEPLAY;
    int lastOption = GameScreen::EXIT;
    GameScreen currentScreen = GameScreen::MENU;

    float timer = 0;
    float coolDownTime = 0.54f;

    Player player;
    player.setSize(Vector2f(200, 100));
    player.getShape()->setPosition(Vector2f(rectangleX, rectangleY));
    player.getShape()->setFillColor(Color::Green);
    player.setGravity(50.0f);

    Obstacle obstacle;
    obstacle.setSize(Vector2f(50,300));
    obstacle.getShape()->setPosition(Vector2f(854, (GetScreenHeight()/2) + 50));
    obstacle.getShape()->setFillColor(Color::Blue);

    Obstacle obstacle2;
    obstacle2.setSize(Vector2f(50, 200));
    obstacle2.getShape()->setPosition(Vector2f(1354, (GetScreenHeight() / 2) + 50));
    obstacle2.getShape()->setFillColor(Color::Blue);

    Obstacle obstacle3;
    obstacle3.setSize(Vector2f(50, 400));
    obstacle3.getShape()->setPosition(Vector2f(1854, (GetScreenHeight() / 2) + 50));
    obstacle3.getShape()->setFillColor(Color::Blue);

    //shape.setFillColor(Color::Green);
    bool windowOpen = window.isOpen();
    bool playerIsAlive = player.getIsAlive();
    while (window.isOpen() && player.getIsAlive() && isGameRunning)
    {
        dt = clock.restart();

        timer += dt.asSeconds();

        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        if (keyboard.isKeyPressed(Keyboard::Down))
        {
            if(timer >= coolDownTime)
            {
                timer -= coolDownTime;
                currentOption++;

                if (currentOption >= lastOption)
                {
                    currentOption = lastOption;
                }
            }
        }

        if (keyboard.isKeyPressed(Keyboard::Up))
        {
            if(timer >= coolDownTime)
            {
                timer -= coolDownTime;
                currentOption--;

                if (currentOption <= firstOption)
                {
                    currentOption = firstOption;
                }
            }
        }

        switch (currentScreen)
        {
        case GameScreen::MENU:
            switch (currentOption)
            {
            case GameScreen::GAMEPLAY:
                if (keyboard.isKeyPressed(Keyboard::Enter))
                {
                    currentScreen = GameScreen::GAMEPLAY;
                }
                break;
            case GameScreen::CREDITS:
                if (keyboard.isKeyPressed(Keyboard::Enter))
                {
                    currentScreen = GameScreen::CREDITS;
                }
                break;
            case GameScreen::EXIT:
                if (keyboard.isKeyPressed(Keyboard::Enter))
                {
                    currentScreen = GameScreen::EXIT;
                }
                break;
            default:
                break;
            }
            break;
        case GameScreen::GAMEPLAY:
            player.movePlayer(dt);

            if (player.getShape()->getPosition().y + player.getShape()->getSize().y >= ground.getPosition().y)
            {
                player.getShape()->setPosition(Vector2f(player.getShape()->getPosition().x, ground.getPosition().y - player.getShape()->getSize().y));
            }

            obstacle.moveObstacle(dt);
            obstacle2.moveObstacle(dt);
            obstacle3.moveObstacle(dt);

            obsTransition(obstacle);
            obsTransition(obstacle2);
            obsTransition(obstacle3);

            collision(player, obstacle);
            collision(player, obstacle2);
            collision(player, obstacle3);
            break;
        case GameScreen::CREDITS:

            break;
        case GameScreen::EXIT:
            isGameRunning = false;
            break;
        default:
            break;
        }

        switch (currentScreen)
        {
        case MENU:
            switch (currentOption)
            {
            case GAMEPLAY:
                break;
            case CREDITS:
                break;
            case EXIT:
                break;
            default:
                break;
            }
            break;
        case GAMEPLAY:
            window.clear();
            window.draw(*player.getShape());
            window.draw(*obstacle.getShape());
            window.draw(*obstacle2.getShape());
            window.draw(*obstacle3.getShape());
            window.draw(ground);
            break;
        case CREDITS:
            window.clear();
            break;
        case EXIT:
            window.clear();
            break;
        default:
            break;
        }
        
        window.display();
    }
}

void drawText(Text text)
{
    //text.setFont();
    
}

void Game::obsTransition(Obstacle& obstacle)
{
    if (obstacle.getShape()->getPosition().x + obstacle.getShape()->getSize().x < 0)
    {
        obstacle.getShape()->setPosition(854, (GetScreenHeight() / 2) + 50);
    }
}

void Game::collision(Player& player, Obstacle& obstacle)
{
    if (player.getShape()->getPosition().x + player.getShape()->getSize().x >= obstacle.getShape()->getPosition().x &&
        player.getShape()->getPosition().x <= obstacle.getShape()->getPosition().x + obstacle.getShape()->getSize().x &&
        player.getShape()->getPosition().y + player.getShape()->getSize().y >= obstacle.getShape()->getPosition().y &&
        player.getShape()->getPosition().y <= obstacle.getShape()->getPosition().y + obstacle.getShape()->getSize().y)
    {
        player.playerHit();
    }
}

Game::Game()
{
}

Game::~Game()
{
}