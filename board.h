#ifndef BOARD_H
#define BOARD_H

#include <iostream>

class board {

public:
	board();
	board(board *board_previous);
	~board();
	void draw(int gameMode);
	void update(int row, int col, int playerNum);
	void clean();
	bool isCellOpen(int row, int col);
	int getSpace(int row, int col);

private:
	int boardLocation[3][3];
};

#endif