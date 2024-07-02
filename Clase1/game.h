#pragma once
#include "Player.h"
#include "Obstacle.h"

class Game
{
public:
	Game();
	~Game();
	void runGame();
private:
	void obsTransition(Obstacle& obstacle, int& randomHeight, int& randomAltitude);
	void collision(Player& player, Obstacle& obstacle);
	
	//CircleShape shape(100.f);
	RectangleShape rectangle;
	RectangleShape ground;
	Keyboard keyboard;
	Time dt;
	float rectangleX = (GetScreenWidth() / 2 - 350);
	float rectangleY = (GetScreenHeight() / 2) + 60;

	bool isJumping = false;
	bool isGameRunning = true;
	bool pause = false;

	int currentOption = 1;
	int firstOption;
	int lastOption;
	Font font;
	Text title;
	Text gamePlay;
	Text Credits;
	Text Exit;

	int randomHeight = 0;
	int randomAltitude = 0;
	float timer = 0;
	float coolDownTime = 0.65f;
};

enum GameScreen
{
	MENU,
	GAMEPLAY,
	CREDITS,
	EXIT
};