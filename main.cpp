// game_manager.cpp
// This program manages all stages of the game flow
#include <iostream>
#include <ctime>
#include <string>
#include <fstream>

//include header file here//
using namespace std;

const int rows = 6;
const int columns = 6;
char matrix[rows][columns]; // user's gameboard
char matrixComp[rows][columns]; // computer's gameboard
char recording[rows][columns]; // computer input location board
char recordingComp[rows][columns]; // user input location board
int indicator; // indicate who starts first, if user starts first, indicator = 1; if comp starts first, indicator = 0
int count_user = 0; // count the number of attacks by user
int count_comp = 0; // count the number of attacks by computer
int user_ship_left = 3; // count the number of user's ships left
int comp_ship_left = 3; // count the number of comp's ships left
bool winner = false; //check if there is a winner

//store ship allocation position
string ship_position[3][3];
string ship_positionComp[3][3];

//store user attack postion
int user_attack_size = 9;
string * user_attack = new string [user_attack_size];

// store computer attack postion
int comp_attack_size = 9;
string * comp_attack = new string [comp_attack_size];

// Prints a horizontal divider
// later put in print_board file
void print_section_divider() {
  for (int i = 0; i < 100; i++ ) {
    cout << "=";
  }
  cout << endl;
}

// Prints the game rules and instructions
void print_instructions () {
  // system("clear");
  print_section_divider();
  cout << "Welcome to Battleship" << endl;
  print_section_divider();
  cout << "Game Guide:" << endl;
  cout << "1) The game is played by 2 players, the computer and player." << endl;
  cout << "2) Each player has 2 boards: Game Board & Recording Board. Game Board - place the ships. Recording Board - show if the guess is a hit or miss." << endl;
  cout << "3) Each board size is a 6x6 grid (6 rows and 6 columns). Rows are denoted by numbers and columns are denoted by alphabets." << endl;
  cout << "4) There are 3 ships for player to place on the board. Each ship occupies different number of spaces with battleships, cruisers and submarines occupying 3 spaces, 3 spaces and 2 spaces respectively." << endl;
  cout << "5) Player will first place the 3 ships on the game board by inputting the row number and column alphabet of the first position of the ship, and the orientation of the ship." << endl;
  cout << "6) Ships can only be placed vertically and horizontally, but not diagonally or overlapping with each other." << endl;
  cout << "7) 'Invalid input' prints out if player fails to place the ship correctly by violating the rules." << endl;
  cout << "8) Player's and computer's game board is hidden from each other." << endl;
  cout << "9) Player and computer alternate turns to call out a row number and column alphabet." << endl;
  cout << "10) If the row number and column alphabet correspond to a space occupy by a ship, the specific coordinate on the recording board will be a 'X'(hit); otherwise, '0'(miss)." << endl;
  cout << "11) Once all coordinates occupy by the ship are guessed correctly, the ship is sunk." << endl;
  cout << "12) The first player to sink all 3 ships of the opponent will win the game." << endl;
  print_section_divider();
}

// Allows the player to choose difficulty level and starting order
// Input: difficulty level
void print_difficulty (int &difficulty) {
  cout << "Please select your difficulty:" << endl;
  cout << "1 - Easy" << endl;
  cout << "2 - Medium" << endl;
  cout << "3 - Hard" << endl;
  cout << "Difficulty? ";
  cin >> difficulty;
  while (difficulty != 1 && difficulty != 2 && difficulty !=3) {
    cout << "Difficulty? ";
    cin >> difficulty;
  }
  print_section_divider();
  // system("clear");
}

// Change the relevant position to 'S' and store them in a dynamic array
void WriteShipPosition(char matrix[6][6], string ship_position[3][3],int ship_number, int row, int column, char direction){
  matrix[row][column] = 'S';
  char r, c;
  c = column + '0';
  r = row + '0';
  auto pos = string(1,r) + c;

  int ship_pos=0;
  ship_position[ship_number][ship_pos] = pos;

  for (int k = 0; k < 2; k++){
    ship_pos += 1;

    if (direction == 'N'){
      row--;
    } else if (direction == 'S'){
      row++;
    } else if (direction == 'E'){
      column++;
    } else if (direction == 'W'){
      column--;
    }
    matrix[row][column] = 'S';

    c = column + '0';
    r = row + '0';
    auto pos = string(1,r) + c;

    ship_position[ship_number][ship_pos] = pos;
  }
}

