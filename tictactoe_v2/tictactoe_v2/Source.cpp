/*
	Title: Tictactoe version 2
	Author: Ari Niknia

	Description: A C++ update to my previous tictactoe game in C.

	New Features:
	- Single Player and 2 player
	- Serveral levels of difficulties
	- Normal and Advanced modes of play
*/

#include <iostream>

#include "game.h"
#include "board.h"
#include "list.h"
#include "queue.h"
#include "stack.h"

int main() {
	game g;
	int gameMode = 0;
	g.printTitleCard();
	while (gameMode != 4) {
		gameMode = g.mode();
		if (gameMode == 4)
			break;
		g.setGameMode(gameMode);
		g.play();
	}
	std::system("pause");

	return 0;
}