#ifndef GAME_H
#define GAME_H

#include "board.h"
#include "player.h"
#include "bot.h"

class game {

public:
	game();
	~game();
	void printTitleCard();
	int mode();
	void setGameMode(int mode);
	void play();
	int victory();
	void victoryScreen(int winner);

private:
	board gameBoard;
	player player_one;
	player player_two;
	bot bot_one;
	bot bot_two;
	int gameMode = 0;
	int turns = 1;
	int maxTurns = 10;
};

#endif