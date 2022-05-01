#include <iostream>
#include <string>
#include <cassert>
using namespace std;

#include "BaseballTeam.h"
#include "League.h"


int main()
{
    BaseballTeam dodgers("LA Dodgers");
    BaseballTeam padres("SD Padres");
    BaseballTeam giants("SF Giants");

    League nlWest("National League West");
    nlWest.season(dodgers, 20, 10, 20, 10);
    nlWest.season(padres, 30, 0, 0, 30);
    nlWest.season(giants, 10, 20, 10, 20);
    assert(nlWest.mostHomeWins(dodgers, padres, giants).getName() == "SD Padres");


	cerr << "Success!" << endl;
}