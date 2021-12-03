// check_winner.h
#ifndef CHECK_WINNER_H
#define CHECK_WINNER_H

#include <string>

// Check who is the winner by determining the number of ships left in both player's board
// Input: valid attacking position, indicator (whose turn to play the game)
// Output: number of ships left in computer's board
int CheckWinner(std::string position, int indicator);

#endif
