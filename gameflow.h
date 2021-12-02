// gameflow.h
#ifndef GAMEFLOW_H
#define GAMEFLOW_H

#include <string>

// Starting board at the most beginning
// Initialise all the locations to * without any ship allocation
void StartBoard();

// Prints a horizontal divider to divide the instructions and game
void print_section_divider();

// Prints the game rules and instructions
void print_instructions ();

// Allows the player to choose difficulty level
// Input: difficulty level
// Output: modify the level according to the chosen level
void print_difficulty (int &difficulty);

// Print out the gameboard after ship allocation
// Input: matrix for ship position
// Output: gameboard with ship position
void PrintBoard(char matrix[6][6]);

// Determine which player to attack first
// Input: sequence
// Output: indicator is even when player starts, otherwise odd
void print_player_sequence(int &indicator);

void pause();

// Check if there is ship at the opponent's board when attacking
// 'O' for missing and 'X for successful hitting
// Input: row, column and indicator (whose turn to play the game)
// Output: user/ comp recording board with valid attacking position
bool AttackShips(int row, int column, int indicator);

// Grow array to store more attack position (dynamic array)
// Input: pointer, array size, number to grow
// Output: new array with updated array size
void grow_attack_position(std::string * &ap, int &ap_size, int n);

#endif
