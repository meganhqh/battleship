//battleship.cpp
//this is the main program which manages the flow of the game

#include <iostream>
#include <string>
#include <fstream>

#include "gameflow.h"
#include "setship.h"
#include "attack_easy.h"
#include "attack_difficult.h"
#include "save_load.h"
#include "battleship.h"

using namespace std;



const int rows = 6; // fix row for the gameboard
const int columns = 6; // fix column for the gameboard
char matrix[rows][columns]; // user's gameboard
char matrixComp[rows][columns]; // computer's gameboard
char recording[rows][columns]; // computer input location board
char recordingComp[rows][columns]; // user input location board
int count_user = 0; // count the number of attacks by user
int count_comp = 0; // count the number of attacks by computer
int user_ship_left = 3; // count the number of user's ships left
int comp_ship_left = 3; // count the number of computer's ships left
int start_player;
bool winner = false; // check if there is a winner
bool hunt = false; // check if computer attacks the ship position
bool target_N = true; // check the north position when computer attacks
bool target_S = true; // check the south position when computer attacks
bool target_E = true; // check the east position when computer attacks
bool target_W = true; // check the west position when computer attacks

//store ship allocation position
string ship_position[3][3];
string ship_positionComp[3][3];

//store user attack postion
int user_attack_size = 9;
string * user_attack = new string [user_attack_size];

// store computer attack postion
int comp_attack_size = 9;
string * comp_attack = new string [comp_attack_size];



// Main program to call functions
int main(){
  int difficulty, indicator = 0, load_temp = 0, load = 0, quit = 0;
  int play_again = 1;
  // start with making assumptions that the target surrounded by a succesful hunt position has a ship
  bool target_N = true, target_S = true, target_E = true, target_W = true;
  int count = 1; // to count the steps for computer attack
  //
  int quit_sequence=0;

  while (play_again == 1) {

    //print out instructions
    print_instructions();
    if (load_temp == 0) {
      cout << "Do you want to load the saved file? " << endl;
      cout << "1 - Yes" << endl;
      cout << "2 - No" << endl;
      cout << "Load saved file? ";
      cin >> load;
      while (load != 1 && load != 2) {
        cout << "Load saved file? ";
        cin >> load;
      }
      load_temp = 1;

      if (load == 1) {
        load = load_test();
        //load_test return 0 if fail -> return 1 if not fail
        if (load == 1) {
          system("clear");
        }
      } else {
        cout << endl;
      }
    }

    // Allows the player to choose difficulty
    // Only runs if save file is not loaded
    if (load != 1) {
      print_difficulty(difficulty);
      // Starts the main part of the game
      StartBoard();
    }
    else{
      string filename = "savefile.txt";
      ifstream fin;
      fin.open(filename);
      fin >> quit_sequence >> difficulty;
      fin.close();
    }

    //quit during set ship
    if(load!= 1 | quit_sequence == 1){
    //set ship returns 1 if quit halfway
      if(SetShips(difficulty, indicator, load, quit) == 1){
        system("clear");
        return 0;
      }
      cout << "Your game board" << endl;
      PrintBoard(matrix);
      SetCompShips();
      print_player_sequence(indicator);
    }


    if (load!=1 | quit_sequence == 1| quit_sequence == 2){
      if(quit_sequence == 1){
        //reset load back to 0
        load = 0;
      }
      if (difficulty == 1){
        SetAttack(difficulty, indicator, load, quit);
      } else if (difficulty == 2){
        SetAttackDifficult(difficulty, indicator, load, quit);
      }
    }

    load = 2;

    // Ask whether the user wants to play again
    // If user saves and quit in the game_start function, exit immediately
    if (quit != 1) {
      cout << endl << "Do you want to play again?" << endl;
      cout << "1 - Yes" << endl;
      cout << "2 - No" << endl;
      cout << "Play again? ";
      cin >> play_again;
      while (play_again != 1 && play_again != 2) {
        cout << "Play again? ";
        cin >> play_again;
      }
      if (play_again == 1){
        user_ship_left = 3;
        comp_ship_left = 3;
        count_user = 0; // count the number of attacks by user
        count_comp = 0; // count the number of attacks by computer
        hunt = false; // check if computer attacks the ship position
        target_N = true;
        target_S = true;
        target_E = true;
        target_W = true;
        winner = false;
        //store ship allocation position
        ship_position[3][3];
        ship_positionComp[3][3];

        //store user attack postion
        user_attack_size = 9;
        string * user_attack = new string [user_attack_size];

        // store computer attack postion
        comp_attack_size = 9;
        string * comp_attack = new string [comp_attack_size];

        load_temp = 0;
      }
    } else {
      play_again = 2;
    }

    system("clear");
  }

  delete []user_attack;
  delete []comp_attack;

  return 0;
}
