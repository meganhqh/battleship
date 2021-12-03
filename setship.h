// setship.h
#ifndef SETSHIP_H
#define SETSHIP_H

#include <string>


// Check the error for input ship location
// Input: input row, column, director and flag_user (determine whose turn to play)
// Output: false for invalid positions
bool CheckError(int row, int column, char direction, int flag_user);

// Change the relevant input position to 'S' on the ship placement or game board, and also store the coordinates in a ship position array
// Input: a 6x6 grid, an array recording ship position coordinates, valid ship input position and direction
void WriteShipPosition(char matrix[6][6], std::string ship_position[3][3],int ship_number, int row, int column, char direction);

// Set the location of the ship in the first part of the game
// Input: difficulty level, indicator (whose turn), load (whether or not we load previous game), quit (whether or not user quits)
// Output: if user decides to quit, return 1, 0 otherwise
int SetShips(int difficulty, int indicator, int load, int &quit);

// Set random ship position input by Computer
void SetCompShips();

#endif
