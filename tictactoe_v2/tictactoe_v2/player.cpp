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

void player::updateScore(int score) {
	if (score == 1)
		wins++;
	else if (score == -1)
		loses++;
	else
		ties++;
}

int player::retrieveWins() {
	return wins;
}

int player::retrieveLoses() {
	return loses;
}

int player::retrieveTies() {
	return ties;
}