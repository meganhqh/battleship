// setship.h
#ifndef SETSHIP_H
#define SETSHIP_H

#include <string>


// Check the error for input ship location
// Input: input row, column, director and flag_user (determine whose turn to play)
// Output: false for invalid positions
bool CheckError(int row, int column, char direction, int flag_user);

// Change the relevant input position to 'S' and store them in a dynamic array
// Input: vlid ship input position and direction
// Output: modify the gameboard according to the valid row, column and direction
void WriteShipPosition(char matrix[6][6], std::string ship_position[3][3],int ship_number, int row, int column, char direction);

// Set the location of the ship at the early stage
// Input: row, column and direction
// Output: print out the gameboard for valid row, column and direction
int SetShips(int difficulty, int indicator, int load, int &quit);

// Set random input by Computer
void SetCompShips();

#endif