// Print out the board after ship allocation
void PrintBoard(char matrix[6][6]){
  for(int i=0; i < 6; i++){
    for(int j=0; j < 6; j++){
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
}

// Show recording board (opponent's board) when attacking
void ShowRecording(int row, int column){
  // cout << "Recording Board" << endl;
  for(int i=0; i < rows; i++){
    for(int j=0; j < columns; j++){
      if (indicator % 2 == 0){
        cout << recording[i][j] << " ";  // visualise user attack towards computer
      } else{
        cout << recordingComp[i][j] << " "; // visualise computer attack towards user
      }
    }
  cout << endl;
  }
  cout << endl;
}

// Check the error for location input
bool CheckError(int row, int column, char direction, int flag_user){

  //check row and column input
  if (row < 0 || column < 0 || row > 5 || column > 5){
    return false;
  }
  // condition of wrong direction input
  if (direction != 'N' && direction != 'S' && direction != 'E' && direction != 'W'){
    return false;
  }
  //check if the direction input is out of bound
  int temp_row, temp_column;
  temp_row = row;
  temp_column = column;

  if (direction == 'N'){
    temp_row-=2;
  } else if (direction == 'S'){
    temp_row+=2;
  } else if (direction == 'E'){
    temp_column+=2;
  } else if (direction == 'W'){
    temp_column-=2;
  }

  if (temp_row < 0 || temp_column < 0 || temp_row > 5 || temp_column > 5){
    return false;
  }

  // check location and direction input
  temp_row = row;
  temp_column = column;
  int count = 0;
  for (int k = 0; k < 3; k++){
    if (direction == 'N'){
      temp_row -= count;
    } else if (direction == 'S'){
      temp_row += count;
    } else if (direction == 'E'){
      temp_column += count;
    } else if (direction == 'W'){
      temp_column -= count;
    }
    count = 1;

    if (flag_user == 1){
      if (matrix[temp_row][temp_column] == 'S'){
        return false;
      }
    }else{
      if (matrixComp[temp_row][temp_column] == 'S'){
        return false;
      }
    }
  }
  return true;
}

//Save file when user chooses to quit during ship placement
void SaveFilePlacement(int difficulty, char matrix[6][6], char matrixComp[6][6]){
  ofstream fout;
  fout.open("savefile.txt");
  if (fout.fail()) {
    cout << "Save fail" << endl;
    exit(1);
  }
  fout << difficulty << endl;
  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 6; j++)
      fout << " " << matrix[i][j];
  }
  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 6; j++)
      fout << " " << matrixComp[i][j];
  }
  fout.close();
}

// Quit file
void Quit(int difficulty, char matrix[6][6], char matrixComp[6][6]){
  int quit, save;
  cout << endl << "Are you sure you want to quit?" << endl;
  cout << "1 - Yes" << endl;
  cout << "2 - No" << endl;
  cout << "Exit the game? ";
  cin >> quit;
  while (quit != 1 && quit != 2) {
    cout << "Exit the game? ";
    cin >> quit;
  }
  cout << endl;
  if (quit == 1) {
    cout << "Do you want to save the game?" << endl;
    cout << "1 - Yes" << endl;
    cout << "2 - No" << endl;
    cout << "Save and exit? ";
    cin >> quit;
  }
  while (quit != 1 && quit != 2) {
    cout << "Save and exit? ";
    cin >> quit;
  }
  if (quit == 1) {
    SaveFilePlacement (difficulty, matrix, matrixComp);
  }
  save = 1;
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
  return 1;
  fin.close();
}

