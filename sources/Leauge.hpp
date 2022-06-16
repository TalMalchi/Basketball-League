#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>

#pragma once
using namespace std;

namespace league
{
    class Game;
    class Team;
    class Schedule;
    class League
    {
    public:
        League();
        League(vector<Team *> existTeams);
        ~League();

        // vector<Game *> generateGames;
        vector<Team *> generateTeams(int num_teams);
        void simulateGames();
        void printTeams();
        void printGames();
        // GETTERS
        int getNumberOfTeams();
        // Analysis
        void sortTeamsTable();

        void topTeams(int num_teams);
        void maxWinningStreak();
        void maxLossingStreak();
        void teamsScoredMoreThenGained();
        void aboveTheAverage();

    private:
        vector<Team *> teams;
        vector<Game *> results;
        Schedule *schedule;
        vector<string> uniqueNamesForTeams =
            {"Toronto Raptors", "Chicago Bulls", "Indiana Pacers", "Detroit Pistons", "Orlando Magic", "Philadelphia 76ers",
             "Washington Wizards", "Charlotte Hornets", "New York Knicks", "Denver Nuggets", "Minnesota Timberwolves",
             "Oklahoma City Thunder", "Portland Trail Blazers", "Utah Jazz", "Golden State Warriors", "Los Angeles Clippers",
             "Los Angeles Lakers", "Phoenix Suns", "Sacramento Kings", "Atlanta Hawks", "Brooklyn Nets",
             "Cleveland Cavaliers", "New Orleans Pelicans", "San Antonio Spurs", "Dallas Mavericks", "Houston Rockets",
             "Memphis Grizzlies", "New York Knicks", "Oklahoma City Thunder", "Portland Trail Blazers", "Utah Jazz",
             "Golden State Warriors", "Los Angeles Clippers", "Los Angeles Lakers", "Phoenix Suns", "Sacramento Kings",
             "Atlanta Hawks", "Brooklyn Nets", "Cleveland Cavaliers", "New Orleans Pelicans", "San Antonio Spurs",
             "Dallas Mavericks", "Houston Rockets", "Memphis Grizzlies"};
    };
};