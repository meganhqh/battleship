// attack_easy.h
#ifndef ATTACK_EASY_H
#define ATTACK_EASY_H

// Set the location to attack ships
// Inputs: difficulty level, indicator (whose turn to play the game), load (if we are loading from load file), and quit (to capture if user quits halfway)
// Output: return 1 if quit halfway, else return 0
int SetAttack(int difficulty, int indicator, int load, int &quit);


#endif
