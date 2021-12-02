// check_winner.h
#ifndef CHECK_WINNER_H
#define CHECK_WINNER_H

#include <string>


// Check who is the winner by eliminating from the dynamic array according to the attack position
// Input: valid attacking position, indicator (whose turn to play the game)
// Output: winner in the game?
int CheckWinner(std::string position, int indicator);

#endif
