#include <iostream>
#include <string>
#include <cassert>
using namespace std;

#include "BaseballTeam.h"
#include "League.h"


int main()
{
	League league1("test");
	BaseballTeam team1("team1");
	BaseballTeam team2("team2");
	BaseballTeam team3("team3");
	BaseballTeam team4("team4");
	BaseballTeam team5("team5");

	team1.setHomeWins(1);
	team1.setHomeLosses(1);
	team2.setHomeWins(3);
	team2.setHomeLosses(3);
	team3.setHomeWins(4);
	team3.setHomeLosses(4);
	team4.setHomeWins(10);
	team4.setHomeLosses(10);
	team5.setHomeWins(10);
	team5.setHomeLosses(2);

	assert(league1.pennantWinner(team1, team2, team3, team4, team5).getName() == team4.getName());

	league1.season(team1, 5, 4, 3, 2);

	assert(team1.getHomeWins() == 5);

	team1.clear();
	team2.clear();
	league1.play(team1, team2, 5, 10);

	assert(team1.getHomeLosses() == 1);
	assert(team2.getAwayWins() == 1);
	assert(team2.hasWinningHomeRecord() == true);
	assert(team2.hasWinningRecord() == true);
	assert(team1.hasWinningRecord() == false);
	assert(team1.overallRecord() == "000-001");



	cerr << "Success!" << endl;
}