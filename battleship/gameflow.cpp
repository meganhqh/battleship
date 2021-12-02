// gameflow.cpp
// This program manages other stages of the game flow, such as:
// initialise start board, printing instructions, asking player to choose difficulty level, asking player to choose playing sequence, printing boards, having a pause on the screen,
// printing that it is a "hit" or "miss" when attacking ships, growing our dynamic array to record attacking movements

#include <iostream>
#include <string>
#include <limits>
#include "gameflow.h"
#include "battleship.h"

using namespace std;

// Initialise all the locations to * without any ship allocation for our ship placement and recording boards at the start
void StartBoard(){
  for(int i=0; i < rows; i++){
    for(int j=0; j < columns; j++){
      matrix[i][j] = '*';
      matrixComp[i][j] = '*';
      recording[i][j] = '*';
      recordingComp[i][j] = '*';
    }
  }
}

// Prints a horizontal divider
void print_section_divider() {
  for (int i = 0; i < 120; i++ ) {
    cout << "=";
  }
  cout << endl;
}

// Prints the game rules and instructions
void print_instructions () {
  system("clear");
  print_section_divider();
  cout << "Welcome to Battleship" << endl;
  print_section_divider();
  cout << "Game Guide:" << endl;
  cout << "1) The game is played by 2 players, the computer and player." << endl;
  cout << "2) Each player has 2 boards: Game Board: to place the ships & Recording Board: to show if guess is a hit or miss." <<  endl;
  cout << "3) Each board size is a 6x6 grid (6 rows and 6 columns)." << endl;
  cout << "4) Each player will first place 3 ships on their own game board. Each ship occupies 3 spaces on the board." << endl;
  cout << "5) Player will place the ships by inputting the row and column number of the first position of the ship, " << endl;
  cout << "   followed by the orientation (North, South, East and West) of the ship." << endl;
  cout << "6) Ships cannot be placed overlapping with each other." << endl;
  cout << "7) The location of ships on the game board for both computer and player is hidden from each other." << endl;
  cout << "8) After placing the ships, player and computer will alternate turns to call out a row and column number." << endl;
  cout << "9) If the row and column number correspond to a space occupy by a ship, the specific coordinate on the recording board" << endl;
  cout << "   will be a 'X'(hit); otherwise, '0'(miss)." << endl;
  cout << "11) Once all coordinates occupy by the ship are guessed correctly, the ship is sunk." << endl;
  cout << "12) The first player to sink all 3 ships of the opponent will win the game." << endl;
  print_section_divider();
}

// Allows the player to choose difficulty level, modifying the level according to the chosen level through pass by reference
// Input: difficulty level
void print_difficulty (int &difficulty) {
  cout << "Please select your difficulty:" << endl;
  cout << "1 - Easy" << endl;
  cout << "2 - Hard" << endl;
  cout << "Difficulty? ";
  cin >> difficulty;
  while (difficulty != 1 && difficulty != 2) {
    cout << "Difficulty? ";
    cin >> difficulty;
  }
  print_section_divider();
  system("clear");
}

// Print out our game and recording boards
// Input: a 6x6 grid
void PrintBoard(char matrix[6][6]){
  cout << "  ";
  for (int i = 0; i<6; i++){
    cout << i << " ";
  }
  cout << endl;
  for(int i=0; i < 6; i++){
    cout << i << " ";
    for(int j=0; j < 6; j++){
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
}

// Determine which player to attack first, changing indicator to even when player starts, otherwise odd
// Input: indicator 
void print_player_sequence(int &indicator){
  int sequence;
  cout << endl << "Do you want to attack first?" << endl;
  cout << "1 - Yes" << endl;
  cout << "2 - No" << endl;
  cout << "Attack first? ";
  cin >> sequence;
  while (sequence != 1 && sequence != 2) {
    cout << "Attack first? ";
    cin >> sequence;
  }
  if (sequence == 1) {
    indicator = 0;
    start_player = 0;
  }
  else {
    indicator = 1;
    start_player = 1;
  }
  system("clear");
}

// To make the screen pause by having the player press enter to continue
void pause(){
   cout<<"Press <enter> to continue:";
   // ensure that cin is ready for inputs
   cin.clear();
   // ignore  pressed key until enter key
   cin.ignore(numeric_limits<streamsize>::max(), '\n');
}


// Check if there is ship at the opponent's board when attacking, printing out it's a miss or it's a hit, and change position on recording board to 'O' for missing and 'X for successful hitting
// Input: row, column and indicator (whose turn to play the game)
// Output: return true if computer hit, false otherwise and if user's turn
bool AttackShips(int row, int column, int indicator){
  if (indicator % 2 == 0){
    // user's turn
    if(matrixComp[row][column] == 'S')
    {
      recording[row][column] = 'X';
      cout << endl;
      cout << "It's a hit!" << endl;
      cout << endl;
    }else{
      recording[row][column] = 'O';
      cout << endl;
      cout << "It's a miss." << endl;
      cout <<  endl;
    }
    return 0;
  }else{
    // computer's turn
    if(matrix[row][column] == 'S')
    {
      hunt = true;
      recordingComp[row][column] = 'X';
      cout << endl;
      cout << "Computer gets a hit." << endl;
      cout << endl;
      cout << "Computer Recording Board" << endl;
      PrintBoard(recordingComp);
      return true;
    }else{
      recordingComp[row][column] = 'O';
      cout << endl;
      cout << "Computer gets a miss." << endl;
      cout << endl;
      cout << "Computer Recording Board" << endl;
      PrintBoard(recordingComp);
      return false;
    }
  }
}


// Grow array to store more attacking position (dynamic array)
// Input: pointer, array size, number to grow
void grow_attack_position(string * &ap, int &ap_size, int n){
	// create a new dynamic array with a new size = old size + n
	string * ap_new = new string[ap_size + n];
	// copy all the records from the original array to the new dynamic array
	for (int i = 0; i < ap_size; i++){
		ap_new[i] = ap[i];
	}
	// destroy old dynamic array to free up the memory allocated to it
	delete [] ap;
	// assign the pointer to the new dynamic array to the pointer variable
	ap = ap_new;
	// update the size of the array
	ap_size += n;
}
