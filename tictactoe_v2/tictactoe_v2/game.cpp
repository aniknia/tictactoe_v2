#include "game.h"

game::game() {
	gameBoard = new board();
	player_one.setPlayerNum(1);
	player_two.setPlayerNum(2);
	bot_one.setPlayerNum(1);
	bot_two.setPlayerNum(2);
}

game::~game() {

}

void game::printTitleCard() {
	std::cout << "<><><><>  <><><><>     <><>    <><><><>    <><>       <><>    <><><><>     <><>     <><><>" << std::endl;
	std::cout << "   <>        <>      <>    <>     <>      <>  <>    <>    <>     <>      <>    <>   <>" << std::endl;
	std::cout << "   <>        <>     <>            <>     <><<>><>  <>            <>     <>      <>  <><><>" << std::endl;
	std::cout << "   <>        <>      <>    <>     <>     <>    <>   <>    <>     <>      <>    <>   <>" << std::endl;
	std::cout << "   <>     <><><><>     <><>       <>     <>    <>     <><>       <>        <><>     <><><>" << std::endl << std::endl;
	std::cout << "<>      <>     <><><>" << std::endl;
	std::cout << "<>      <>    <>    <>" << std::endl;
	std::cout << " <>    <>         <>" << std::endl;
	std::cout << "  <>  <>        <>" << std::endl;
	std::cout << "   <><>       <><><><>" << std::endl;
	
	std::system("pause");
	std::system("CLS");
}

int game::mode() {
	std::system("CLS");

	std::cout << "<><><><>  <><><><>     <><>    <><><><>    <><>       <><>    <><><><>     <><>     <><><>" << std::endl;
	std::cout << "   <>        <>      <>    <>     <>      <>  <>    <>    <>     <>      <>    <>   <>" << std::endl;
	std::cout << "   <>        <>     <>            <>     <><<>><>  <>            <>     <>      <>  <><><>" << std::endl;
	std::cout << "   <>        <>      <>    <>     <>     <>    <>   <>    <>     <>      <>    <>   <>" << std::endl;
	std::cout << "   <>     <><><><>     <><>       <>     <>    <>     <><>       <>        <><>     <><><>" << std::endl << std::endl;
	std::cout << "<>      <>     <><><>" << std::endl;
	std::cout << "<>      <>    <>    <>" << std::endl;
	std::cout << " <>    <>         <>" << std::endl;
	std::cout << "  <>  <>        <>" << std::endl;
	std::cout << "   <><>       <><><><>" << std::endl;

	std::cout << "What game mode woud you like to experience..." << std::endl;
	std::cout << "1 : Player vs Player (Standard Play)" << std::endl;
	std::cout << "2 : Player vs Player (Advanced Play)" << std::endl;
	std::cout << "3 : Player vs Bot" << std::endl;
	std::cout << "4 : Exit Game" << std::endl;

	std::cin >> gameMode;

	return gameMode;
}

void game::setGameMode(int mode) {
	gameMode = mode;
}

void game::play() {
	bool continuePlaying = true;
	int x_position;
	int y_position;

	while (continuePlaying) {
		gameBoard.draw(gameMode);

		if (this->victory() || turns == maxTurns)
			this->victoryScreen(this->victory());

		bool cellIsOpen = false;

		while (!cellIsOpen) {
			std::cout << "\nPlease enter you desired location (row number, a space, then column number)..." << std::endl;
			if (gameMode != 3) {
				if (turns % 2 == 1) {
					player_one.setPosition();
					x_position = player_one.getXPosition();
					y_position = player_one.getYPosition();
				}
				else {
					player_two.setPosition();
					x_position = player_two.getXPosition();
					y_position = player_two.getYPosition();
				}
			}
			else {
				if (turns % 2 == 1) {
					player_one.setPosition();
					x_position = player_one.getXPosition();
					y_position = player_one.getYPosition();
				}
				else {
					player_two.setPosition();
					x_position = player_two.getXPosition();
					y_position = player_two.getYPosition();
				}
			}

			if (gameBoard.isCellOpen(x_position, y_position)) {
				cellIsOpen = true;
				if ((turns % 2) == 1)
					gameBoard.update(x_position, y_position, player_one.getPlayerNum());
				else
					gameBoard.update(x_position, y_position, player_two.getPlayerNum());
				
			}
			else {
				std::system("CLS");
				gameBoard.draw(gameMode);
				std::cout << "That space is taken, please pick another space..." << std::endl;
			}
		}

		gameBoard.update(x_position, y_position, 0);
		
		turns++;
	}
}

