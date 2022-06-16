#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <iomanip>
#include "Schedule.hpp"
#include "Game.hpp"
#include "Team.hpp"
using namespace std;

namespace league
{
    class League;
    Schedule::Schedule(vector<Team *> &teams, vector<Game *> &games)
    {
        this->teams = teams;
        this->games = games;
        this->number_of_teams = teams.size();
        this->number_of_games = this->number_of_teams * (this->number_of_teams - 1);
    }
    Schedule::~Schedule()
    {
        for (uint i = 0; i < this->games.size(); i++)
        {
            delete this->games[i];
        }
        cout << "Schedule has deleted" << endl;
    }
    void Schedule::printGames()
    {
        // print all game results with table using iomanip
        cout << "Game results:" << endl;
        cout << setw(8) << "Game id" << setw(25) << "Team1" << setw(25) << "Team2" << setw(10) << "Score1" << setw(10) << "Score2" << setw(10) << "Winner" << endl;
        for (uint i = 0; i < this->games.size(); i++)
        {
            cout << setw(8) << i << setw(25) << this->games[i]->getHome()->getName() << setw(25) << this->games[i]->getAway()->getName() << setw(10) << this->games[i]->getHomeScore() << setw(10) << this->games[i]->getAwayScore() << setw(10) << this->games[i]->getWinTeam() << endl;
        }
    }
    void Schedule::simulateGames()
    {
        for (uint i = 0; i < this->teams.size(); i++)
        {
            for (uint j = i + 1; j < this->teams.size(); j++)
            {
                this->games.push_back(new Game(this->teams[i], this->teams[j]));
                this->games.push_back(new Game(this->teams[j], this->teams[i]));
            }
        }
    }
    vector<Game *> Schedule::getResults() { return this->games; }
}