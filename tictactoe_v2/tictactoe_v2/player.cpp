#include "player.h"

player::player() {
	
}

player::~player() {

}

void player::setPlayerNum(int num) {
	playerNum = num;
}

int player::getPlayerNum() {
	return playerNum;
}

void player::setPosition() {
	std::cin >> x_position >> y_position;
}

int player::getXPosition() {
	return x_position;
}

int player::getYPosition() {
	return y_position;
}

void player::updateScore(int score) {
	if (score == 1)
		wins++;
	else if (score == -1)
		losses++;
	else
		ties++;
}

int player::retrieveWins() {
	return wins;
}

int player::retrieveLosses() {
	return losses;
}

int player::retrieveTies() {
	return ties;
}