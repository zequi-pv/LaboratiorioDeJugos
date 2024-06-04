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
	void obsTransition(Obstacle& obstacle);
	void collision(Player& player, Obstacle& obstacle);
	
};

enum GameScreen
{
	MENU,
	GAMEPLAY,
	CREDITS,
	EXIT
};