#include "board.h"

board::board() {
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			boardLocation[i][j] = 0;
}

board::board(board *board_previous) {
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			this->boardLocation[i][j] = board_previous->boardLocation[i][j];
}

board::~board() {
	//delete [] boardLocation;
}

void board::draw() {
	std::system("CLS");
	std::cout << "\n\n                            0    1    2\n" << std::endl;
	for (int i = 0; i < 3; i++) {
		std::cout << "                        " << i << " ";
		for (int j = 0; j < 3; j++) {
			if (j < 2) {
				if (boardLocation[i][j] == 1)
					std::cout << "  X |";
				else if (boardLocation[i][j] == 2)
					std::cout << "  O |";
				else
					std::cout << "    |";
			}
			else {
				if (boardLocation[i][j] == 1)
					std::cout << "  X ";
				else if (boardLocation[i][j] == 2)
					std::cout << "  O ";
				else
					std::cout << "    ";
			}
		}
		if (i < 2)
			std::cout << "\n                           _____________\n" << std::endl;
		else
			std::cout << "\n" << std::endl;
	}
}

void board::update(int row, int col, int playerNum) {
	if(this->isCellOpen(row, col) == true)
		boardLocation[row][col] = playerNum;
}

bool board::isCellOpen(int row, int col) {
	if (boardLocation[row][col] == 0)
		return true;
	return false;
}

int board::getSpace(int row, int col) {
	return boardLocation[row][col];
}
