#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <random>
#include <cmath>

// #include "Team.hpp"
// #include "Game.hpp"

#pragma once
using namespace std;

namespace league
{
    class Team;
    class Game;
    class League;
    class Schedule
    {
    private:
        vector<Team *> teams;
        vector<Game *> games;
        int number_of_games;
        int number_of_teams;
        int total_games;
        string date;

    public:
        // Schedule();
        Schedule(vector<Team *> &teams, vector<Game *> &games);
        ~Schedule();
        void printGames();
        void simulateGames();
        vector<Game *> getResults();
    };
};
