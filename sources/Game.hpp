#include <iostream>
using namespace std;
#pragma once
namespace league
{
    class Team;
    class Game
    {
    private:
        string win_team;
        Team *home;
        Team *away;
        int home_score;
        int away_score;
        string location;

    public:
        Game(Team *home, Team *away);
        ~Game();
        void setWinTeam(string win_team);
        void setHomeScore(int home_score);
        void setAwayScore(int away_score);
        void setHomeGained(int away_score);
        void setAwayGained(int home_score);
        string getWinTeam();
        Team *getHome();
        Team *getAway();
        int getHomeScore() const;
        int getAwayScore() const;
        void result();
    };
};