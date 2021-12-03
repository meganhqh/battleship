//setship.cpp
//this program determines the ship placement move of user and computer

#include <iostream>
#include <string>
#include <ctime>

#include "gameflow.h"
#include "quit.h"
#include "save_load.h"
#include "setship.h"
#include "battleship.h"

using namespace std;

// Check the error for input ship location
// Input: input row, column, direction and flag_user (determine whose turn to play)
// Output: False for invalid positions
bool CheckError(int row, int column, char direction, int flag_user){

  //check if row or column input out of bound
  if (row < 0 || column < 0 || row > 5 || column > 5){
    return false;
  }

  //check if the direction input is not north, south, east or west
  if (direction != 'N' && direction != 'S' && direction != 'E' && direction != 'W'){
    return false;
  }

  //check if the direction input for the valid row and column is out of bound
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

  //check if there is a ship at the valid row, column and direction input (repeated input)
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

    // check if there is a ship placed at the input location
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



// Change the relevant input position to 'S' on the ship placement or game board, and also store the coordinates in a ship position array
// Input: a 6x6 grid, an array recording ship position coordinates, valid ship input position and direction
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

    // change to string to store in a dynamic array
    c = column + '0';
    r = row + '0';
    auto pos = string(1,r) + c;

    ship_position[ship_number][ship_pos] = pos;
  }
}


