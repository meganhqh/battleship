// save_load.h
#ifndef SAVE_LOAD_H
#define SAVE_LOAD_H

#include <string>

// Save the game progress into a savefile.txt
// Input: difficulty level, indicator (player sequence), ship_inputted, quit sequence
// Input: ships location board, recording board, previous attack positions
// Input: number of times that user/ computer attacks
// Output: save in a lines with spaces in savefile.txt
void SaveFilePlacement(int quit_sequence, int difficulty, int start_player, int indicator, int ship_inputted, char matrix[6][6], char matrixComp[6][6], char recording[6][6], char recordingComp[6][6], std::string ship_position[3][3], std::string ship_positionComp[3][3], std::string *&user_attack, std::string *&comp_attack, int count_user, int count_comp, int comp_ship_left_last, bool hunt, bool target_N, bool target_S, bool target_E, bool target_W);

// Check the validity of the savefile.txt when loading
// Output: return 0 if fail, otherwise return 1
int load_test ();

// Load the game progress from savefile.txt but checking function is removed
// Input: difficulty level, indicator (player sequence), ship_inputted, quit sequence
// Input: ships location board, recording board, previous attack positions
// Input: number of times that user/ computer attacks
// Output: modify all inputs based on savefile.txt
void load_file (int &quit_sequence, int start_player, int &difficulty, int &indicator,  int &ship_inputted, char matrix[6][6], char matrixComp[6][6], char recording[6][6], char recordingComp[6][6], std::string ship_position[3][3], std::string ship_positionComp[3][3], std::string *&user_attack, std::string *&comp_attack, int &count_user, int &count_comp, int &comp_ship_left_last, bool hunt, bool target_N, bool target_S, bool target_E, bool target_W);

#endif
