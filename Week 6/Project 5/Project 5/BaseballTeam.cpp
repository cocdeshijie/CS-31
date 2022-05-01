#include "BaseballTeam.h"

BaseballTeam::BaseballTeam(string name)
{
	mName = name;
}

// get team name
string BaseballTeam::getName()
{
	return mName;
}

// set team name
void BaseballTeam::setName(string name)
{
	mName = name;
}

// get home wins
int BaseballTeam::getHomeWins()
{
	return mHomeWins;
}

// set home wins
void BaseballTeam::setHomeWins(int wins)
{
	mHomeWins = wins;
}

// set home losses
int BaseballTeam::getHomeLosses()
{
	return mHomeLoses;
}

// set home losses
void BaseballTeam::setHomeLosses(int losses)
{
	mHomeLoses = losses;
}

// get away wins
int BaseballTeam::getAwayWins()
{
	return mAwayWins;
}

// get away losses
void BaseballTeam::setAwayWins(int wins)
{
	mAwayWins = wins;
}

// get away losses
int BaseballTeam::getAwayLosses()
{
	return mAwayLoses;
}

// set away losses
void BaseballTeam::setAwayLosses(int losses)
{
	mAwayLoses = losses;
}

// add one to home wins
void BaseballTeam::wonHomeGame()
{
	mHomeWins++;
}

// add one to home losses
void BaseballTeam::lostHomeGame()
{
	mHomeLoses++;
}

// add one to awat wins
void BaseballTeam::wonAwayGame()
{
	mAwayWins++;
}

// add one to home losses
void BaseballTeam::lostAwayGame()
{
	mAwayLoses++;
}

// change everything back to zero
void BaseballTeam::clear()
{
	mHomeWins = 0;
	mHomeLoses = 0;
	mAwayWins = 0;
	mAwayLoses = 0;
}

// return false if no wins anywhere
bool BaseballTeam::hasWinningRecord()
{
	if (mHomeWins + mAwayWins >= mHomeLoses + mAwayLoses)
	{
		return true;
	}
	return false;
}

// return false if awayWins is 0
bool BaseballTeam::hasWinningRoadRecord()
{
	if (mAwayWins >= mAwayLoses)
	{
		return true;
	}
	return false;
}

// return false if homeWins is 0
bool BaseballTeam::hasWinningHomeRecord()
{
	if (mHomeWins >= mHomeLoses)
	{
		return true;
	}
	return false;
}

// format to string
string BaseballTeam::overallRecord()
{
	string wins = to_string(mHomeWins + mAwayWins);
	string losses = to_string(mAwayLoses + mHomeLoses);

	return formatScore(wins) + "-" + formatScore(losses);
}


string BaseballTeam::formatScore(string score)
{
	string formated = score;
	if (score.length() == 1)
	{
		formated = "00" + score;
	}
	if (score.length() == 2)
	{
		formated = "0" + score;
	}
	if (score.length() == 3)
	{
		formated = score;
	}
	return formated;
}