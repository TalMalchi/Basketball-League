#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <random>
#include "Team.hpp"

using namespace std;
namespace league
{
    float round(float num);
    // --------------------------------------------------------------------------------------------------
    // Constructor in full control
    Team::Team(string name, float talent_level, int id, int score)
    {
        this->name = name;
        this->talent_level = talent_level;
        this->id = id;
        this->total_score = score;
        this->gained_score = 0;
        this->total_wins = 0;
        this->total_losses = 0;
        this->winning_streak = 0;
        this->losing_streak = 0;
        this->last_game_win = false;
    }
    // Constructor
    Team::Team(string name, int id)
    {
        this->name = name;
        this->talent_level = round(((float)rand() / (float)RAND_MAX));
        this->id = id;
        this->total_score = 0;
        this->gained_score = 0;
        this->total_wins = 0;
        this->total_losses = 0;
        this->winning_streak = 0;
        this->losing_streak = 0;
        this->last_game_win = false;
    }
    Team::~Team()
    {
        // cout << "Team " << this->name << ", id: " << this->id << " is destroyed." << endl;
        // delete this;
    }
    // Getters
    string Team::getName() { return this->name; }                 // Return name
    int Team::getTotalScore() { return this->total_score; }       // Return total_score
    int Team::getGainedScore() { return this->gained_score; }     // Return gained_score
    int Team::getId() { return this->id; }                        // Return id
    float Team::getTalentLevel() { return this->talent_level; }   // Return talent_level
    int Team::getTotalWins() { return this->total_wins; }         // Return total_wins
    int Team::getTotalLosses() { return this->total_losses; }     // Return total_losses
    int Team::getWinningStreak() { return this->winning_streak; } // Return winning_streak
    int Team::getLosingStreak() { return this->losing_streak; }   // Return losing_streak
    bool Team::getLastGameWin() { return this->last_game_win; }   // Return last_game_win
    // Setters
    void Team::setTalentLevel(float talent_level) { this->talent_level = talent_level; }       // Set talent_level
    void Team::setTotalScore(int total_score) { this->total_score += total_score; }            // Set total_score
    void Team::setGainedScore(int gained_score) { this->gained_score += gained_score; }        // Set gained_score
    void Team::setWinningStreak(int winning_streak) { this->winning_streak = winning_streak; } // Set winning_streak
    void Team::setLosingStreak(int losing_streak) { this->losing_streak = losing_streak; }     // Set losing_streak
    void Team::setLastGameWin(bool last_game_win) { this->last_game_win = last_game_win; }     // Set last_game_win
    // Incrementers
    void Team::incrementWins() { this->total_wins++; }              // Increment total_wins: "total_wins++"
    void Team::incrementLosses() { this->total_losses++; }          // Increment total_losses: "total_losses++"
    void Team::incrementWinningStreak() { this->winning_streak++; } // Increment winning_streak: "winning_streak++"
    void Team::incrementLosingStreak() { this->losing_streak++; }   // Increment losing_streak: "losing_streak++"
    // Help functions
    /**
     * @brief Round a float number to 2 decimal places
     *
     * @param num
     * @return float
     */
    float round(float num)
    {
        return (float)((int)(num * 100 + .05)) / 100;
    }
} // namespace league