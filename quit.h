// quit.h
#ifndef QUIT_H
#define QUIT_H

#include <string>

// Quit function when user requests to quit by typing 9, allowing the user to save the file
// Input: All variables to keep track of if we load the saved game later, such as at which point user quits, diffculty level, whose turn, which player attacks first, the number of ships inputted, 
// the user and computer game boards and recording boards, the ship placements arrays of user and computer, the attacking position arrays of user and computer,
// number of attacks of user and computers, number of computer ships left, check for computer attacking positions, hunt and target algorithm
// Output: return 1 if quit; return to save function if user chooses to save
bool Quit(int quit_sequence, int difficulty, int start_player, int indicator, int ship_inputted, char matrix[6][6], char matrixComp[6][6], char recording[6][6], char recordingComp[6][6], std::string ship_position[3][3], std::string ship_positionComp[3][3], std::string *&user_attack, std::string *&comp_attack, int count_user,int count_comp, int comp_ship_left_last, bool hunt, bool target_N, bool target_S, bool target_E, bool target_W);

#endif