// Set the location of the ship in the first part of the game
// Input: difficulty level, indicator (whose turn), load (whether or not we load previous game), quit (whether or not user quits)
// Output: if user decides to quit, return 1, 0 otherwise
int SetShips(int difficulty, int indicator, int load, int &quit){
  int flag_user = 1, ship_inputted = 0, quit_sequence = 1;
  int comp_ship_left_last=3;

  // if user decides to continue previous game
  if (load == 1) {
    load_file(quit_sequence, difficulty, start_player, indicator, ship_inputted, matrix, matrixComp, recording, recordingComp, ship_position, ship_positionComp, user_attack, comp_attack, count_user, count_comp, comp_ship_left_last, hunt, target_N, target_S, target_E, target_W);
    load = 0;
  }

  for (int i = ship_inputted+1;i < 4; i++){
    int row, column, error;
    char direction;
    cout << "Your game board" << endl;
    PrintBoard(matrix);
    ship_inputted = i-1;

    cout << "Please input the location of the ships. ";
    cout << "[Select 9 to save or quit]" << endl;
    cout << "Ship " << i << ": ";
    
    //input row to place the ship
    cin >> row;

    // if user selects '9' and decides to quit, function ends and returns 1
    while(row == 9){
        if (Quit(quit_sequence, difficulty, start_player, indicator, ship_inputted, matrix, matrixComp, recording, recordingComp, ship_position, ship_positionComp, user_attack, comp_attack, count_user, count_comp, comp_ship_left_last, hunt, target_N, target_S, target_E, target_W) == true){
            quit =1;
            return 1;
        }
        else{
            cout << "Please input the location of the ships. ";
            cout << "[Select 9 to save or quit]" << endl;
            cout << "Ship " << i << ": ";
            cin >> row;
        }
    }
    // input column to place the ship
    cin >> column;
    
    // if user selects '9' and decides to quit, function ends and returns 1
    while(row == 9 | column == 9){
        if (Quit(quit_sequence, difficulty, start_player, indicator, ship_inputted, matrix, matrixComp, recording, recordingComp, ship_position, ship_positionComp, user_attack, comp_attack, count_user, count_comp, comp_ship_left_last, hunt, target_N, target_S, target_E, target_W) == true){
            quit =1;
            return 1;
        }
        else{
            cout << "Please input the location of the ship. ";
            cout << "[Select 9 to save or quit]" << endl;
            cout << "Ship " << i << ": ";
            cin >> row >> column;
        }
    }

    // input direction to place the ship
    cout << "Please choose the direction to place the ship(N, S, E, W). ";
    cout << "[Select 9 to save or quit]" << endl;
    cout << "Direction: ";
    cin >> direction; 
    
    cout << endl;
    
    // if user selects '9' and decides to quit, function ends and returns 1
    while(row == 9 | column == 9 | direction == '9'){
        if (Quit(quit_sequence, difficulty, start_player, indicator, ship_inputted, matrix, matrixComp, recording, recordingComp, ship_position, ship_positionComp, user_attack, comp_attack, count_user, count_comp, comp_ship_left_last, hunt, target_N, target_S, target_E, target_W) == true){
            quit =1;
            return 1;
        }
        else{
            cout << "Please input the location of the ship. ";
            cout << "[Select 9 to save or quit]" << endl;
            cout << "Ship " << i << ": ";
            cin >> row >> column;
            cout << "Please choose the direction to place the ship(N, S, E, W). ";
            cout << "[Select 9 to save or quit]" << endl;
            cout << "Direction: ";
            cin >> direction;
            cout << endl;
        }
    }
    // calls CheckError function to make sure the input row, column and direction are valid
    while ((CheckError(row, column, direction, flag_user) == false) || (error == 1)){
        error = 0;
        cout << "Input error." << endl;

        cout << "Please input the location of the ships. ";
        cout << "[Select 9 to save or quit]" << endl;
        cout << "Ship " << i << ": ";
        // input row to place the ship
        cin >> row;

        // if user selects '9' and decides to quit, function ends and returns 1
        while(row == 9){
            if (Quit(quit_sequence, difficulty, start_player, indicator, ship_inputted, matrix, matrixComp, recording, recordingComp, ship_position, ship_positionComp, user_attack, comp_attack, count_user, count_comp, comp_ship_left_last, hunt, target_N, target_S, target_E, target_W) == true){
                quit =1;
                return 1;
            }
            else{
                cout << "Please input the location of the ships. ";
                cout << "[Select 9 to save or quit]" << endl;
                cout << "Ship " << i << ": ";
                cin >> row;
            }
        }
        // input column to place the ship
        cin >> column;
      
        // if user selects '9' and decides to quit, function ends and returns 1
        while(row == 9 | column == 9){
            if (Quit(quit_sequence, difficulty, start_player, indicator, ship_inputted, matrix, matrixComp, recording, recordingComp, ship_position, ship_positionComp, user_attack, comp_attack, count_user, count_comp, comp_ship_left_last, hunt, target_N, target_S, target_E, target_W) == true){
                quit =1;
                return 1;
            }
            else{
                cout << "Please input the location of the ship. ";
                cout << "[Select 9 to save or quit]" << endl;
                cout << "Ship " << i << ": ";
                cin >> row >> column;
            }
        }

        cout << "Please choose the direction to place the ship(N, S, E, W). ";
        cout << "[Select 9 to save or quit]" << endl;
        cout << "Direction: ";
        // input director to place ship
        cin >> direction; 
        cout << endl;
      
         // if user selects '9' and decides to quit, function ends and returns 1
        while(row == 9 | column == 9 | direction == '9'){
            if (Quit(quit_sequence, difficulty, start_player, indicator, ship_inputted, matrix, matrixComp, recording, recordingComp, ship_position, ship_positionComp, user_attack, comp_attack, count_user, count_comp, comp_ship_left_last, hunt, target_N, target_S, target_E, target_W) == true){
                quit =1;
                return 1;
            }
            else{
                cout << "Please input the location of the ship. ";
                cout << "[Select 9 to save or quit]" << endl;
                cout << "Ship " << i << ": ";
                cin >> row >> column;
                cout << "Please choose the direction to place the ship(N, S, E, W). ";
                cout << "[Select 9 to save or quit]" << endl;
                cout << "Direction: ";
                cin >> direction;
                cout << endl;
            }
        }

        CheckError(row, column, direction, flag_user);
        //check if there is a ship on own board
        //increase error by 1
        if (matrix[row][column] == 'S'){
          error +=1;
        }
    }
    WriteShipPosition(matrix,ship_position,i-1, row, column, direction);
    system("clear");
  }
  return 0;
}


// Set random ship position input by Computer
void SetCompShips(){
  int error, x, y;
  int flag_user = 0;
  char direction;
  char letters[] = "NSEW";
  //set seed and randomise computer input for row, column and direction
  srand(time(NULL));
  for (int i = 1; i < 4; i++){
    x = rand() % rows;
    y = rand() % columns;
    direction = letters[rand() % 4];
    //check if there are errors with the input
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
}
