// attack_difficult.h
#ifndef ATTACK_DIFFICULT_H
#define ATTACK_DIFFICULT_H

// Check the error for input ship location
bool CompTarget(int row, int column);

// Set the location to attack ships
int SetAttackDifficult(int difficulty, int indicator, int load, int &quit);


#endif
