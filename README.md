# Basketball-League
A program that represents a basketball league that contains 20 different teams. The program uses object-oriented programming and statistical analysis.


# Classes
- `team`- A class representing a group. Each group has a unique name and a talent level represented by a number (between 0 and 1)
- `Game` - The match is contested by two teams, a home team and an away team. A game has a score that is determined by the number of points each team scored. The team that scored more points wins. In the event of a draw, the home team will win (according to my personal choice)
- `League` - A department representing a basketball league. The league has 20 teams with unique names. The department produces its set of groups in one of the following ways:
A. Receives from the outside a given set of groups B. Does not accept groups from the outside and produces 20 groups randomly C. Combination of the two previous sections (get part from outside and part to initialize randomly).
- `Schedule` - League schedule of matches. The schedule is divided into cycles and each team in the league plays each cycle exactly once. The schedule represents a whole season and therefore each pair of teams play against each other twice exactly when in one cycle Group A is the home team and in another cycle Group B is home.

# Additional settings
### The draw of the results of the games
The games in our league will be similar to games in a real basketball league.<br>
Therefore, we will grill results that meet the following requirements.
1. A basic result is a number between 50 and 100.
2. Homegroup score is between 55 and 100.
3. Depending on the talent parameter of the team, after the initial lottery will be added to it up to 10 bonus points.
<br>
I determined the results according to a normal distribution around a certain average with a certain standard deviation.<br>
See the following link (the algorithm I used): https://en.cppreference.com/w/cpp/numeric/random/normal_distribution

### Statistical analysis:
After the season is over, I will present the scoring table arranged according to two parameters in the following order of importance:
1. Ratio of wins and losses
2. Basket difference (points that the team scored fewer points than the team scored)
<br>
Once we've received the results, you have the option to know the following:

1. `topTeams(int)` - Who are the top teams in the league (the number of teams you return to will be according to a parameter you receive from outside)
2. `maxWinningStreak()` - How long was the longest winning streak of the season
3. `maxLossingStreak()` - How long was the longest losing streak of the season
4. `teamsScoredMoreThenGained()` - How many teams scored more points than they scored

## How to run:
1. Clone this repository.
2. In the project folder open the terminal.
3. Write `make main`.
4. Then `./main`
