#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <random>
#include <cmath>
#include <iomanip>
#include "Leauge.hpp"
#include "Game.hpp"
#include "Team.hpp"
#include "Schedule.hpp"
using namespace std;

#define TEAM_NUMBER 20

namespace league
{
    League::League()
    {
        this->teams = this->generateTeams(TEAM_NUMBER);
        this->schedule = new Schedule(this->teams, this->results);
    }
    /*
        existTeams = {"Team1, Team2, Team3, ..."}
    */
    League::League(vector<Team *> existTeams)
    {
        this->teams = existTeams;
        if (existTeams.size() < TEAM_NUMBER)
        {
            this->teams = existTeams;
            // e.g size of existTeams is 2, but TEAM_NUMBER is 20, so we need to add 20-2=18 teams
            vector<Team *> newTeams = this->generateTeams(TEAM_NUMBER - existTeams.size());
            this->teams.insert(this->teams.end(), newTeams.begin(), newTeams.end());
        }
        else if (existTeams.size() == TEAM_NUMBER)
        {
            this->teams = existTeams;
        }
        else
        {
            this->teams.resize(TEAM_NUMBER);
        }
        this->schedule = new Schedule(this->teams, this->results);
    }
    League::~League()
    {
        for (uint i = 0; i < this->teams.size(); i++)
        {
            delete this->teams[i];
        }
        // delete this->schedule;
        cout << "League has deleted" << endl;
        this->schedule->~Schedule();
    }

    // Generate teams
    vector<Team *> League::generateTeams(int number_of_teams)
    {
        vector<Team *> new_teams;
        if (this->teams.size() == 0)
        {
            for (int i = 0; i < TEAM_NUMBER; i++)
            {
                // Take random name from 'uniqueTeamNames' and remove it from 'uniqueTeamNames'
                string name = this->uniqueNamesForTeams[uint(rand()) % this->uniqueNamesForTeams.size()];
                this->uniqueNamesForTeams.erase(remove(this->uniqueNamesForTeams.begin(), this->uniqueNamesForTeams.end(), name), this->uniqueNamesForTeams.end());
                // Create a new team
                new_teams.push_back(new Team(name, i + 1));
            }
        }
        else
        {
            for (int i = this->teams.size(); i < TEAM_NUMBER; i++)
            {
                // Take random name from 'uniqueTeamNames' and remove it from 'uniqueTeamNames'
                string name = this->uniqueNamesForTeams[uint(rand()) % this->uniqueNamesForTeams.size()];
                this->uniqueNamesForTeams.erase(remove(this->uniqueNamesForTeams.begin(), this->uniqueNamesForTeams.end(), name), this->uniqueNamesForTeams.end());
                // Create a new team
                new_teams.push_back(new Team(name, i + 1));
            }
        }
        return new_teams;
    }
    void League::simulateGames()
    {
        cout << "Simulating games..." << endl;
        schedule->simulateGames();
        // // Get the results
        this->results = schedule->getResults();
        this->sortTeamsTable();
    }

    // PRINTS
    void League::printTeams()
    {
        cout
            << setw(25)
            << left
            << "\nTeam name"
            << setw(5)
            << left
            << "ID"
            << setw(10)
            << left
            << "Talent"
            << setw(14)
            << left
            << "Total score"
            << setw(15)
            << left
            << "Gained score"
            << setw(10)
            << left
            << "Wins"
            << setw(10)
            << left
            << "Losses"
            << setw(10)
            << left
            << endl;

        for (uint i = 0; i < this->teams.size(); i++)
        {
            cout
                << setw(25)
                << left
                << this->teams[i]->getName()
                << setw(5)
                << left
                << this->teams[i]->getId()
                << setw(13)
                << left
                << this->teams[i]->getTalentLevel()
                << setw(15)
                << left
                << this->teams[i]->getTotalScore()
                << setw(13)
                << left
                << this->teams[i]->getGainedScore()
                << setw(10)
                << left
                << this->teams[i]->getTotalWins()
                << setw(10)
                << left<< this->teams[i]->getTotalLosses() << endl;
        }
    }
    void League::printGames()
    {
        this->schedule->printGames();
    }

    // GETTERS
    int League::getNumberOfTeams() { return this->teams.size(); }

