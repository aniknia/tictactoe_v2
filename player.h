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
	void setXPosition(int new_x_position);
	int getXPosition();
	void setYPosition(int new_y_position);
	int getYPosition();
	void updateScore(int);
	int retrieveWins();
	int retrieveLosses();
	int retrieveTies();


private:
	int playerNum = 0;
	int x_position = 0;
	int y_position = 0;
	int wins = 0;
	int losses = 0;
	int ties = 0;
};

#endif