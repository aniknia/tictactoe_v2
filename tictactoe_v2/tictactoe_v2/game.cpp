#include "game.h"

game::game() {
	gameBoard = new board();
}


game::~game() {

}

void game::play() {
	bool continuePlaying = true;
	while (continuePlaying) {
		if (this->victory() || turns == maxturns)
			this->victoryScreen(this->victory());

	}
}

int game::victory() {
	if ((gameBoard->getSpace(0, 0) == gameBoard->getSpace(0, 1)) && (gameBoard->getSpace(0, 1) == gameBoard->getSpace(0, 2)) && (gameBoard->getSpace(0, 0) != 0))
		return gameBoard->getSpace(0, 0);
	if ((gameBoard->getSpace(1, 0) == gameBoard->getSpace(1, 1)) && (gameBoard->getSpace(1, 1) == gameBoard->getSpace(1, 2)) && (gameBoard->getSpace(1, 0) != 0))
		return gameBoard->getSpace(1, 0);
	if ((gameBoard->getSpace(2, 0) == gameBoard->getSpace(2, 1)) && (gameBoard->getSpace(2, 1) == gameBoard->getSpace(2, 2)) && (gameBoard->getSpace(2, 0) != 0))
		return gameBoard->getSpace(2, 0);
	if ((gameBoard->getSpace(0, 0) == gameBoard->getSpace(1, 0)) && (gameBoard->getSpace(1, 0) == gameBoard->getSpace(2, 0)) && (gameBoard->getSpace(0, 0) != 0))
		return gameBoard->getSpace(0, 0);
	if ((gameBoard->getSpace(0, 1) == gameBoard->getSpace(1, 1)) && (gameBoard->getSpace(1, 1) == gameBoard->getSpace(2, 1)) && (gameBoard->getSpace(0, 1) != 0))
		return gameBoard->getSpace(0, 1);
	if ((gameBoard->getSpace(0, 2) == gameBoard->getSpace(1, 2)) && (gameBoard->getSpace(1, 2) == gameBoard->getSpace(2, 2)) && (gameBoard->getSpace(0, 2) != 0))
		return gameBoard->getSpace(0, 2);
	if ((gameBoard->getSpace(0, 0) == gameBoard->getSpace(1, 1)) && (gameBoard->getSpace(1, 1) == gameBoard->getSpace(2, 2)) && (gameBoard->getSpace(0, 0) != 0))
		return gameBoard->getSpace(0, 0);
	return 0;
}

void game::victoryScreen(int winner) {
	char continue_playing = NULL;
	if (winner == 0)
		std::cout << "Nobody won..." << std::endl;
	else if (winner == 1)
		std::cout << "Player 1 won!" << std::endl;
	else if (winner == 2)
		std::cout << "Player 2 won!" << std::endl;

	while (continue_playing == NULL) {
		std::cout << "Would you like to continue playing?\n 'y' to continue\n 'n' to exit" << std::endl;
		std::cin >> continue_playing;

		if (continue_playing == 'y')
			std::cout << "play" << std::endl;
		else if (continue_playing == 'n')
			std::cout << "stop" << std::endl;
		else
			continue_playing = NULL;
	}
}