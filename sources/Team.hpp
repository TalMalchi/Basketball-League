#include <iostream>
#pragma once
using namespace std;
namespace league
{
    class Team
    {
    private:
        string name;
        float talent_level;
        int id;
        int total_score;
        int gained_score;
        int total_wins;
        int total_losses;
        int winning_streak;
        int losing_streak;
        bool last_game_win;

    public:
        Team(string name, float talent_level, int id, int score = 0); // Constructor in full control
        Team(string name, int id);                                    // Constructor
        // GETTERS
        string getName();
        float getTalentLevel();
        int getId();
        int getTotalScore();
        int getGainedScore();
        int getTotalWins();
        int getTotalLosses();
        int getWinningStreak();
        int getLosingStreak();
        bool getLastGameWin();
        // SETTERS
        void setTalentLevel(float talent_level);
        void setTotalScore(int total_score);
        void setGainedScore(int gained_score);
        void setWinningStreak(int winning_streak);
        void setLosingStreak(int losing_streak);
        void setLastGameWin(bool last_game_win);
        // INCREMENTERS
        void incrementWins();          // Increment total_wins: "total_wins++"
        void incrementLosses();        // Increment total_losses: "total_losses++"
        void incrementWinningStreak(); // Increment winning_streak: "winning_streak++"
        void incrementLosingStreak();  // Increment losing_streak: "losing_streak++"

        ~Team();
    };
};