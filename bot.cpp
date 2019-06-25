#include "bot.h"

bot::bot() {

}

bot::~bot() {

}

void bot::setPosition(board gameBoard) {

	// This is strategy always guarantees a win or a tie
	if (this->checkWin(gameBoard))
		return;
	if (this->blockWin(gameBoard))
		return;
	if (this->fork(gameBoard))
		return;
	if (this->blockFork(gameBoard))
		return;
	if (this->center(gameBoard))
		return;
	if (this->oppositeCorner(gameBoard))
		return;
	if (this->corner(gameBoard))
		return;
	if (this->side(gameBoard))
		return;
	return;
}

bool bot::checkWin(board gameBoard) {
	// Horizontal checks
	if ((gameBoard.getSpace(0, 0) == gameBoard.getSpace(0, 1)) && (gameBoard.getSpace(0, 0) == getPlayerNum()) && (gameBoard.getSpace(0, 2) == 0)) {
		setXPosition(0);
		setYPosition(2);
		return true;
	}

	if ((gameBoard.getSpace(0, 1) == gameBoard.getSpace(0, 2)) && (gameBoard.getSpace(0, 1) == getPlayerNum()) && (gameBoard.getSpace(0, 0) == 0)) {
		setXPosition(0);
		setYPosition(0);
		return true;
	}

	if ((gameBoard.getSpace(0, 0) == gameBoard.getSpace(0, 2)) && (gameBoard.getSpace(0, 0) == getPlayerNum()) && (gameBoard.getSpace(0, 1) == 0)) {
		setXPosition(0);
		setYPosition(1);
		return true;
	}

	if ((gameBoard.getSpace(1, 0) == gameBoard.getSpace(1, 1)) && (gameBoard.getSpace(1, 0) == getPlayerNum()) && (gameBoard.getSpace(1, 2) == 0)) {
		setXPosition(1);
		setYPosition(2);
		return true;
	}

	if ((gameBoard.getSpace(1, 1) == gameBoard.getSpace(1, 2)) && (gameBoard.getSpace(1, 1) == getPlayerNum()) && (gameBoard.getSpace(1, 0) == 0)) {
		setXPosition(1);
		setYPosition(0);
		return true;
	}

	if ((gameBoard.getSpace(1, 0) == gameBoard.getSpace(1, 2)) && (gameBoard.getSpace(1, 0) == getPlayerNum()) && (gameBoard.getSpace(1, 1) == 0)) {
		setXPosition(1);
		setYPosition(1);
		return true;
	}

	if ((gameBoard.getSpace(2, 0) == gameBoard.getSpace(2, 1)) && (gameBoard.getSpace(2, 0) == getPlayerNum()) && (gameBoard.getSpace(2, 2) == 0)) {
		setXPosition(2);
		setYPosition(2);
		return true;
	}

	if ((gameBoard.getSpace(2, 1) == gameBoard.getSpace(2, 2)) && (gameBoard.getSpace(2, 1) == getPlayerNum()) && (gameBoard.getSpace(2, 0) == 0)) {
		setXPosition(2);
		setYPosition(0);
		return true;
	}

	if ((gameBoard.getSpace(2, 0) == gameBoard.getSpace(2, 2)) && (gameBoard.getSpace(2, 0) == getPlayerNum()) && (gameBoard.getSpace(2, 1) == 0)) {
		setXPosition(2);
		setYPosition(1);
		return true;
	}

	// Vertical Checks
	if ((gameBoard.getSpace(0, 0) == gameBoard.getSpace(1, 0)) && (gameBoard.getSpace(0, 0) == getPlayerNum()) && (gameBoard.getSpace(2, 0) == 0)) {
		setXPosition(2);
		setYPosition(0);
		return true;
	}

	if ((gameBoard.getSpace(1, 0) == gameBoard.getSpace(2, 0)) && (gameBoard.getSpace(1, 0) == getPlayerNum()) && (gameBoard.getSpace(0, 0) == 0)) {
		setXPosition(0);
		setYPosition(0);
		return true;
	}

	if ((gameBoard.getSpace(0, 0) == gameBoard.getSpace(2, 0)) && (gameBoard.getSpace(0, 0) == getPlayerNum()) && (gameBoard.getSpace(1, 0) == 0)) {
		setXPosition(1);
		setYPosition(0);
		return true;
	}

	if ((gameBoard.getSpace(0, 1) == gameBoard.getSpace(1, 1)) && (gameBoard.getSpace(0, 1) == getPlayerNum()) && (gameBoard.getSpace(1, 1) == 0)) {
		setXPosition(1);
		setYPosition(1);
		return true;
	}

	if ((gameBoard.getSpace(1, 1) == gameBoard.getSpace(2, 1)) && (gameBoard.getSpace(1, 1) == getPlayerNum()) && (gameBoard.getSpace(0, 1) == 0)) {
		setXPosition(0);
		setYPosition(1);
		return true;
	}

	if ((gameBoard.getSpace(0, 1) == gameBoard.getSpace(2, 1)) && (gameBoard.getSpace(0, 1) == getPlayerNum()) && (gameBoard.getSpace(1, 1) == 0)) {
		setXPosition(1);
		setYPosition(1);
		return true;
	}

	if ((gameBoard.getSpace(0, 2) == gameBoard.getSpace(1, 2)) && (gameBoard.getSpace(0, 2) == getPlayerNum()) && (gameBoard.getSpace(2, 2) == 0)) {
		setXPosition(2);
		setYPosition(2);
		return true;
	}

	if ((gameBoard.getSpace(1, 2) == gameBoard.getSpace(2, 2)) && (gameBoard.getSpace(1, 2) == getPlayerNum()) && (gameBoard.getSpace(0, 2) == 0)) {
		setXPosition(0);
		setYPosition(2);
		return true;
	}

	if ((gameBoard.getSpace(0, 2) == gameBoard.getSpace(2, 2)) && (gameBoard.getSpace(0, 2) == getPlayerNum()) && (gameBoard.getSpace(1, 2) == 0)) {
		setXPosition(1);
		setYPosition(2);
		return true;
	}

	// Diagonal Checks
	if ((gameBoard.getSpace(0, 0) == gameBoard.getSpace(1, 1)) && (gameBoard.getSpace(0, 0) == getPlayerNum()) && (gameBoard.getSpace(2, 2) == 0)) {
		setXPosition(2);
		setYPosition(2);
		return true;
	}

	if ((gameBoard.getSpace(1, 1) == gameBoard.getSpace(2, 2)) && (gameBoard.getSpace(1, 1) == getPlayerNum()) && (gameBoard.getSpace(0, 0) == 0)) {
		setXPosition(0);
		setYPosition(2);
		return true;
	}

	if ((gameBoard.getSpace(2, 2) == gameBoard.getSpace(0, 0)) && (gameBoard.getSpace(2, 2) == getPlayerNum()) && (gameBoard.getSpace(1, 1) == 0)) {
		setXPosition(1);
		setYPosition(2);
		return true;
	}

	if ((gameBoard.getSpace(0, 2) == gameBoard.getSpace(1, 1)) && (gameBoard.getSpace(0, 2) == getPlayerNum()) && (gameBoard.getSpace(2, 0) == 0)) {
		setXPosition(2);
		setYPosition(2);
		return true;
	}

	if ((gameBoard.getSpace(1, 1) == gameBoard.getSpace(2, 0)) && (gameBoard.getSpace(1, 1) == getPlayerNum()) && (gameBoard.getSpace(0, 2) == 0)) {
		setXPosition(0);
		setYPosition(2);
		return true;
	}

	if ((gameBoard.getSpace(2, 0) == gameBoard.getSpace(0, 2)) && (gameBoard.getSpace(2, 0) == getPlayerNum()) && (gameBoard.getSpace(1, 1) == 0)) {
		setXPosition(1);
		setYPosition(2);
		return true;
	}

	return false;
}
bool bot::blockWin(board gameBoard) {
	// Horizontal checks
	if ((gameBoard.getSpace(0, 0) == gameBoard.getSpace(0, 1)) && (gameBoard.getSpace(0, 0) != getPlayerNum()) && (gameBoard.getSpace(0, 0) != 0) && (gameBoard.getSpace(0, 2) == 0)) {
		setXPosition(0);
		setYPosition(2);
		return true;
	}

	if ((gameBoard.getSpace(0, 1) == gameBoard.getSpace(0, 2)) && (gameBoard.getSpace(0, 1) != getPlayerNum()) && (gameBoard.getSpace(0, 1) != 0) && (gameBoard.getSpace(0, 0) == 0)) {
		setXPosition(0);
		setYPosition(0);
		return true;
	}

	if ((gameBoard.getSpace(0, 0) == gameBoard.getSpace(0, 2)) && (gameBoard.getSpace(0, 0) != getPlayerNum()) && (gameBoard.getSpace(0, 0) != 0) && (gameBoard.getSpace(0, 1) == 0)) {
		setXPosition(0);
		setYPosition(1);
		return true;
	}

	if ((gameBoard.getSpace(1, 0) == gameBoard.getSpace(1, 1)) && (gameBoard.getSpace(1, 0) != getPlayerNum()) && (gameBoard.getSpace(1, 0) != 0) && (gameBoard.getSpace(1, 2) == 0)) {
		setXPosition(1);
		setYPosition(2);
		return true;
	}

	if ((gameBoard.getSpace(1, 1) == gameBoard.getSpace(1, 2)) && (gameBoard.getSpace(1, 1) != getPlayerNum()) && (gameBoard.getSpace(1, 1) != 0) && (gameBoard.getSpace(1, 0) == 0)) {
		setXPosition(1);
		setYPosition(0);
		return true;
	}

	if ((gameBoard.getSpace(1, 0) == gameBoard.getSpace(1, 2)) && (gameBoard.getSpace(1, 0) != getPlayerNum()) && (gameBoard.getSpace(1, 0) != 0) && (gameBoard.getSpace(1, 1) == 0)) {
		setXPosition(1);
		setYPosition(1);
		return true;
	}

	if ((gameBoard.getSpace(2, 0) == gameBoard.getSpace(2, 1)) && (gameBoard.getSpace(2, 0) != getPlayerNum()) && (gameBoard.getSpace(2, 0) != 0) && (gameBoard.getSpace(2, 2) == 0)) {
		setXPosition(2);
		setYPosition(2);
		return true;
	}

	if ((gameBoard.getSpace(2, 1) == gameBoard.getSpace(2, 2)) && (gameBoard.getSpace(2, 1) != getPlayerNum()) && (gameBoard.getSpace(2, 1) != 0) && (gameBoard.getSpace(2, 0) == 0)) {
		setXPosition(2);
		setYPosition(0);
		return true;
	}

	if ((gameBoard.getSpace(2, 0) == gameBoard.getSpace(2, 2)) && (gameBoard.getSpace(2, 0) != getPlayerNum()) && (gameBoard.getSpace(2, 0) != 0) && (gameBoard.getSpace(2, 1) == 0)) {
		setXPosition(2);
		setYPosition(1);
		return true;
	}

	// Vertical Checks
	if ((gameBoard.getSpace(0, 0) == gameBoard.getSpace(1, 0)) && (gameBoard.getSpace(0, 0) != getPlayerNum()) && (gameBoard.getSpace(0, 0) != 0) && (gameBoard.getSpace(2, 0) == 0)) {
		setXPosition(2);
		setYPosition(0);
		return true;
	}

	if ((gameBoard.getSpace(1, 0) == gameBoard.getSpace(2, 0)) && (gameBoard.getSpace(1, 0) != getPlayerNum()) && (gameBoard.getSpace(1, 0) != 0) && (gameBoard.getSpace(0, 0) == 0)) {
		setXPosition(0);
		setYPosition(0);
		return true;
	}

	if ((gameBoard.getSpace(0, 0) == gameBoard.getSpace(2, 0)) && (gameBoard.getSpace(0, 0) != getPlayerNum()) && (gameBoard.getSpace(0, 0) != 0) && (gameBoard.getSpace(1, 0) == 0)) {
		setXPosition(1);
		setYPosition(0);
		return true;
	}

	if ((gameBoard.getSpace(0, 1) == gameBoard.getSpace(1, 1)) && (gameBoard.getSpace(0, 1) != getPlayerNum()) && (gameBoard.getSpace(0, 1) != 0) && (gameBoard.getSpace(1, 1) == 0)) {
		setXPosition(1);
		setYPosition(1);
		return true;
	}

	if ((gameBoard.getSpace(1, 1) == gameBoard.getSpace(2, 1)) && (gameBoard.getSpace(1, 1) != getPlayerNum()) && (gameBoard.getSpace(1, 1) != 0) && (gameBoard.getSpace(0, 1) == 0)) {
		setXPosition(0);
		setYPosition(1);
		return true;
	}

	if ((gameBoard.getSpace(0, 1) == gameBoard.getSpace(2, 1)) && (gameBoard.getSpace(0, 1) != getPlayerNum()) && (gameBoard.getSpace(0, 1) != 0) && (gameBoard.getSpace(1, 1) == 0)) {
		setXPosition(1);
		setYPosition(1);
		return true;
	}

	if ((gameBoard.getSpace(0, 2) == gameBoard.getSpace(1, 2)) && (gameBoard.getSpace(0, 2) != getPlayerNum()) && (gameBoard.getSpace(0, 2) != 0) && (gameBoard.getSpace(2, 2) == 0)) {
		setXPosition(2);
		setYPosition(2);
		return true;
	}

	if ((gameBoard.getSpace(1, 2) == gameBoard.getSpace(2, 2)) && (gameBoard.getSpace(1, 2) != getPlayerNum()) && (gameBoard.getSpace(1, 2) != 0) && (gameBoard.getSpace(0, 2) == 0)) {
		setXPosition(0);
		setYPosition(2);
		return true;
	}

	if ((gameBoard.getSpace(0, 2) == gameBoard.getSpace(2, 2)) && (gameBoard.getSpace(0, 2) != getPlayerNum()) && (gameBoard.getSpace(0, 2) != 0) && (gameBoard.getSpace(1, 2) == 0)) {
		setXPosition(1);
		setYPosition(2);
		return true;
	}

	// Diagonal Checks
	if ((gameBoard.getSpace(0, 0) == gameBoard.getSpace(1, 1)) && (gameBoard.getSpace(0, 0) != getPlayerNum()) && (gameBoard.getSpace(0, 0) != 0) && (gameBoard.getSpace(2, 2) == 0)) {
		setXPosition(2);
		setYPosition(2);
		return true;
	}

	if ((gameBoard.getSpace(1, 1) == gameBoard.getSpace(2, 2)) && (gameBoard.getSpace(1, 1) != getPlayerNum()) && (gameBoard.getSpace(1, 1) != 0) && (gameBoard.getSpace(0, 0) == 0)) {
		setXPosition(0);
		setYPosition(2);
		return true;
	}

	if ((gameBoard.getSpace(2, 2) == gameBoard.getSpace(0, 0)) && (gameBoard.getSpace(2, 2) != getPlayerNum()) && (gameBoard.getSpace(2, 2) != 0) && (gameBoard.getSpace(1, 1) == 0)) {
		setXPosition(1);
		setYPosition(2);
		return true;
	}

	if ((gameBoard.getSpace(0, 2) == gameBoard.getSpace(1, 1)) && (gameBoard.getSpace(0, 2) != getPlayerNum()) && (gameBoard.getSpace(0, 2) != 0) && (gameBoard.getSpace(2, 0) == 0)) {
		setXPosition(2);
		setYPosition(2);
		return true;
	}

	if ((gameBoard.getSpace(1, 1) == gameBoard.getSpace(2, 0)) && (gameBoard.getSpace(1, 1) != getPlayerNum()) && (gameBoard.getSpace(1, 1) != 0) && (gameBoard.getSpace(0, 2) == 0)) {
		setXPosition(0);
		setYPosition(2);
		return true;
	}

	if ((gameBoard.getSpace(2, 0) == gameBoard.getSpace(0, 2)) && (gameBoard.getSpace(2, 0) != getPlayerNum()) && (gameBoard.getSpace(2, 0) != 0) && (gameBoard.getSpace(1, 1) == 0)) {
		setXPosition(1);
		setYPosition(2);
		return true;
	}

	return false;
}
bool bot::fork(board gameBoard) {

	/* These are the three basic fork patterns
	   The 'W' represents the fork openings
		x|x|W    |x|    x|x|W   x| |
		-----   -----   -----   -----
		x| |    x|x|W    |x|    x|x|W
		-----   -----   -----   -----
		W| |     |W|     |W|W   W| |W
	*/

	// First fork type
	if (gameBoard.getSpace(0, 2) == gameBoard.getSpace(2, 0) == 0) {
		// X pattern is in top left
		if ((gameBoard.getSpace(0, 0) == 0) && ((gameBoard.getSpace(0, 1) == gameBoard.getSpace(1, 0)) && (gameBoard.getSpace(1, 0) == getPlayerNum()))) {
			setXPosition(0);
			setYPosition(0);
			return true;
		}
		else if ((gameBoard.getSpace(1, 0) == 0) && ((gameBoard.getSpace(0, 0) == gameBoard.getSpace(0, 1)) && (gameBoard.getSpace(0, 1) == getPlayerNum()))) {
			setXPosition(1);
			setYPosition(0);
			return true;
		}
		else if ((gameBoard.getSpace(0, 1) == 0) && ((gameBoard.getSpace(1, 0) == gameBoard.getSpace(0, 0)) && (gameBoard.getSpace(0, 0) == getPlayerNum()))) {
			setXPosition(0);
			setYPosition(1);
			return true;
		}

		// X pattern is in bottom right
		if ((gameBoard.getSpace(2, 1) == 0) && ((gameBoard.getSpace(2, 2) == gameBoard.getSpace(1, 2)) && (gameBoard.getSpace(1, 2) == getPlayerNum()))) {
			setXPosition(2);
			setYPosition(1);
			return true;
		}
		else if ((gameBoard.getSpace(1, 2) == 0) && ((gameBoard.getSpace(2, 1) == gameBoard.getSpace(2, 2)) && (gameBoard.getSpace(2, 2) == getPlayerNum()))) {
			setXPosition(1);
			setYPosition(2);
			return true;
		}
		else if ((gameBoard.getSpace(2, 2) == 0) && ((gameBoard.getSpace(1, 2) == gameBoard.getSpace(2, 1)) && (gameBoard.getSpace(2, 1) == getPlayerNum()))) {
			setXPosition(2);
			setYPosition(2);
			return true;
		}

	}
	else if (gameBoard.getSpace(0, 0) == gameBoard.getSpace(2, 2) == 0) {
		// X pattern is in top right
		if ((gameBoard.getSpace(0, 1) == 0) && ((gameBoard.getSpace(0, 2) == gameBoard.getSpace(1, 2)) && (gameBoard.getSpace(1, 2) == getPlayerNum()))) {
			setXPosition(0);
			setYPosition(1);
			return true;
		}
		else if ((gameBoard.getSpace(1, 2) == 0) && ((gameBoard.getSpace(0, 1) == gameBoard.getSpace(0, 2)) && (gameBoard.getSpace(0, 2) == getPlayerNum()))) {
			setXPosition(1);
			setYPosition(2);
			return true;
		}
		else if ((gameBoard.getSpace(0, 2) == 0) && ((gameBoard.getSpace(1, 2) == gameBoard.getSpace(0, 1)) && (gameBoard.getSpace(0, 1) == getPlayerNum()))) {
			setXPosition(0);
			setYPosition(2);
			return true;
		}

		// X pattern is in bottom left
		if ((gameBoard.getSpace(1, 0) == 0) && ((gameBoard.getSpace(2, 0) == gameBoard.getSpace(2, 1)) && (gameBoard.getSpace(2, 1) == getPlayerNum()))) {
			setXPosition(1);
			setYPosition(0);
			return true;
		}
		else if ((gameBoard.getSpace(2, 1) == 0) && ((gameBoard.getSpace(1, 0) == gameBoard.getSpace(2, 0)) && (gameBoard.getSpace(2, 0) == getPlayerNum()))) {
			setXPosition(2);
			setYPosition(1);
			return true;
		}
		else if ((gameBoard.getSpace(2, 0) == 0) && ((gameBoard.getSpace(2, 1) == gameBoard.getSpace(1, 0)) && (gameBoard.getSpace(1, 0) == getPlayerNum()))) {
			setXPosition(2);
			setYPosition(0);
			return true;
		}

	}
	
	// Second fork type
	if (gameBoard.getSpace(2, 1) == gameBoard.getSpace(1, 2) == 0) {
		// X pattern is in top left
		if ((gameBoard.getSpace(1, 0) == 0) && ((gameBoard.getSpace(1, 1) == gameBoard.getSpace(0, 1)) && (gameBoard.getSpace(0, 1) == getPlayerNum()))) {
			setXPosition(1);
			setYPosition(0);
			return true;
		}
		else if ((gameBoard.getSpace(0, 1) == 0) && ((gameBoard.getSpace(1, 0) == gameBoard.getSpace(1, 1)) && (gameBoard.getSpace(1, 1) == getPlayerNum()))) {
			setXPosition(0);
			setYPosition(1);
			return true;
		}
		else if ((gameBoard.getSpace(1, 1) == 0) && ((gameBoard.getSpace(0, 1) == gameBoard.getSpace(1, 0)) && (gameBoard.getSpace(1, 0) == getPlayerNum()))) {
			setXPosition(1);
			setYPosition(1);
			return true;
		}

	}

	else if (gameBoard.getSpace(1, 0) == gameBoard.getSpace(2, 1) == 0) {
		// X pattern is in top right
		if ((gameBoard.getSpace(0, 1) == 0) && ((gameBoard.getSpace(1, 1) == gameBoard.getSpace(1, 2)) && (gameBoard.getSpace(1, 2) == getPlayerNum()))) {
			setXPosition(0);
			setYPosition(1);
			return true;
		}
		else if ((gameBoard.getSpace(1, 2) == 0) && ((gameBoard.getSpace(0, 1) == gameBoard.getSpace(1, 1)) && (gameBoard.getSpace(1, 1) == getPlayerNum()))) {
			setXPosition(1);
			setYPosition(2);
			return true;
		}
		else if ((gameBoard.getSpace(1, 1) == 0) && ((gameBoard.getSpace(1, 2) == gameBoard.getSpace(0, 1)) && (gameBoard.getSpace(0, 1) == getPlayerNum()))) {
			setXPosition(1);
			setYPosition(1);
			return true;
		}

	}

	else if (gameBoard.getSpace(1, 0) == gameBoard.getSpace(0, 1) == 0) {
		// X pattern is in bottom right
		if ((gameBoard.getSpace(1, 1) == 0) && ((gameBoard.getSpace(1, 2) == gameBoard.getSpace(2, 1)) && (gameBoard.getSpace(2, 1) == getPlayerNum()))) {
			setXPosition(1);
			setYPosition(1);
			return true;
		}
		else if ((gameBoard.getSpace(2, 1) == 0) && ((gameBoard.getSpace(1, 1) == gameBoard.getSpace(1, 2)) && (gameBoard.getSpace(1, 2) == getPlayerNum()))) {
			setXPosition(2);
			setYPosition(1);
			return true;
		}
		else if ((gameBoard.getSpace(1, 2) == 0) && ((gameBoard.getSpace(2, 1) == gameBoard.getSpace(1, 1)) && (gameBoard.getSpace(1, 1) == getPlayerNum()))) {
			setXPosition(1);
			setYPosition(2);
			return true;
		}

	}

	else if (gameBoard.getSpace(0, 1) == gameBoard.getSpace(1, 2) == 0) {
		// X pattern is in bottom left
		if ((gameBoard.getSpace(1, 1) == 0) && ((gameBoard.getSpace(2, 1) == gameBoard.getSpace(1, 0)) && (gameBoard.getSpace(1, 0) == getPlayerNum()))) {
			setXPosition(1);
			setYPosition(1);
			return true;
		}
		else if ((gameBoard.getSpace(1, 0) == 0) && ((gameBoard.getSpace(1, 1) == gameBoard.getSpace(2, 1)) && (gameBoard.getSpace(2, 1) == getPlayerNum()))) {
			setXPosition(1);
			setYPosition(0);
			return true;
		}
		else if ((gameBoard.getSpace(2, 1) == 0) && ((gameBoard.getSpace(1, 0) == gameBoard.getSpace(1, 1)) && (gameBoard.getSpace(1, 1) == getPlayerNum()))) {
			setXPosition(2);
			setYPosition(1);
			return true;
		}

	}
	
	// Third fork
	if ((gameBoard.getSpace(2, 0) == gameBoard.getSpace(2, 2) == 0) || (gameBoard.getSpace(2, 0) == gameBoard.getSpace(1, 2) == 0) || (gameBoard.getSpace(2, 2) == gameBoard.getSpace(1, 2) == 0)) {
		// X pattern is in top left
		if ((gameBoard.getSpace(1, 1) == 0) && ((gameBoard.getSpace(0, 0) == gameBoard.getSpace(1, 0)) && (gameBoard.getSpace(1, 0) == getPlayerNum()))) {
			setXPosition(1);
			setYPosition(1);
			return true;
		}
		else if ((gameBoard.getSpace(1, 0) == 0) && ((gameBoard.getSpace(1, 1) == gameBoard.getSpace(0, 0)) && (gameBoard.getSpace(0, 0) == getPlayerNum()))) {
			setXPosition(1);
			setYPosition(0);
			return true;
		}
		else if ((gameBoard.getSpace(0, 0) == 0) && ((gameBoard.getSpace(1, 0) == gameBoard.getSpace(1, 1)) && (gameBoard.getSpace(1, 1) == getPlayerNum()))) {
			setXPosition(0);
			setYPosition(0);
			return true;
		}

	}
	
	else if ((gameBoard.getSpace(0, 0) == gameBoard.getSpace(2, 0) == 0) || (gameBoard.getSpace(0, 0) == gameBoard.getSpace(2, 1) == 0) || (gameBoard.getSpace(2, 0) == gameBoard.getSpace(2, 1) == 0)) {
		// X pattern is in top right
		if ((gameBoard.getSpace(1, 1) == 0) && ((gameBoard.getSpace(0, 1) == gameBoard.getSpace(0, 2)) && (gameBoard.getSpace(0, 2) == getPlayerNum()))) {
			setXPosition(1);
			setYPosition(1);
			return true;
		}
		else if ((gameBoard.getSpace(0, 2) == 0) && ((gameBoard.getSpace(1, 1) == gameBoard.getSpace(0, 1)) && (gameBoard.getSpace(0, 1) == getPlayerNum()))) {
			setXPosition(0);
			setYPosition(2);
			return true;
		}
		else if ((gameBoard.getSpace(0, 1) == 0) && ((gameBoard.getSpace(0, 2) == gameBoard.getSpace(1, 1)) && (gameBoard.getSpace(1, 1) == getPlayerNum()))) {
			setXPosition(0);
			setYPosition(1);
			return true;
		}

	}

	else if ((gameBoard.getSpace(0, 0) == gameBoard.getSpace(1, 0) == 0) || (gameBoard.getSpace(0, 0) == gameBoard.getSpace(0, 2) == 0) || (gameBoard.getSpace(1, 0) == gameBoard.getSpace(0, 2) == 0)) {
		// X pattern is in bottom right
		if ((gameBoard.getSpace(1, 1) == 0) && ((gameBoard.getSpace(1, 2) == gameBoard.getSpace(2, 2)) && (gameBoard.getSpace(2, 2) == getPlayerNum()))) {
			setXPosition(1);
			setYPosition(1);
			return true;
		}
		else if ((gameBoard.getSpace(2, 2) == 0) && ((gameBoard.getSpace(1, 1) == gameBoard.getSpace(1, 2)) && (gameBoard.getSpace(1, 2) == getPlayerNum()))) {
			setXPosition(2);
			setYPosition(2);
			return true;
		}
		else if ((gameBoard.getSpace(1, 2) == 0) && ((gameBoard.getSpace(2, 2) == gameBoard.getSpace(1, 1)) && (gameBoard.getSpace(1, 1) == getPlayerNum()))) {
			setXPosition(1);
			setYPosition(2);
			return true;
		}

	}

	else if ((gameBoard.getSpace(0, 1) == gameBoard.getSpace(0, 2) == 0) || (gameBoard.getSpace(0, 1) == gameBoard.getSpace(2, 2) == 0) || (gameBoard.getSpace(0, 2) == gameBoard.getSpace(2, 2) == 0)) {
		// X pattern is in bottom left
		if ((gameBoard.getSpace(1, 1) == 0) && ((gameBoard.getSpace(2, 0) == gameBoard.getSpace(2, 1)) && (gameBoard.getSpace(2, 1) == getPlayerNum()))) {
			setXPosition(1);
			setYPosition(1);
			return true;
		}
		else if ((gameBoard.getSpace(2, 1) == 0) && ((gameBoard.getSpace(1, 1) == gameBoard.getSpace(2, 0)) && (gameBoard.getSpace(2, 0) == getPlayerNum()))) {
			setXPosition(2);
			setYPosition(1);
			return true;
		}
		else if ((gameBoard.getSpace(2, 0) == 0) && ((gameBoard.getSpace(2, 1) == gameBoard.getSpace(1, 1)) && (gameBoard.getSpace(1, 1) == getPlayerNum()))) {
			setXPosition(2);
			setYPosition(0);
			return true;
		}

	}

	// Fourth fork
	if ((gameBoard.getSpace(0, 2) == gameBoard.getSpace(2, 1) == 0) || (gameBoard.getSpace(0, 2) == gameBoard.getSpace(2, 2) == 0) || (gameBoard.getSpace(2, 1) == gameBoard.getSpace(2, 2) == 0)) {
		// X pattern is in top left
		if ((gameBoard.getSpace(1, 1) == 0) && ((gameBoard.getSpace(0, 0) == gameBoard.getSpace(0, 1)) && (gameBoard.getSpace(0, 1) == getPlayerNum()))) {
			setXPosition(1);
			setYPosition(1);
			return true;
		}
		else if ((gameBoard.getSpace(0, 1) == 0) && ((gameBoard.getSpace(1, 1) == gameBoard.getSpace(0, 0)) && (gameBoard.getSpace(0, 0) == getPlayerNum()))) {
			setXPosition(0);
			setYPosition(1);
			return true;
		}
		else if ((gameBoard.getSpace(0, 0) == 0) && ((gameBoard.getSpace(0, 1) == gameBoard.getSpace(1, 1)) && (gameBoard.getSpace(1, 1) == getPlayerNum()))) {
			setXPosition(0);
			setYPosition(0);
			return true;
		}

	}

	else if ((gameBoard.getSpace(1, 0) == gameBoard.getSpace(2, 0) == 0) || (gameBoard.getSpace(1, 0) == gameBoard.getSpace(2, 2) == 0) || (gameBoard.getSpace(2, 0) == gameBoard.getSpace(2, 2) == 0)) {
		// X pattern is in top right
		if ((gameBoard.getSpace(1, 1) == 0) && ((gameBoard.getSpace(1, 2) == gameBoard.getSpace(0, 2)) && (gameBoard.getSpace(0, 2) == getPlayerNum()))) {
			setXPosition(1);
			setYPosition(1);
			return true;
		}
		else if ((gameBoard.getSpace(0, 2) == 0) && ((gameBoard.getSpace(1, 1) == gameBoard.getSpace(1, 2)) && (gameBoard.getSpace(1, 2) == getPlayerNum()))) {
			setXPosition(0);
			setYPosition(2);
			return true;
		}
		else if ((gameBoard.getSpace(1, 2) == 0) && ((gameBoard.getSpace(0, 2) == gameBoard.getSpace(1, 1)) && (gameBoard.getSpace(1, 1) == getPlayerNum()))) {
			setXPosition(1);
			setYPosition(2);
			return true;
		}

	}

	else if ((gameBoard.getSpace(0, 0) == gameBoard.getSpace(2, 0) == 0) || (gameBoard.getSpace(0, 0) == gameBoard.getSpace(0, 1) == 0) || (gameBoard.getSpace(2, 0) == gameBoard.getSpace(0, 1) == 0)) {
		// X pattern is in bottom right
		if ((gameBoard.getSpace(1, 1) == 0) && ((gameBoard.getSpace(2, 1) == gameBoard.getSpace(2, 2)) && (gameBoard.getSpace(2, 2) == getPlayerNum()))) {
			setXPosition(1);
			setYPosition(1);
			return true;
		}
		else if ((gameBoard.getSpace(2, 2) == 0) && ((gameBoard.getSpace(1, 1) == gameBoard.getSpace(2, 1)) && (gameBoard.getSpace(2, 1) == getPlayerNum()))) {
			setXPosition(2);
			setYPosition(2);
			return true;
		}
		else if ((gameBoard.getSpace(2, 1) == 0) && ((gameBoard.getSpace(2, 2) == gameBoard.getSpace(1, 1)) && (gameBoard.getSpace(1, 1) == getPlayerNum()))) {
			setXPosition(2);
			setYPosition(1);
			return true;
		}

	}

	else if ((gameBoard.getSpace(0, 0) == gameBoard.getSpace(0, 2) == 0) || (gameBoard.getSpace(0, 0) == gameBoard.getSpace(1, 2) == 0) || (gameBoard.getSpace(0, 2) == gameBoard.getSpace(1, 2) == 0)) {
		// X pattern is in bottom left
		if ((gameBoard.getSpace(1, 1) == 0) && ((gameBoard.getSpace(2, 0) == gameBoard.getSpace(1, 0)) && (gameBoard.getSpace(1, 0) == getPlayerNum()))) {
			setXPosition(1);
			setYPosition(1);
			return true;
		}
		else if ((gameBoard.getSpace(1, 0) == 0) && ((gameBoard.getSpace(1, 1) == gameBoard.getSpace(2, 0)) && (gameBoard.getSpace(2, 0) == getPlayerNum()))) {
			setXPosition(1);
			setYPosition(0);
			return true;
		}
		else if ((gameBoard.getSpace(2, 0) == 0) && ((gameBoard.getSpace(1, 0) == gameBoard.getSpace(1, 1)) && (gameBoard.getSpace(1, 1) == getPlayerNum()))) {
			setXPosition(2);
			setYPosition(0);
			return true;
		}

	}

	return false;
}
bool bot::blockFork(board gameBoard) {

	// First fork type
	if (gameBoard.getSpace(0, 2) == gameBoard.getSpace(2, 0) == 0) {
		// X pattern is in top left
		if ((gameBoard.getSpace(0, 0) == 0) && ((gameBoard.getSpace(0, 1) == gameBoard.getSpace(1, 0)) && (gameBoard.getSpace(1, 0) != getPlayerNum()) && (gameBoard.getSpace(1, 0) != 0))) {
			setXPosition(0);
			setYPosition(0);
			return true;
		}
		else if ((gameBoard.getSpace(1, 0) == 0) && ((gameBoard.getSpace(0, 0) == gameBoard.getSpace(0, 1)) && (gameBoard.getSpace(0, 1) != getPlayerNum()) && (gameBoard.getSpace(0, 1) != 0))) {
			setXPosition(1);
			setYPosition(0);
			return true;
		}
		else if ((gameBoard.getSpace(0, 1) == 0) && ((gameBoard.getSpace(1, 0) == gameBoard.getSpace(0, 0)) && (gameBoard.getSpace(0, 0) != getPlayerNum()) && (gameBoard.getSpace(0, 0) != 0))) {
			setXPosition(0);
			setYPosition(1);
			return true;
		}

		// X pattern is in bottom right
		if ((gameBoard.getSpace(2, 1) == 0) && ((gameBoard.getSpace(2, 2) == gameBoard.getSpace(1, 2)) && (gameBoard.getSpace(1, 2) != getPlayerNum()) && (gameBoard.getSpace(1, 2) != 0))) {
			setXPosition(2);
			setYPosition(1);
			return true;
		}
		else if ((gameBoard.getSpace(1, 2) == 0) && ((gameBoard.getSpace(2, 1) == gameBoard.getSpace(2, 2)) && (gameBoard.getSpace(2, 2) != getPlayerNum()) && (gameBoard.getSpace(2, 2) != 0))) {
			setXPosition(1);
			setYPosition(2);
			return true;
		}
		else if ((gameBoard.getSpace(2, 2) == 0) && ((gameBoard.getSpace(1, 2) == gameBoard.getSpace(2, 1)) && (gameBoard.getSpace(2, 1) != getPlayerNum()) && (gameBoard.getSpace(2, 1) != 0))) {
			setXPosition(2);
			setYPosition(2);
			return true;
		}

	}
	else if (gameBoard.getSpace(0, 0) == gameBoard.getSpace(2, 2) == 0) {
		// X pattern is in top right
		if ((gameBoard.getSpace(0, 1) == 0) && ((gameBoard.getSpace(0, 2) == gameBoard.getSpace(1, 2)) && (gameBoard.getSpace(1, 2) != getPlayerNum()) && (gameBoard.getSpace(1, 2) != 0))) {
			setXPosition(0);
			setYPosition(1);
			return true;
		}
		else if ((gameBoard.getSpace(1, 2) == 0) && ((gameBoard.getSpace(0, 1) == gameBoard.getSpace(0, 2)) && (gameBoard.getSpace(0, 2) != getPlayerNum()) && (gameBoard.getSpace(0, 2) != 0))) {
			setXPosition(1);
			setYPosition(2);
			return true;
		}
		else if ((gameBoard.getSpace(0, 2) == 0) && ((gameBoard.getSpace(1, 2) == gameBoard.getSpace(0, 1)) && (gameBoard.getSpace(0, 1) != getPlayerNum()) && (gameBoard.getSpace(0, 1) != 0))) {
			setXPosition(0);
			setYPosition(2);
			return true;
		}

		// X pattern is in bottom left
		if ((gameBoard.getSpace(1, 0) == 0) && ((gameBoard.getSpace(2, 0) == gameBoard.getSpace(2, 1)) && (gameBoard.getSpace(2, 1) != getPlayerNum()) && (gameBoard.getSpace(2, 1) != 0))) {
			setXPosition(1);
			setYPosition(0);
			return true;
		}
		else if ((gameBoard.getSpace(2, 1) == 0) && ((gameBoard.getSpace(1, 0) == gameBoard.getSpace(2, 0)) && (gameBoard.getSpace(2, 0) != getPlayerNum()) && (gameBoard.getSpace(2, 0) != 0))) {
			setXPosition(2);
			setYPosition(1);
			return true;
		}
		else if ((gameBoard.getSpace(2, 0) == 0) && ((gameBoard.getSpace(2, 1) == gameBoard.getSpace(1, 0)) && (gameBoard.getSpace(1, 0) != getPlayerNum()) && (gameBoard.getSpace(1, 0) != 0))) {
			setXPosition(2);
			setYPosition(0);
			return true;
		}

	}

	// Second fork type
	if (gameBoard.getSpace(2, 1) == gameBoard.getSpace(1, 2) == 0) {
		// X pattern is in top left
		if ((gameBoard.getSpace(1, 0) == 0) && ((gameBoard.getSpace(1, 1) == gameBoard.getSpace(0, 1)) && (gameBoard.getSpace(0, 1) != getPlayerNum()) && (gameBoard.getSpace(0, 1) != 0))) {
			setXPosition(1);
			setYPosition(0);
			return true;
		}
		else if ((gameBoard.getSpace(0, 1) == 0) && ((gameBoard.getSpace(1, 0) == gameBoard.getSpace(1, 1)) && (gameBoard.getSpace(1, 1) != getPlayerNum()) && (gameBoard.getSpace(1, 1) != 0))) {
			setXPosition(0);
			setYPosition(1);
			return true;
		}
		else if ((gameBoard.getSpace(1, 1) == 0) && ((gameBoard.getSpace(0, 1) == gameBoard.getSpace(1, 0)) && (gameBoard.getSpace(1, 0) != getPlayerNum()) && (gameBoard.getSpace(1, 0) != 0))) {
			setXPosition(1);
			setYPosition(1);
			return true;
		}

	}

	else if (gameBoard.getSpace(1, 0) == gameBoard.getSpace(2, 1) == 0) {
		// X pattern is in top right
		if ((gameBoard.getSpace(0, 1) == 0) && ((gameBoard.getSpace(1, 1) == gameBoard.getSpace(1, 2)) && (gameBoard.getSpace(1, 2) != getPlayerNum()) && (gameBoard.getSpace(1, 2) != 0))) {
			setXPosition(0);
			setYPosition(1);
			return true;
		}
		else if ((gameBoard.getSpace(1, 2) == 0) && ((gameBoard.getSpace(0, 1) == gameBoard.getSpace(1, 1)) && (gameBoard.getSpace(1, 1) != getPlayerNum()) && (gameBoard.getSpace(1, 1) != 0))) {
			setXPosition(1);
			setYPosition(2);
			return true;
		}
		else if ((gameBoard.getSpace(1, 1) == 0) && ((gameBoard.getSpace(1, 2) == gameBoard.getSpace(0, 1)) && (gameBoard.getSpace(0, 1) != getPlayerNum()) && (gameBoard.getSpace(0, 1) != 0))) {
			setXPosition(1);
			setYPosition(1);
			return true;
		}

	}

	else if (gameBoard.getSpace(1, 0) == gameBoard.getSpace(0, 1) == 0) {
		// X pattern is in bottom right
		if ((gameBoard.getSpace(1, 1) == 0) && ((gameBoard.getSpace(1, 2) == gameBoard.getSpace(2, 1)) && (gameBoard.getSpace(2, 1) != getPlayerNum()) && (gameBoard.getSpace(2, 1) != 0))) {
			setXPosition(1);
			setYPosition(1);
			return true;
		}
		else if ((gameBoard.getSpace(2, 1) == 0) && ((gameBoard.getSpace(1, 1) == gameBoard.getSpace(1, 2)) && (gameBoard.getSpace(1, 2) != getPlayerNum()) && (gameBoard.getSpace(1, 2) != 0))) {
			setXPosition(2);
			setYPosition(1);
			return true;
		}
		else if ((gameBoard.getSpace(1, 2) == 0) && ((gameBoard.getSpace(2, 1) == gameBoard.getSpace(1, 1)) && (gameBoard.getSpace(1, 1) != getPlayerNum()) && (gameBoard.getSpace(1, 1) != 0))) {
			setXPosition(1);
			setYPosition(2);
			return true;
		}

	}

	else if (gameBoard.getSpace(0, 1) == gameBoard.getSpace(1, 2) == 0) {
		// X pattern is in bottom left
		if ((gameBoard.getSpace(1, 1) == 0) && ((gameBoard.getSpace(2, 1) == gameBoard.getSpace(1, 0)) && (gameBoard.getSpace(1, 0) != getPlayerNum()) && (gameBoard.getSpace(1, 0) != 0))) {
			setXPosition(1);
			setYPosition(1);
			return true;
		}
		else if ((gameBoard.getSpace(1, 0) == 0) && ((gameBoard.getSpace(1, 1) == gameBoard.getSpace(2, 1)) && (gameBoard.getSpace(2, 1) != getPlayerNum()) && (gameBoard.getSpace(2, 1) != 0))) {
			setXPosition(1);
			setYPosition(0);
			return true;
		}
		else if ((gameBoard.getSpace(2, 1) == 0) && ((gameBoard.getSpace(1, 0) == gameBoard.getSpace(1, 1)) && (gameBoard.getSpace(1, 1) != getPlayerNum()) && (gameBoard.getSpace(1, 1) != 0))) {
			setXPosition(2);
			setYPosition(1);
			return true;
		}

	}

	// Third fork
	if ((gameBoard.getSpace(2, 0) == gameBoard.getSpace(2, 2) == 0) || (gameBoard.getSpace(2, 0) == gameBoard.getSpace(1, 2) == 0) || (gameBoard.getSpace(2, 2) == gameBoard.getSpace(1, 2) == 0)) {
		// X pattern is in top left
		if ((gameBoard.getSpace(1, 1) == 0) && ((gameBoard.getSpace(0, 0) == gameBoard.getSpace(1, 0)) && (gameBoard.getSpace(1, 0) != getPlayerNum()) && (gameBoard.getSpace(1, 0) != 0))) {
			setXPosition(1);
			setYPosition(1);
			return true;
		}
		else if ((gameBoard.getSpace(1, 0) == 0) && ((gameBoard.getSpace(1, 1) == gameBoard.getSpace(0, 0)) && (gameBoard.getSpace(0, 0) != getPlayerNum()) && (gameBoard.getSpace(0, 0) != 0))) {
			setXPosition(1);
			setYPosition(0);
			return true;
		}
		else if ((gameBoard.getSpace(0, 0) == 0) && ((gameBoard.getSpace(1, 0) == gameBoard.getSpace(1, 1)) && (gameBoard.getSpace(1, 1) != getPlayerNum()) && (gameBoard.getSpace(1, 1) != 0))) {
			setXPosition(0);
			setYPosition(0);
			return true;
		}

	}

	else if ((gameBoard.getSpace(0, 0) == gameBoard.getSpace(2, 0) == 0) || (gameBoard.getSpace(0, 0) == gameBoard.getSpace(2, 1) == 0) || (gameBoard.getSpace(2, 0) == gameBoard.getSpace(2, 1) == 0)) {
		// X pattern is in top right
		if ((gameBoard.getSpace(1, 1) == 0) && ((gameBoard.getSpace(0, 1) == gameBoard.getSpace(0, 2)) && (gameBoard.getSpace(0, 2) != getPlayerNum()) && (gameBoard.getSpace(0, 2) != 0))) {
			setXPosition(1);
			setYPosition(1);
			return true;
		}
		else if ((gameBoard.getSpace(0, 2) == 0) && ((gameBoard.getSpace(1, 1) == gameBoard.getSpace(0, 1)) && (gameBoard.getSpace(0, 1) != getPlayerNum()) && (gameBoard.getSpace(0, 1) != 0))) {
			setXPosition(0);
			setYPosition(2);
			return true;
		}
		else if ((gameBoard.getSpace(0, 1) == 0) && ((gameBoard.getSpace(0, 2) == gameBoard.getSpace(1, 1)) && (gameBoard.getSpace(1, 1) != getPlayerNum()) && (gameBoard.getSpace(1, 1) != 0))) {
			setXPosition(0);
			setYPosition(1);
			return true;
		}

	}

	else if ((gameBoard.getSpace(0, 0) == gameBoard.getSpace(1, 0) == 0) || (gameBoard.getSpace(0, 0) == gameBoard.getSpace(0, 2) == 0) || (gameBoard.getSpace(1, 0) == gameBoard.getSpace(0, 2) == 0)) {
		// X pattern is in bottom right
		if ((gameBoard.getSpace(1, 1) == 0) && ((gameBoard.getSpace(1, 2) == gameBoard.getSpace(2, 2)) && (gameBoard.getSpace(2, 2) != getPlayerNum()) && (gameBoard.getSpace(2, 2) != 0))) {
			setXPosition(1);
			setYPosition(1);
			return true;
		}
		else if ((gameBoard.getSpace(2, 2) == 0) && ((gameBoard.getSpace(1, 1) == gameBoard.getSpace(1, 2)) && (gameBoard.getSpace(1, 2) != getPlayerNum()) && (gameBoard.getSpace(1, 2) != 0))) {
			setXPosition(2);
			setYPosition(2);
			return true;
		}
		else if ((gameBoard.getSpace(1, 2) == 0) && ((gameBoard.getSpace(2, 2) == gameBoard.getSpace(1, 1)) && (gameBoard.getSpace(1, 1) != getPlayerNum()) && (gameBoard.getSpace(1, 1) != 0))) {
			setXPosition(1);
			setYPosition(2);
			return true;
		}

	}

	else if ((gameBoard.getSpace(0, 1) == gameBoard.getSpace(0, 2) == 0) || (gameBoard.getSpace(0, 1) == gameBoard.getSpace(2, 2) == 0) || (gameBoard.getSpace(0, 2) == gameBoard.getSpace(2, 2) == 0)) {
		// X pattern is in bottom left
		if ((gameBoard.getSpace(1, 1) == 0) && ((gameBoard.getSpace(2, 0) == gameBoard.getSpace(2, 1)) && (gameBoard.getSpace(2, 1) != getPlayerNum()) && (gameBoard.getSpace(2, 1) != 0))) {
			setXPosition(1);
			setYPosition(1);
			return true;
		}
		else if ((gameBoard.getSpace(2, 1) == 0) && ((gameBoard.getSpace(1, 1) == gameBoard.getSpace(2, 0)) && (gameBoard.getSpace(2, 0) != getPlayerNum()) && (gameBoard.getSpace(2, 0) != 0))) {
			setXPosition(2);
			setYPosition(1);
			return true;
		}
		else if ((gameBoard.getSpace(2, 0) == 0) && ((gameBoard.getSpace(2, 1) == gameBoard.getSpace(1, 1)) && (gameBoard.getSpace(1, 1) != getPlayerNum()) && (gameBoard.getSpace(1, 1) != 0))) {
			setXPosition(2);
			setYPosition(0);
			return true;
		}

	}

	// Fourth fork
	if ((gameBoard.getSpace(0, 2) == gameBoard.getSpace(2, 1) == 0) || (gameBoard.getSpace(0, 2) == gameBoard.getSpace(2, 2) == 0) || (gameBoard.getSpace(2, 1) == gameBoard.getSpace(2, 2) == 0)) {
		// X pattern is in top left
		if ((gameBoard.getSpace(1, 1) == 0) && ((gameBoard.getSpace(0, 0) == gameBoard.getSpace(0, 1)) && (gameBoard.getSpace(0, 1) != getPlayerNum()) && (gameBoard.getSpace(0, 1) != 0))) {
			setXPosition(1);
			setYPosition(1);
			return true;
		}
		else if ((gameBoard.getSpace(0, 1) == 0) && ((gameBoard.getSpace(1, 1) == gameBoard.getSpace(0, 0)) && (gameBoard.getSpace(0, 0) != getPlayerNum()) && (gameBoard.getSpace(0, 0) != 0))) {
			setXPosition(0);
			setYPosition(1);
			return true;
		}
		else if ((gameBoard.getSpace(0, 0) == 0) && ((gameBoard.getSpace(0, 1) == gameBoard.getSpace(1, 1)) && (gameBoard.getSpace(1, 1) != getPlayerNum()) && (gameBoard.getSpace(1, 1) != 0))) {
			setXPosition(0);
			setYPosition(0);
			return true;
		}

	}

	else if ((gameBoard.getSpace(1, 0) == gameBoard.getSpace(2, 0) == 0) || (gameBoard.getSpace(1, 0) == gameBoard.getSpace(2, 2) == 0) || (gameBoard.getSpace(2, 0) == gameBoard.getSpace(2, 2) == 0)) {
		// X pattern is in top right
		if ((gameBoard.getSpace(1, 1) == 0) && ((gameBoard.getSpace(1, 2) == gameBoard.getSpace(0, 2)) && (gameBoard.getSpace(0, 2) != getPlayerNum()) && (gameBoard.getSpace(0, 2) != 0))) {
			setXPosition(1);
			setYPosition(1);
			return true;
		}
		else if ((gameBoard.getSpace(0, 2) == 0) && ((gameBoard.getSpace(1, 1) == gameBoard.getSpace(1, 2)) && (gameBoard.getSpace(1, 2) != getPlayerNum()) && (gameBoard.getSpace(1, 2) != 0))) {
			setXPosition(0);
			setYPosition(2);
			return true;
		}
		else if ((gameBoard.getSpace(1, 2) == 0) && ((gameBoard.getSpace(0, 2) == gameBoard.getSpace(1, 1)) && (gameBoard.getSpace(1, 1) != getPlayerNum()) && (gameBoard.getSpace(1, 1) != 0))) {
			setXPosition(1);
			setYPosition(2);
			return true;
		}

	}

	else if ((gameBoard.getSpace(0, 0) == gameBoard.getSpace(2, 0) == 0) || (gameBoard.getSpace(0, 0) == gameBoard.getSpace(0, 1) == 0) || (gameBoard.getSpace(2, 0) == gameBoard.getSpace(0, 1) == 0)) {
		// X pattern is in bottom right
		if ((gameBoard.getSpace(1, 1) == 0) && ((gameBoard.getSpace(2, 1) == gameBoard.getSpace(2, 2)) && (gameBoard.getSpace(2, 2) != getPlayerNum()) && (gameBoard.getSpace(2, 2) != 0))) {
			setXPosition(1);
			setYPosition(1);
			return true;
		}
		else if ((gameBoard.getSpace(2, 2) == 0) && ((gameBoard.getSpace(1, 1) == gameBoard.getSpace(2, 1)) && (gameBoard.getSpace(2, 1) != getPlayerNum()) && (gameBoard.getSpace(2, 1) != 0))) {
			setXPosition(2);
			setYPosition(2);
			return true;
		}
		else if ((gameBoard.getSpace(2, 1) == 0) && ((gameBoard.getSpace(2, 2) == gameBoard.getSpace(1, 1)) && (gameBoard.getSpace(1, 1) != getPlayerNum()) && (gameBoard.getSpace(1, 1) != 0))) {
			setXPosition(2);
			setYPosition(1);
			return true;
		}

	}

	else if ((gameBoard.getSpace(0, 0) == gameBoard.getSpace(0, 2) == 0) || (gameBoard.getSpace(0, 0) == gameBoard.getSpace(1, 2) == 0) || (gameBoard.getSpace(0, 2) == gameBoard.getSpace(1, 2) == 0)) {
		// X pattern is in bottom left
		if ((gameBoard.getSpace(1, 1) == 0) && ((gameBoard.getSpace(2, 0) == gameBoard.getSpace(1, 0)) && (gameBoard.getSpace(1, 0) != getPlayerNum()) && (gameBoard.getSpace(1, 0) != 0))) {
			setXPosition(1);
			setYPosition(1);
			return true;
		}
		else if ((gameBoard.getSpace(1, 0) == 0) && ((gameBoard.getSpace(1, 1) == gameBoard.getSpace(2, 0)) && (gameBoard.getSpace(2, 0) != getPlayerNum()) && (gameBoard.getSpace(2, 0) != 0))) {
			setXPosition(1);
			setYPosition(0);
			return true;
		}
		else if ((gameBoard.getSpace(2, 0) == 0) && ((gameBoard.getSpace(1, 0) == gameBoard.getSpace(1, 1)) && (gameBoard.getSpace(1, 1) != getPlayerNum()) && (gameBoard.getSpace(1, 1) != 0))) {
			setXPosition(2);
			setYPosition(0);
			return true;
		}

	}

	return false;
}
bool bot::center(board gameBoard) {

	if (gameBoard.getSpace(1, 1) == 0) {
		setXPosition(1);
		setYPosition(1);
		return true;
	}

	return false;
}
bool bot::oppositeCorner(board gameBoard) {

	if ((gameBoard.getSpace(0, 0) == (getPlayerNum() - 1)) && (gameBoard.getSpace(2, 2) == 0)) {
		setXPosition(2);
		setYPosition(2);
		return true;
	}

	else if ((gameBoard.getSpace(0, 2) == (getPlayerNum() - 1)) && (gameBoard.getSpace(2, 0) == 0)) {
		setXPosition(2);
		setYPosition(0);
		return true;
	}

	else if ((gameBoard.getSpace(2, 2) == (getPlayerNum() - 1)) && (gameBoard.getSpace(0, 0) == 0)) {
		setXPosition(0);
		setYPosition(0);
		return true;
	}

	else if ((gameBoard.getSpace(2, 0) == (getPlayerNum() - 1)) && (gameBoard.getSpace(0, 2) == 0)) {
		setXPosition(0);
		setYPosition(2);
		return true;
	}

	return false;
}
bool bot::corner(board gameBoard) {

	srand(time(0));
	int randomNum = rand();
	randomNum = (randomNum % 4) + 1;

	if ((gameBoard.getSpace(0, 0) == gameBoard.getSpace(0, 2) == gameBoard.getSpace(2, 2) == gameBoard.getSpace(2, 0)) && (gameBoard.getSpace(0, 0) == 0)) {
		
		if (randomNum == 1) {
			setXPosition(0);
			setYPosition(0);
			return true;
		}

		else if (randomNum == 2) {
			setXPosition(0);
			setYPosition(2);
			return true;
		}

		else if (randomNum == 3) {
			setXPosition(2);
			setYPosition(2);
			return true;
		}

		else if (randomNum == 4) {
			setXPosition(2);
			setYPosition(0);
			return true;
		}
		
	}

	return false;
}
bool bot::side(board gameBoard) {

	srand(time(0));
	int randomNum = rand();
	randomNum = (randomNum % 4) + 1;

	if ((gameBoard.getSpace(0, 1) == gameBoard.getSpace(1, 2) == gameBoard.getSpace(2, 1) == gameBoard.getSpace(1, 0)) && (gameBoard.getSpace(0, 1) == 0)) {

		if (randomNum == 1) {
			setXPosition(0);
			setYPosition(1);
			return true;
		}

		else if (randomNum == 2) {
			setXPosition(1);
			setYPosition(2);
			return true;
		}

		else if (randomNum == 3) {
			setXPosition(2);
			setYPosition(1);
			return true;
		}

		else if (randomNum == 4) {
			setXPosition(1);
			setYPosition(0);
			return true;
		}

	}

	return false;
}