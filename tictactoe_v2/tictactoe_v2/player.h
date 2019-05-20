#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>

class player {

public:
	player();
	~player();
	void setPlayerNum(int);
	int getPlayerNum();
	void setPosition();
	int getXPosition();
	int getYPosition();
	void updateScore(int);
	int retrieveWins();
	int retrieveLosses();
	int retrieveTies();


private:
	int playerNum = 0;
	int x_position;
	int y_position;
	int wins = 0;
	int losses = 0;
	int ties = 0;
};

#endif