// Load the game progress from savefile.txt but checking function is removed
void load_file (int *&difficulty, char *&matrix, char *&matrixComp) {
  string filename = "savefile.txt";
  ifstream fin;
  fin.open(filename);
  fin >> difficulty  >> endl;
  int ** a = new int*[row];
  for (int i = 0; i < row; i++) {
    a[i] = new int[col];
    fin >> a[i];
  }
  fin.close();
  for (int i = 0; i < row; i++) {
    delete [] a[i];
  }
  delete [] a;
}
// Set the location of the ship
int SetShips(int difficulty){
  int flag_user = 1;
  cout << "Please input the location of the ships. " << endl;
  for (int i = 1; i < 4; i++){
    int row, column, error;
    char direction;
    cout << "Ship " << i << ": ";
    cin >> row >> column;
    cout << "Please choose the direction to place the ship(N, S, E, W) ";
    cout << "[Select Q to save or quit]: ";
    cin >> direction;
    if( direction == 'Q'){
      Quit(difficulty, matrix, matrixComp);
      return 1;
    }
    while ((CheckError(row, column, direction, flag_user) == false) || (error == 1)){
        error = 0;
        cout << "Input error. Please input the location again: " << endl;
        cout << "Ship " << i << ": "; cin >> row >> column;
        cout << "Please choose the direction to place the ship(N, S, E, W): "; cin >> direction;
        CheckError(row, column, direction, flag_user);
        //check if there is a ship on own board
        if (matrix[row][column] == 'S'){
          error +=1;
        }
    }
    WriteShipPosition(matrix,ship_position,i-1, row, column, direction);
    PrintBoard(matrix);
  }
  return 0;
}

// Starting board at the most beginning
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

// Set random input by Computer
void SetCompShips(){
  int error, x, y;
  int flag_user = 0;
  char direction;
  char letters[] = "NSEW";
  for (int i = 1; i < 4; i++){
    x = rand() % rows;
    y = rand() % columns;
    direction = letters[rand() % 4];
    while ((CheckError(x,y, direction, flag_user) == false) || (error == 1)){
      error = 0;
      x = rand() % rows;
      y = rand() % columns;
      direction = letters[rand() % 4];
      CheckError(x,y, direction, flag_user);
      if (matrixComp[x][y] == 'S'){
        error +=1;
      }
    }
    WriteShipPosition(matrixComp,ship_positionComp,i-1, x, y, direction);
  }
  // Print computer's starting board
  cout << endl;
  cout << "Opponent's board" << endl;
  PrintBoard(matrixComp);
}

// Check who is the winner by eliminating from the dynamic array according to the attack position
void CheckWinner(string position){
  for (int i = 0; i < 3; i++){
    for (int j = 0; j < 3; j++){
      if (indicator % 2 == 0){
        if (ship_positionComp[i][j] == position){
          ship_positionComp[i][j] = 'N';
        }
      }else{
        if (ship_position[i][j] == position){
          ship_position[i][j] = 'N';
        }
      }
    }
  }

  for (int i = 0; i < 3; i++){

    int sink_ship = 0;

    for (int j = 0; j < 3; j++){
      if (indicator % 2 == 0){
        if (ship_positionComp[i][j] == "N"){
          sink_ship++;
        }
      }else{
        if (ship_position[i][j] == "N"){
          sink_ship++;
        }
      }
    }

    if (indicator % 2 == 0){
      if (sink_ship == 3){
        comp_ship_left = comp_ship_left - 1;
      }
    }else{
      if (sink_ship == 3){
        user_ship_left = user_ship_left - 1;
      }
    }
  }

  if (indicator % 2 == 0){
    cout << "Number of ships left: " << comp_ship_left << endl;
    cout << endl;
  }else{
    cout << "Number of ships left: " << comp_ship_left << endl;
    cout << endl;
  }

  // if all 3 ships are being hit
  if (user_ship_left == 0){
    cout << "Congratulatons! Computer wins!" << endl;
    winner = true;
  } else if (comp_ship_left == 0){
    cout << "Congratulations! User wins!" << endl;
    winner = true;
  }
}

// Determine which player to attack first
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
  }
  else {
    indicator = 1;
  }
  // system("clear");
}

// Check if there is ship at the opponent's board when attacking
// 'O' for missing and 'X for successful hitting
bool AttackShips(int row, int column){
  if (indicator % 2 == 0){
    if(matrixComp[row][column] == 'S')
    {
      recording[row][column] = 'X';
    }else{
      recording[row][column] = 'O';
    }
    cout << "User Recording Board" << endl;
  }else{
    if(matrix[row][column] == 'S')
    {
      recordingComp[row][column] = 'X';
    }else{
      recordingComp[row][column] = 'O';
    }
    cout << "Computer Recording Board" << endl;
  }
  ShowRecording(row, column);
  return 0;
}

