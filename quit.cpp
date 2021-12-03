//quit.cpp
//allows users to quit during the game

#include <iostream>
#include <string>
#include "save_load.h"
#include "quit.h"
#include "battleship.h"

using namespace std;

// Quit function when user requests to quit by typing 9, allowing the user to save the file
// Input: All variables to keep track of if we load the saved game later, such as at which point user quits, diffculty level, whose turn, which player attacks first, the number of ships inputted, 
// the user and computer game boards and recording boards, the ship placements arrays of user and computer, the attacking position arrays of user and computer,
// number of attacks of user and computers, number of computer ships left, check for computer attacking positions, hunt and target algorithm
// Output: return 1 if quit; return to save function if user chooses to save
bool Quit(int quit_sequence, int difficulty, int start_player, int indicator, int ship_inputted, char matrix[6][6], char matrixComp[6][6], char recording[6][6], char recordingComp[6][6], string ship_position[3][3], string ship_positionComp[3][3], string *&user_attack, string *&comp_attack, int count_user, int count_comp, int comp_ship_left_last, bool hunt, bool target_N, bool target_S, bool target_E, bool target_W){
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
  // if user wants to save the file, call the SaveFilePlacement function to save the file
  if (save == 1) {
    SaveFilePlacement(quit_sequence, difficulty, start_player, indicator, ship_inputted, matrix, matrixComp, recording, recordingComp, ship_position, ship_positionComp, user_attack, comp_attack, count_user, count_comp, comp_ship_left_last, hunt, target_N, target_S, target_E, target_W);
  }
  // close the program if user wants to quit, and return to the game otherwise
  if (quit == 1){
    return true;
  } else{
    return false;
  }
}
