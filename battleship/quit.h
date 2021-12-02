// quit.h
#ifndef QUIT_H
#define QUIT_H

#include <string>


bool Quit(int quit_sequence, int difficulty, int start_player, int indicator, int ship_inputted, char matrix[6][6], char matrixComp[6][6], char recording[6][6], char recordingComp[6][6], std::string ship_position[3][3], std::string ship_positionComp[3][3], std::string *&user_attack, std::string *&comp_attack, int count_user, int comp_ship_left_last);

#endif
