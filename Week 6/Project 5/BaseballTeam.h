#pragma once
#include <string>
using namespace std;
#ifndef BaseballTeam_H
#define BaseballTeam_H

class BaseballTeam
{
public:
	BaseballTeam(string name);

	// get team name
	string getName();

	// set team name
	void setName(string name);

	// get home wins
	int getHomeWins();

	// set home wins
	void setHomeWins(int wins);

	// set home losses
	int getHomeLosses();

	// set home losses
	void setHomeLosses(int losses);

	// get away wins
	int getAwayWins();

	// get away losses
	void setAwayWins(int wins);

	// get away losses
	int getAwayLosses();

	// set away losses
	void setAwayLosses(int losses);

	// add one to home wins
	void wonHomeGame();

	// add one to home losses
	void lostHomeGame();

	// add one to awat wins
	void wonAwayGame();

	// add one to home losses
	void lostAwayGame();

	// change everything back to zero
	void clear();

	// return false if no wins anywhere
	bool hasWinningRecord();

	// return false if awayWins is 0
	bool hasWinningRoadRecord();

	// return false if homeWins is 0
	bool hasWinningHomeRecord();

	// format to string
	string overallRecord();

	//
	string formatScore(string score);

private:
	string mName;
	int mHomeWins = 0;
	int mHomeLoses = 0;
	int mAwayWins = 0;
	int mAwayLoses = 0;
};

#endif