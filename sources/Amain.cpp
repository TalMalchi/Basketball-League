#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <sstream>
#include <fstream>
#include <random>
#include <cmath>
#include <iomanip>
#include "Team.hpp"
#include "Game.hpp"
#include "Leauge.hpp"

using namespace std;
using namespace league;

int main()
{
    // // Create 2 teams calls "Team1" and "Team2" by using the constructor
    // league::Team *Team1 = new Team("Team1", 1);
    // league::Team *Team2 = new Team("Team2", 2);
    // league::Team *Team3 = new Team("Team3", 3);
    // league::Team *Team4 = new Team("Team4", 4);
    // league::Team *Team5 = new Team("Team5", 5);

    // // Print all details of team1 and team2
    // cout << "Team1: " << Team1.getName() << "| id: " << Team1.getId() << "| talent: " << Team1.getTalentLevel() << endl;
    // cout << "Team2: " << Team2.getName() << "| id: " << Team2.getId() << "| talent: " << Team2.getTalentLevel() << endl;
    // cout << "Team3: " << Team3.getName() << "| id: " << Team3.getId() << "| talent: " << Team3.getTalentLevel() << endl;

    // // simulate games by each team play all other teams, one time current team is home team, second time current team is away team
    // league::Game game1(Team1, Team2);
    // league::Game game2(Team1, Team3);
    // league::Game game3(Team2, Team1);
    // league::Game game4(Team2, Team3);
    // league::Game game5(Team3, Team1);
    // league::Game game6(Team3, Team2);

    // // Print all details of games
    // cout << "Game1: " << game1.getHome().getName() << " vs " << game1.getAway().getName() << "| Home score: " << game1.getHomeScore() << "| Away score: " << game1.getAwayScore() << "| " << game1.getWinTeam() << endl;
    // cout << "Game2: " << game2.getHome().getName() << " vs " << game2.getAway().getName() << "| Home score: " << game2.getHomeScore() << "| Away score: " << game2.getAwayScore() << "| " << game2.getWinTeam() << endl;
    // cout << "Game3: " << game3.getHome().getName() << " vs " << game3.getAway().getName() << "| Home score: " << game3.getHomeScore() << "| Away score: " << game3.getAwayScore() << "| " << game3.getWinTeam() << endl;
    // cout << "Game4: " << game4.getHome().getName() << " vs " << game4.getAway().getName() << "| Home score: " << game4.getHomeScore() << "| Away score: " << game4.getAwayScore() << "| " << game4.getWinTeam() << endl;
    // cout << "Game5: " << game5.getHome().getName() << " vs " << game5.getAway().getName() << "| Home score: " << game5.getHomeScore() << "| Away score: " << game5.getAwayScore() << "| " << game5.getWinTeam() << endl;
    // cout << "Game6: " << game6.getHome().getName() << " vs " << game6.getAway().getName() << "| Home score: " << game6.getHomeScore() << "| Away score: " << game6.getAwayScore() << "| " << game6.getWinTeam() << endl;
    // vector<Team *> existTeams = {Team1, Team2, Team3, Team4, Team5};
    // League league(existTeams);
    // League *league = new League();
    // league.simulateGames();
    // league.printGames();
    // league->printTeams();
    // league.printTeams();

    // Iterate through all teams and make game between currect team to all other teams
    // first time the currect team is home team,
    // second time the currect team is away team
    // for (int i = 0; i < league.getNumberOfTeams(); i++){
    //     for (int j = i + 1; j < league.getNumberOfTeams(); j++){
    //         league.addGame(league.getTeams()[i], league.getTeams()[j]);
    //     }
    // }
    Team *Team1 = new Team("Team1", 0.01, 1);
    Team *Team2 = new Team("Team2", 0.21, 2);
    vector<Team *> existTeams = {Team1, Team2};
    League league(existTeams);

    // League league;
    league.simulateGames();
    league.printTeams();
    league.topTeams(5);
    league.maxWinningStreak();
    league.maxLossingStreak();
    league.teamsScoredMoreThenGained();

    return 0;
}
