#ifndef PLAYER_H
#define PLAYER_H

class player {

public:
	player();
	~player();
	void setPlayerNum(int);
	int getPlayerNum();
	void updateScore(int);
	int retrieveWins();
	int retrieveLoses();
	int retrieveTies();


private:
	int playerNum = 0;
	int wins = 0;
	int loses = 0;
	int ties = 0;
};

#endif