    // Analysis
    bool compTable(Team *a, Team *b)
    {
        float a_win_rate = (float)a->getTotalWins() / (float)(a->getTotalLosses());
        float b_win_rate = (float)b->getTotalWins() / (float)(b->getTotalLosses());
        if (a_win_rate > b_win_rate)
        {
            return true;
        }
        else
        {
            if (a_win_rate == b_win_rate)
            {
                return (a->getTotalScore() - a->getGainedScore()) >= (b->getTotalScore() - b->getGainedScore());
            }
            return false;
        }
    }
    bool compWinningStreak(Team *a, Team *b)
    {
        return a->getWinningStreak() < b->getWinningStreak();
    }
    bool compLosingStreak(Team *a, Team *b)
    {
        return a->getLosingStreak() < b->getLosingStreak();
    }
    void League::sortTeamsTable()
    {
        sort(this->teams.begin(), this->teams.end(), compTable);
    }
    void League::topTeams(int number_of_teams)
    {
        cout << "\n       ----------------------------- TOP " << number_of_teams << " TEAMS: -----------------------------" << endl;
        cout << setw(25) << left << "Team name" << setw(5) << left << "ID" << setw(10) << left << "Talent" << setw(14) << left << "Total score" << setw(15) << left << "Gained score" << setw(10) << left << "Wins" << setw(10) << left << "Losses" << setw(10) << left << endl;
        for (uint i = 0; i < number_of_teams; i++)
        {
            cout
                << setw(25)
                << left
                << this->teams[i]->getName()
                << setw(5)
                << left
                << this->teams[i]->getId()
                << setw(13)
                << left
                << this->teams[i]->getTalentLevel()
                << setw(15)
                << left
                << this->teams[i]->getTotalScore()
                << setw(13)
                << left
                << this->teams[i]->getGainedScore()
                << setw(10)
                << left
                << this->teams[i]->getTotalWins()
                << setw(10)
                << left
                << this->teams[i]->getTotalLosses() << endl;
        }
    }
    void League::maxWinningStreak()
    {
        auto x = *max_element(this->teams.begin(), this->teams.end(), compWinningStreak);
        cout << "\n      ----------------------------- MAX WINNING STREAK: -----------------------------" << endl;
        cout << "               " << x->getName() << " has the longest winning streak of " << x->getWinningStreak() << endl;
        cout << "      -----------------------------------------------------------------------------" << endl;
    }
    void League::maxLossingStreak()
    {
        auto x = *max_element(this->teams.begin(), this->teams.end(), compLosingStreak);
        cout << "\n      ----------------------------- MAX LOSING STREAK: -----------------------------" << endl;
        cout << "               " << x->getName() << " has the longest losing streak of " << x->getLosingStreak() << endl;
        cout << "      -----------------------------------------------------------------------------" << endl;
    }
    void League::teamsScoredMoreThenGained()
    {
        int count = 0;
        // Print the teams that scored more then gained
        cout << "\n      ----------------------------- TEAMS SCORED MORE THEN GAINED: -----------------------------" << endl;
        for (uint i = 0; i < this->teams.size(); i++)
        {
            if (this->teams[i]->getTotalScore() - this->teams[i]->getGainedScore() > 0)
            {
                count++;
                cout
                    << setw(25)
                    << left
                    << this->teams[i]->getName()
                    << setw(5)
                    << left
                    << this->teams[i]->getId()
                    << setw(13)
                    << left
                    << this->teams[i]->getTalentLevel()
                    << setw(15)
                    << left
                    << this->teams[i]->getTotalScore()
                    << setw(13)
                    << left
                    << this->teams[i]->getGainedScore()
                    << setw(10)
                    << left
                    << this->teams[i]->getTotalWins()
                    << setw(10)
                    << left
                    << this->teams[i]->getTotalLosses() << endl;
            }
        }
        cout << "\n\t\t\t" << count << " teams scored more then gained" << endl;
        cout << "      -----------------------------------------------------------------------------" << endl;
    }
    // void League::aboveTheAverage()
    // {
    //     int average = 0;
    //     for (auto team : this->teams)
    //     {
    //         average += team->getTotalScore();
    //     }
    //     average /= this->teams.size();
    //     auto x = copy_n(this->teams.begin(), this->teams.size(), [average](Team *team)
    //                     { return team->getTotalScore() > average; });
    //     cout << x << endl;
    // }
};
