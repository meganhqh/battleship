// save_load.cpp
// saving and loading the game status

#include <iostream>
#include <fstream>
#include <string>
#include "save_load.h"
#include "battleship.h"

using namespace std;



// Save the game progress into a savefile.txt
// Input: difficulty level, indicator (player sequence), ship_inputted, quit sequence
// Input: ships location board, recording board, previous attack positions
// Input: number of times that user/ computer attacks
void SaveFilePlacement(int quit_sequence, int difficulty, int start_player, int indicator, int ship_inputted, char matrix[6][6], char matrixComp[6][6], char recording[6][6], char recordingComp[6][6], string ship_position[3][3], string ship_positionComp[3][3], string *&user_attack, string *&comp_attack, int count_user, int comp_ship_left_last){
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
  // who starts the game
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
  fout << count_user << " " << comp_ship_left_last;
  fout.close();
}

// Check the validity of the savefile.txt when loading
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


// Load the game progress from savefile.txt but checking function is removed
// Input: difficulty level, indicator (player sequence), ship_inputted, quit sequence
// Input: ships location board, recording board, previous attack positions
// Input: number of times that user/ computer attacks
// Output: modify all inputs based on savefile.txt
void load_file (int &quit_sequence, int start_player, int &difficulty, int &indicator,  int &ship_inputted, char matrix[6][6], char matrixComp[6][6], char recording[6][6], char recordingComp[6][6], string ship_position[3][3], string ship_positionComp[3][3], string *&user_attack, string *&comp_attack, int &count_user, int &comp_ship_left_last) {
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
  fin >> count_user >> comp_ship_left_last;
  fin.close();
  delete []user_attack;
  delete []comp_attack;
  user_attack = a;
  comp_attack = b;
}
