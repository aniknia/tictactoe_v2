#ifndef BOARD_H
#define BOARD_H

#include <iostream>

class board
{
public:
	board();
	board(board *board_previous);
	~board();
	void draw();
	void update(int row, int col, int playerNum);
	bool isCellOpen(int row, int col);
	int getSpace(int row, int col);

private:
	int boardLocation[3][3];
};

#endif