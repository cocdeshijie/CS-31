#pragma once
#include <string>
#include "BaseballTeam.h"
using namespace std;
#ifndef League_H
#define League_H

class League
{
public:
	League(string name);

	// get team name
	string getName();

	// set team name
	void setName(string name);

	void play(BaseballTeam& awayTeam, BaseballTeam& homeTeam, int awayScore, int homeScore);

	void season(BaseballTeam& team, int homeWins, int homeLosses, int awayWins, int awayLosses);

	BaseballTeam pennantWinner(BaseballTeam team1, BaseballTeam team2, BaseballTeam team3, BaseballTeam team4, BaseballTeam team5);

private:
	string mName;
};

#endif