int game::victory() {
	if (gameMode != 2) {
		if ((gameBoard.getSpace(0, 0) == gameBoard.getSpace(0, 1)) && (gameBoard.getSpace(0, 1) == gameBoard.getSpace(0, 2)) && (gameBoard.getSpace(0, 0) != 0))
			return gameBoard.getSpace(0, 0);
		if ((gameBoard.getSpace(1, 0) == gameBoard.getSpace(1, 1)) && (gameBoard.getSpace(1, 1) == gameBoard.getSpace(1, 2)) && (gameBoard.getSpace(1, 0) != 0))
			return gameBoard.getSpace(1, 0);
		if ((gameBoard.getSpace(2, 0) == gameBoard.getSpace(2, 1)) && (gameBoard.getSpace(2, 1) == gameBoard.getSpace(2, 2)) && (gameBoard.getSpace(2, 0) != 0))
			return gameBoard.getSpace(2, 0);
		if ((gameBoard.getSpace(0, 0) == gameBoard.getSpace(1, 0)) && (gameBoard.getSpace(1, 0) == gameBoard.getSpace(2, 0)) && (gameBoard.getSpace(0, 0) != 0))
			return gameBoard.getSpace(0, 0);
		if ((gameBoard.getSpace(0, 1) == gameBoard.getSpace(1, 1)) && (gameBoard.getSpace(1, 1) == gameBoard.getSpace(2, 1)) && (gameBoard.getSpace(0, 1) != 0))
			return gameBoard.getSpace(0, 1);
		if ((gameBoard.getSpace(0, 2) == gameBoard.getSpace(1, 2)) && (gameBoard.getSpace(1, 2) == gameBoard.getSpace(2, 2)) && (gameBoard.getSpace(0, 2) != 0))
			return gameBoard.getSpace(0, 2);
		if ((gameBoard.getSpace(0, 0) == gameBoard.getSpace(1, 1)) && (gameBoard.getSpace(1, 1) == gameBoard.getSpace(2, 2)) && (gameBoard.getSpace(0, 0) != 0))
			return gameBoard.getSpace(0, 0);
		if ((gameBoard.getSpace(0, 2) == gameBoard.getSpace(1, 1)) && (gameBoard.getSpace(1, 1) == gameBoard.getSpace(2, 0)) && (gameBoard.getSpace(0, 2) != 0))
			return gameBoard.getSpace(0, 2);
		return 0;
	}
	else {
		if ((gameBoard.getSpace(0, 0) != 0) && (gameBoard.getSpace(0, 1) != 0) && (gameBoard.getSpace(0, 2) != 0))
			return (turns % 2) + 1;
		if ((gameBoard.getSpace(1, 0) != 0) && (gameBoard.getSpace(1, 1) != 0) && (gameBoard.getSpace(1, 2) != 0))
			return (turns % 2) + 1;
		if ((gameBoard.getSpace(2, 0) != 0) && (gameBoard.getSpace(2, 1) != 0) && (gameBoard.getSpace(2, 2) != 0))
			return (turns % 2) + 1;
		if ((gameBoard.getSpace(0, 0) != 0) && (gameBoard.getSpace(1, 0) != 0) && (gameBoard.getSpace(2, 0) != 0))
			return (turns % 2) + 1;
		if ((gameBoard.getSpace(0, 1) != 0) && (gameBoard.getSpace(1, 1) != 0) && (gameBoard.getSpace(2, 1) != 0))
			return (turns % 2) + 1;
		if ((gameBoard.getSpace(0, 2) != 0) && (gameBoard.getSpace(1, 2) != 0) && (gameBoard.getSpace(2, 2) != 0))
			return (turns % 2) + 1;
		if ((gameBoard.getSpace(0, 0) != 0) && (gameBoard.getSpace(1, 1) != 0) && (gameBoard.getSpace(2, 2) != 0))
			return (turns % 2) + 1;
		if ((gameBoard.getSpace(0, 2) != 0) && (gameBoard.getSpace(1, 1) != 0) && (gameBoard.getSpace(2, 0) != 0))
			return (turns % 2) + 1;
		return 0;
	}
	return 0;
}

void game::victoryScreen(int winner) {
	char continue_playing = NULL;

	if (winner == 0) {
		std::cout << "Nobody won..." << std::endl;
		player_one.updateScore(0);
		player_two.updateScore(0);
	}
	else if (winner == 1) {
		std::cout << "Player 1 won!" << std::endl;
		player_one.updateScore(1);
		player_two.updateScore(-1);
	}
	else if (winner == 2) {
		std::cout << "Player 2 won!" << std::endl;
		player_one.updateScore(-1);
		player_two.updateScore(1);
	}

	while (continue_playing == NULL) {
		std::cout << "Would you like to continue playing?\n 'y' to continue\n 'n' to exit" << std::endl;
		std::cin >> continue_playing;

		if (continue_playing == 'y') {
			std::cout << "play" << std::endl;
			gameBoard.clean();
			gameBoard.draw(gameMode);
			turns = 1;
		}
		else if (continue_playing == 'n') {
			std::cout << "stop" << std::endl;
			gameBoard.clean();
			turns = 1;
			gameMode = mode();
			if (gameMode == 4)
				exit(0);

		}
		else
			continue_playing = NULL;
	}
}