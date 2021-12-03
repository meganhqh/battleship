// attack_difficult.h
#ifndef ATTACK_DIFFICULT_H
#define ATTACK_DIFFICULT_H

// Check the error for input ship location
// Check the 4 direction surrounded the attacked ship
// Input: valid row and column
// Output: true if there is ship at the specific row and column for targetting, othewise false
bool CompTarget(int row, int column);

// Set the location to attack ships
// Inputs: difficulty level, indicator (whose turn to play the game), load (if we are loading from load file), and quit (to capture if user quits halfway)
// Output: return 1 if quit halfway, else return 0; and successful and insuccessful of hunt and target
int SetAttackDifficult(int difficulty, int indicator, int load, int &quit);


#endif
