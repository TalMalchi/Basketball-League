#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <iomanip>
#include <random>
#include <cmath>
#include "Game.hpp"
#include "Team.hpp"

using namespace std;
void setDetails(league::Team *home, league::Team *away);
default_random_engine generator; // generator for normal distribution
namespace league
{
    Game::Game(Team *home, Team *away) : home(home), away(away), home_score(0), away_score(0)
    {
        result();
    }
    Game::~Game()
    {
    }

    // Setters
    void Game::setWinTeam(string win_team) { this->win_team = win_team; }
    void Game::setHomeScore(int home_score) { this->home->setTotalScore(home_score); }
    void Game::setAwayScore(int away_score) { this->away->setTotalScore(away_score); }
    void Game::setHomeGained(int away_score) { this->home->setGainedScore(away_score); }
    void Game::setAwayGained(int home_score) { this->away->setGainedScore(home_score); }
    // Getters
    string Game::getWinTeam() { return this->win_team; }
    Team *Game::getHome() { return this->home; }
    Team *Game::getAway() { return this->away; }
    int Game::getHomeScore() const { return this->home_score; }
    int Game::getAwayScore() const { return this->away_score; }

    // Resault of the game and update the score of the teams,
    // and increment the wins and losses of the teams
    void Game::result()
    {
        // The home team randomly score:
        this->home_score = int(normal_distribution<>{75, 20}(generator));
        this->home_score = this->home_score < 55 ? 55 : this->home_score;
        this->home_score = this->home_score > 100 ? 100 : this->home_score;

        // The away team randomly score:
        this->away_score = int(normal_distribution<>{75, 20}(generator));
        this->away_score = this->away_score < 50 ? 50 : this->away_score;
        this->away_score = this->away_score > 100 ? 100 : this->away_score;

        /*
            If home talent level is higher then increase their points by 10
            If away talent level is higher then increase their points by 10
            If their talent levels are equal then home team increase their points by 10
        */
        if (this->home->getTalentLevel() > this->away->getTalentLevel())
        {
            this->home_score += 10;
        }
        else if (this->home->getTalentLevel() < this->away->getTalentLevel())
        {
            this->away_score += 10;
        }
        else
        {
            this->home_score += 10;
        }

        // Setters
        this->setHomeScore(this->home_score);
        this->setHomeGained(this->away_score);
        this->setAwayScore(this->away_score);
        this->setAwayGained(this->home_score);

        // Conditions for the win
        if (home_score > away_score)
        {
            setDetails(this->home, this->away);
            this->setWinTeam("home");
        }
        else if (home_score < away_score)
        {
            setDetails(this->away, this->home);
            this->setWinTeam("away");
        }
        else
        {
            if (this->home->getTalentLevel() > this->away->getTalentLevel())
            {
                setDetails(this->home, this->away);
                this->setWinTeam("home");
            }
            else if (this->home->getTalentLevel() < this->away->getTalentLevel())
            {
                setDetails(this->away, this->home);
                this->setWinTeam("away");
            }
        }
    }

} // namespace league

// Set the details of the winner team
// and the loser team
void setDetails(league::Team *home, league::Team *away)
{
    home->incrementWins();
    away->incrementLosses();
    // Increase winning streak of home's team
    // cout << home->getName() << " have won the game and their winning streak is " << home->getWinningStreak() << endl;
    home->setWinningStreak(home->getLastGameWin() ? home->getWinningStreak() + 1 : 1);
    home->setLastGameWin(true);
    // Increase lossing streak of away's team
    // cout << away->getName() << " have lost the game and their losing streak is " << away->getLosingStreak() << endl;
    away->setLosingStreak(away->getLastGameWin() ? 1 : away->getLosingStreak() + 1);
    away->setLastGameWin(false);
}