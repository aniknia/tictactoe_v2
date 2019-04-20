#ifndef GAME_H
#define GAME_H

#include "board.h"
#include "player.h"

class game {

public:
	game();
	~game();
	void printTitleCard();
	void play();
	int victory();
	void victoryScreen(int winner);

private:
	board gameBoard;
	player player_one;
	player player_two;
	int turns;
	int maxTurns = 9;
};

#endif