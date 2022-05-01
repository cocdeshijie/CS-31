#include "League.h"

League::League(string name)
{
	mName = name;
}

// get team name
string League::getName()
{
	return mName;
}

// set team name
void League::setName(string name)
{
	mName = name;
}

void League::play(BaseballTeam& awayTeam, BaseballTeam& homeTeam, int awayScore, int homeScore)
{
	if (awayScore > homeScore)
	{
		int awayTeamWins = awayTeam.getAwayWins();
		awayTeam.setAwayWins(awayTeamWins + 1);

		int homeTeamLosses = homeTeam.getHomeLosses();
		homeTeam.setHomeLosses(homeTeamLosses + 1);
	}
	if (homeScore > awayScore)
	{
		int homeTeamWins = homeTeam.getAwayWins();
		homeTeam.setAwayWins(homeTeamWins + 1);

		int awayTeamLosses = awayTeam.getHomeLosses();
		awayTeam.setHomeLosses(awayTeamLosses + 1);
	}
}

void League::season(BaseballTeam& team, int homeWins, int homeLosses, int awayWins, int awayLosses)
{
	team.setHomeWins(homeWins);
	team.setHomeLosses(homeLosses);
	team.setAwayWins(awayWins);
	team.setAwayLosses(awayLosses);
}

BaseballTeam League::pennantWinner(BaseballTeam team1, BaseballTeam team2, BaseballTeam team3, BaseballTeam team4, BaseballTeam team5)
{
	BaseballTeam teams[5] = { team1, team2, team3, team4, team5 };
	int winningTeam = 0;
	// compare each team and find highest score
	for (int i = 0; i < 5; i++)
	{
		if (teams[i].overallRecord() > teams[winningTeam].overallRecord())
		{
			winningTeam = i;
		}
	}

	return teams[winningTeam];
}

BaseballTeam League::mostHomeWins(BaseballTeam team1, BaseballTeam team2, BaseballTeam team3)
{
	BaseballTeam teams[3] = { team1, team2, team3 };
	int winningTeam = 0;
	for (int i = 0; i < 3; i++)
	{
		if (teams[i].getHomeWins() > teams[winningTeam].getHomeWins())
		{
			winningTeam = i;
		}
	}
	return teams[winningTeam];
}