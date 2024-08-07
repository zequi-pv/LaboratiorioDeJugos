#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>
#include "game.h"
#include "utils.h"
#include "Player.h"
#include "Obstacle.h"
#include <random>

using namespace sf;



void Game::runGame() 
{
    RenderWindow window(sf::VideoMode(854, 480), "Labo de jugos");
    Clock clock;
    GameScreen currentScreen;

    srand(time(NULL));

    currentScreen = GameScreen::MENU;
    firstOption = GameScreen::GAMEPLAY;
    lastOption = GameScreen::EXIT;
    rectangle.setSize(Vector2f(200, 100));
    rectangle.setFillColor(Color::Green);
    rectangle.setPosition(rectangleX, rectangleY);
    ground.setSize(Vector2f(854, 100));
    ground.setFillColor(Color::White);
    ground.setPosition(0, 400);

    font.loadFromFile("res/fonts/BoaConstruktorBold.ttf");

    title.setFont(font);
    title.setCharacterSize(50);
    title.setStyle(Text::Regular);

    Player player;
    player.setSize(Vector2f(200, 100));
    player.getShape()->setPosition(Vector2f(rectangleX, rectangleY));
    player.getShape()->setFillColor(Color::Green);
    player.setGravity(70.0f);

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

            obsTransition(obstacle, randomHeight, randomAltitude);
            obsTransition(obstacle2, randomHeight, randomAltitude);
            obsTransition(obstacle3, randomHeight, randomAltitude);

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

            title.setFillColor(Color::Blue);
            title.setPosition(330, 130);
            title.setString("RUNNER");
            window.draw(title);

            gamePlay.setFillColor(Color::Blue);
            gamePlay.setPosition(390, 190);
            gamePlay.setFont(font);
            gamePlay.setCharacterSize(30);
            gamePlay.setStyle(Text::Regular);
            gamePlay.setString("PLAY");
            window.draw(gamePlay);

            Credits.setFillColor(Color::Blue);
            Credits.setPosition(390, 220);
            Credits.setFont(font);
            Credits.setCharacterSize(30);
            Credits.setStyle(Text::Regular);
            Credits.setString("CREDITS");
            window.draw(Credits);

            Exit.setFillColor(Color::Blue);
            Exit.setPosition(390, 250);
            Exit.setFont(font);
            Exit.setCharacterSize(30);
            Exit.setStyle(Text::Regular);
            Exit.setString("EXIT");
            window.draw(Exit);

            switch (currentOption)
            {
            case GAMEPLAY:
                gamePlay.setFillColor(Color::Red);
                gamePlay.setPosition(390, 190);
                gamePlay.setFont(font);
                gamePlay.setCharacterSize(30);
                gamePlay.setStyle(Text::Regular);
                gamePlay.setString("PLAY");
                window.draw(gamePlay);
                break;
            case CREDITS:
                Credits.setFillColor(Color::Red);
                Credits.setPosition(390, 220);
                Credits.setFont(font);
                Credits.setCharacterSize(30);
                Credits.setStyle(Text::Regular);
                Credits.setString("CREDITS");
                window.draw(Credits);
                break;
            case EXIT:
                Exit.setFillColor(Color::Red);
                Exit.setPosition(390, 250);
                Exit.setFont(font);
                Exit.setCharacterSize(30);
                Exit.setStyle(Text::Regular);
                Exit.setString("EXIT");
                window.draw(Exit);
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
//
//void drawText(Text text)
//{
//    window.draw
//    
//}

void Game::obsTransition(Obstacle& obstacle, int& randomHeight, int& randomAltitude)
{
    
    if (obstacle.getShape()->getPosition().x + obstacle.getShape()->getSize().x < 0)
    {
        obstacle.getShape()->setSize(Vector2f(obstacle.getShape()->getSize().x, randomHeight = rand() % (400 + 1 - 200) + 200));

        obstacle.getShape()->setPosition(854, randomAltitude = rand() % 480 + 1);
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