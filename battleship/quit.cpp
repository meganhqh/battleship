//quit.cpp
//allows users to quit

#include <iostream>
#include <string>
#include "save_load.h"
#include "quit.h"
#include "battleship.h"



using namespace std;



// Quit function when user requests for quit by typing 9
// Input: quit? , save?
// Output: return to the game when user decides not to quit
// Output: modify the savefile.txt if user saves
bool Quit(int quit_sequence, int difficulty, int start_player, int indicator, int ship_inputted, char matrix[6][6], char matrixComp[6][6], char recording[6][6], char recordingComp[6][6], string ship_position[3][3], string ship_positionComp[3][3], string *&user_attack, string *&comp_attack, int count_user, int comp_ship_left_last, bool hunt, bool target_N, bool target_S, bool target_E, bool target_W){
  int quit, save;
  cout << endl << "Are you sure you want to quit?" << endl;
  cout << "1 - Yes" << endl;
  cout << "2 - No" << endl;
  cout << "Exit the game? ";
  cin >> quit;
  // invalid quit input
  while (quit != 1 && quit != 2) {
    cout << "Exit the game? ";
    cin >> quit;
  }
  cout << endl;
  // if user quits, check if they want the game to be saved
  if (quit == 1) {
    cout << "Do you want to save the game?" << endl;
    cout << "1 - Yes" << endl;
    cout << "2 - No" << endl;
    cout << "Save and exit? ";
    cin >> save;

  // invalid save input
  while (save != 1 && save != 2) {
    cout << "Save and exit? ";
    cin >> save;
  }
}
  // save difficulty level, indicator (player sequence), ship_inputted, quit sequence,
  // ships location board, recording board, previous attack positions,number of times that user/ computer attacks
  if (save == 1) {
    SaveFilePlacement(quit_sequence, difficulty, start_player, indicator, ship_inputted, matrix, matrixComp, recording, recordingComp, ship_position, ship_positionComp, user_attack, comp_attack, count_user, comp_ship_left_last, hunt, target_N, target_S, target_E, target_W);
  }
  // close the program
  if (quit == 1){
    return true;
  } else{
    return false;
  }
}
