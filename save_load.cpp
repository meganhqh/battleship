// save_load.cpp
// for saving and loading the game status

#include <iostream>
#include <fstream>
#include <string>
#include "save_load.h"
#include "battleship.h"

using namespace std;

// Save the game progress into a savefile.txt
// Input: All variables to keep track of if we load the saved game later, such as at which point user quits, diffculty level, whose turn, which player attacks first, the number of ships inputted, 
// the user and computer game boards and recording boards, the ship placements arrays of user and computer, the attacking position arrays of user and computer,
// number of attacks of user and computers, number of computer ships left, check for computer attacking positions
// Output: save in a lines with spaces in savefile.txt
void SaveFilePlacement(int quit_sequence, int difficulty, int start_player, int indicator, int ship_inputted, char matrix[6][6], char matrixComp[6][6], char recording[6][6], char recordingComp[6][6], string ship_position[3][3], string ship_positionComp[3][3], string *&user_attack, string *&comp_attack, int count_user, int count_comp, int comp_ship_left_last, bool hunt, bool target_N, bool target_S, bool target_E, bool target_W){
  ofstream fout;
  fout.open("savefile.txt");
  if (fout.fail()) {
    cout << "Save fail" << endl;
    exit(1);
  }
  fout << quit_sequence << " " << difficulty << " " << start_player << " " << indicator << " " << ship_inputted;
  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 6; j++)
      fout << matrix[i][j];
  }
  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 6; j++)
      fout << matrixComp[i][j];
  }
  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 6; j++)
      fout << recording[i][j];
  }
  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 6; j++)
      fout << recordingComp[i][j];
  }
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++)
    fout << ship_position[i][j] << " ";
  }
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++)
    fout << ship_positionComp[i][j] << " ";
  }
  if (start_player == 0){
    for (int i = 0; i < indicator/2; i++){
      fout << user_attack[i] << " ";
    }
    for (int i = 0; i < indicator/2; i++){
      fout << comp_attack[i] << " ";
    }
  }else if (start_player == 1){
    for (int i = 0; i < (indicator/2)-1; i++){
      fout << user_attack[i] << " ";
    }
    for (int i = 0; i < indicator/2; i++){
      fout << comp_attack[i] << " ";
    }
  }
  fout << count_user << " " << count_comp << " " << comp_ship_left_last << " " << hunt << " " << target_N << " " << target_S << " " << target_E << " " << target_W;
  fout.close();
}

// Check the validity of the savefile.txt when loading
// Output: return 0 if fail, otherwise return 1
int load_test () {
  string filename = "savefile.txt";
  ifstream fin;
  fin.open(filename);
  if (fin.fail()) {
    cout << "Load fail...." << endl << endl;
    return 0;
  }
  fin.close();
  return 1;
}


// Load the game progress from savefile.txt but checking function is removed, modifying the variables through pass by reference
// Input: All variables to keep track of if we load the saved game later, such as at which point user quits, diffculty level, whose turn, which player attacks first, the number of ships inputted, 
// the user and computer game boards and recording boards, the ship placements arrays of user and computer, the attacking position arrays of user and computer,
// number of attacks of user and computers, number of computer ships left, check for computer attacking positions
// Output: modify all inputs based on savefile.txt
void load_file (int &quit_sequence, int start_player, int &difficulty, int &indicator,  int &ship_inputted, char matrix[6][6], char matrixComp[6][6], char recording[6][6], char recordingComp[6][6], string ship_position[3][3], string ship_positionComp[3][3], string *&user_attack, string *&comp_attack, int &count_user, int &count_comp, int &comp_ship_left_last, bool hunt, bool target_N, bool target_S, bool target_E, bool target_W) {
  string filename = "savefile.txt";
  ifstream fin;
  fin.open(filename);
  fin >> quit_sequence >> difficulty >> start_player >> indicator >> ship_inputted;
  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 6; j++)
      fin >> matrix[i][j];
  }
  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 6; j++)
      fin >> matrixComp[i][j];
  }
  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 6; j++)
      fin >> recording[i][j];
  }
  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 6; j++)
      fin >> recordingComp[i][j];
  }
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++)
      fin >> ship_position[i][j];
  }
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++)
      fin >> ship_positionComp[i][j];
  }
  string *a = new string[36];
  string *b = new string[36];
  if (start_player == 0){
    for (int i = 0; i < indicator/2; i++){
      fin >> a[i];
    }
    for (int i = 0; i < indicator/2; i++){
      fin >> b[i];
    }
  }else if (start_player == 1){
    for (int i = 0; i < (indicator/2)-1; i++){
      fin >> a[i];
    }
    for (int i = 0; i < indicator/2; i++){
      fin >> b[i];
    }
  }
  fin >> count_user >> count_comp >> comp_ship_left_last >> hunt >> target_N >> target_S >> target_E >> target_W;
  fin.close();
  delete []user_attack;
  delete []comp_attack;
  user_attack = a;
  comp_attack = b;
}
