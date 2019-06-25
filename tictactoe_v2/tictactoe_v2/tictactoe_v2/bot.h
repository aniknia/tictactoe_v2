#ifndef BOT_H
#define BOT_H

#include <ctime>
#include <cstdlib>

#include "player.h"
#include "board.h"
#include "time.h"


class bot : public player {

public:
	bot();
	~bot();
	void setPosition(board gameBoard);
	bool checkWin(board gameBoard);
	bool blockWin(board gameBoard);
	bool fork(board gameBoard);
	bool blockFork(board gameBoard);
	bool center(board gameBoard);
	bool oppositeCorner(board gameBoard);
	bool corner(board gameBoard);
	bool side(board gameBoard);

private:
	int points = 0;

};

#endif