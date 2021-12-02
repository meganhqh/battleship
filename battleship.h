#ifndef BATTLESHIP_H
#define BATTLESHIP_H

#include <string>

extern const int rows; // fix row for the gameboard
extern const int columns; // fix column for the gameboard
extern char matrix[6][6]; // user's gameboard
extern char matrixComp[6][6]; // computer's gameboard
extern char recording[6][6]; // computer input location board
extern char recordingComp[6][6]; // user input location board
extern int count_user; // count the number of attacks by user
extern int count_comp; // count the number of attacks by computer
extern int user_ship_left; // count the number of user's ships left
extern int comp_ship_left; // count the number of computer's ships left
extern int start_player;
extern bool winner; // check if there is a winner
extern bool hunt; // check if computer attacks the ship position
extern bool target_N; // check the north position when computer attacks
extern bool target_S; // check the south position when computer attacks
extern bool target_E; // check the east position when computer attacks
extern bool target_W; // check the west position when computer attacks

//store ship allocation position
extern std::string ship_position[3][3];
extern std::string ship_positionComp[3][3];

//store user attack postion
extern int user_attack_size;
extern std::string * user_attack;

// store computer attack postion
extern int comp_attack_size;
extern std::string * comp_attack;


#endif