// Grow array to store more attack position
void grow_attack_position(string * &ap, int &ap_size, int n){
	// create a new dynamic array with a new size = max_size + n
	string * ap_new = new string[ap_size + n];

	// copy all the records from the original array to the new dynamic array
	for (int i = 0; i < ap_size; i++){
		ap_new[i] = ap[i];
	}

	// destroy the old dynamic array to free up the memory allocated to it
	delete [] ap;

	// assign the pointer to the new dynamic array to the pointer variable
	ap = ap_new;

	// update the size of the array
	ap_size += n;
}

// Set the location to attack ships
int SetAttack(int difficulty){
  int row, column, x, y;
  int duplicate = 0;
  bool valid = true;
  while(valid){
    if (indicator % 2 == 0){
      cout << "[Select -1 to save or quit]";
      cout << "Please input the location of the ships to attack: " << endl;
      cout << "Location: "; cin >> row >> column;
      if( column == -1){
        Quit(difficulty, matrix, matrixComp);
        return 1;
      }
      if (row < 0 || column < 0 || row > 5 || column > 5){
        cout << "Incorrect input. Please input the location again." << endl;
      }else{
        char r = row + '0';
        char c = column + '0';
        auto pos = string(1,r) + c;
        for (int i = 0; i < count_user; i++){
          if (pos == user_attack[i]){
            duplicate++;
            cout << "Input repeated. Please try again." << endl;
            break;
          }
        }
        // No duplicates of input attack position
        if (duplicate == 0){
          if (count_user >= user_attack_size){
            grow_attack_position(user_attack, user_attack_size, 3);
          }
          //append
          user_attack[count_user] = pos;
          AttackShips(row, column);
          CheckWinner(pos);
          if (winner == true){
            break;
          }
          valid == false;
          indicator++;
          count_user++;
        }
        duplicate = 0;
        user_ship_left = 3;
      }
    } else {
      x = rand() % rows;
      y = rand() % columns;
      cout << "Show computer attack position: " << x << " " << y << endl;
      char r = x + '0';
      char c = y + '0';
      auto pos1 = string(1,r) + c;
      for (int i = 0; i < count_comp; i++){
        if (pos1 == comp_attack[i]){
          duplicate++;
          cout << "Input repeated. Please try again." << endl;
          break;
        }
      }
      // No duplicates of input attack position
      if (duplicate == 0){
        if (count_user >= comp_attack_size){
          grow_attack_position(comp_attack, comp_attack_size, 3);
        }
        comp_attack[count_comp] = pos1;
        AttackShips(x, y);
        CheckWinner(pos1);
        if (winner == true){
          break;
        }
        valid == false;
        indicator++;
        count_comp++;
      }
      duplicate = 0;
      comp_ship_left=3;
    }
  }
  return 0;
}

// Main program to call functions
int main(){
  int difficulty = 0, load_temp = 0, load = 0;

  //print out instructions
  print_instructions();

  if (load_temp == 0) {
      cout << "Do you want to load the saved file? " << endl;
      cout << "1 - Yes" << endl;
      cout << "2 - No" << endl;
      cout << "Load save file? ";
      cin >> load;
      while (load != 1 && load != 2) {
        cout << "Load save file? ";
        cin >> load;
      }
      load_temp = 1;
      if (load == 1) {
        load = load_test();
        //load_test return 0 if fail -> return 1 if not fail
        if (load == 1) {
          system("clear");
        }
      }
        else {
          cout << endl;
        }
      }
    // Allows the player to choose difficulty
    // Only runs if save file is not loaded
    if (load != 1) {
      print_difficulty (difficulty);
    }

    // Starts the main part of the game
    StartBoard();
    //SetShips(difficulty);

    //return 1 if quit
    if(SetShips(difficulty) == 1){
      return 0;
    }

    SetCompShips();
  // cout << "My ship placement: " ;
  // for(int i=0; i < 3; i++){
  //   for(int j=0; j < 3; j++){
  //     cout << ship_position[i][j] << " ";
  //   }
  // }
  // cout << endl;
  // cout << "Comp ship placement: " ;
  // for(int i=0; i < 3; i++){
  //   for(int j=0; j < 3; j++){
  //     cout << ship_positionComp[i][j] << " ";
  //   }
  // }
  // cout << endl;
    print_player_sequence(indicator);
    SetAttack(difficulty);
    delete [] user_attack;
    delete [] comp_attack;
    return 0;
  //code
}
