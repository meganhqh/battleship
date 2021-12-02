//attack_easy.cpp
//this program determines the attacking move if user select "easy" level
//computer uses random guessing in easy level

#include <iostream>
#include <ctime>
#include <string>

#include "gameflow.h"
#include "check_winner.h"
#include "save_load.h"
#include "quit.h"
#include "attack_easy.h"
#include "battleship.h"

using namespace std;


// Set the location to attack ships
// Inputs: difficulty level, indicator (whose turn to play the game), load (if we are loading from load file), and quit (to capture if user quits halfway)
// Output: return 1 if quit halfway, else return 0
int SetAttack(int difficulty, int indicator, int load, int &quit){
  int row, column, x, y;
  int duplicate = 0, count_user = 0, count_comp =0, attack_num = 0;
  bool repeat = false;
  int ship_inputted = 4, quit_sequence = 2, comp_ship_left_last=3;
  bool valid = true;
  while(valid){
    int duplicate_last = 0;
    int incorrect = 0;
    
    // check if user wants to load from previous game
    if (load == 1) {
      load_file(quit_sequence, difficulty, start_player, indicator, ship_inputted, matrix, matrixComp, recording, recordingComp, ship_position, ship_positionComp, user_attack, comp_attack, count_user, count_comp,comp_ship_left_last, hunt, target_N, target_S, target_E, target_W);
      user_attack_size = count_user - (count_user % 3);
      comp_attack_size = count_comp - (count_comp % 3);
      cout << "Your ship placement board" << endl;
      PrintBoard(matrix);
      load = 0;
    }
    
    // check whose turn to play
    if (indicator % 2 == 0){
      if(repeat == false){
        cout << "Your Recording Board" << endl;
        PrintBoard(recording);
        cout << "Number of ships left: " << comp_ship_left_last << endl;
        cout << endl;
      }
      cout << "Please input the location of the ships to attack. ";
      cout << "[Select 9 to save or quit]" << endl;
      cout << "Location: ";
      cin >> row;
      // check if user wants to quit with 9 in input row
      while(row == 9){
        if (Quit(quit_sequence, difficulty, start_player, indicator, ship_inputted, matrix, matrixComp, recording, recordingComp, ship_position, ship_positionComp, user_attack, comp_attack, count_user, count_comp,comp_ship_left_last, hunt, target_N, target_S, target_E, target_W) == true){
          quit =1;
          return 1;
        }
        else{
          cout << "Please input the location of the ships to attack. ";
          cout << "[Select 9 to save or quit]" << endl;
          cout << "Location: ";
          cin >> row;
        }
      }
      cin >> column;
      // check if user wants to quit with 9 in input column
      while(column == 9){
        if (Quit(quit_sequence, difficulty, start_player, indicator, ship_inputted, matrix, matrixComp, recording, recordingComp, ship_position, ship_positionComp, user_attack, comp_attack, count_user,count_comp, comp_ship_left_last, hunt, taregt_N, target_S, target_E, target_W) == true){
          quit =1;
          return 1;
        }
        else{
          cout << "Please input the location of the ships to attack. ";
          cout << "[Select 9 to save or quit]" << endl;
          cout << "Location: ";
          cin >> row >> column;
        }
      }
      
      // check if the input row and column is in the valid range
      if (row < 0 || column < 0 || row > 5 || column > 5){
        cout << "Incorrect input. Please input the location again." << endl;
        incorrect = 1;
        repeat = true;
      }else{
        // convert valid row and column to string
        char r = row + '0';
        char c = column + '0';
        auto pos = string(1,r) + c;
        // check if there are duplicates from the dynamic array which stores all the attack positions
        for (int i = 0; i < count_user; i++){
          if (pos == user_attack[i]){
            duplicate++;
            duplicate_last = duplicate;
            incorrect = 1;
            repeat = true;
            cout << "Input repeated. Please try again." << endl;
            break;
          }
        }
        // If no duplicates of input attack position
        if (duplicate == 0){
          repeat = false;
          attack_num++;
          // check if the number of user's attacks is larger than the array size which stores all attack positions, and grow array if so
          if (count_user >= user_attack_size){
            grow_attack_position(user_attack, user_attack_size, 3);
          }
          
          //write attack position in the dynamic array
          user_attack[count_user] = pos;
          //call AttackShips function which checks if the attack is a hit or miss and prints out the recording board
          AttackShips(row, column, indicator);
          //call CheckWinner function which determines the number of ships left in opponent's board and also determine a winner (whoever makes opponent's ship count go to zero first).
          comp_ship_left_last = CheckWinner(pos, indicator);

          //if winner could be determined, the loop breaks and will stop inputting an attacking position.
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
        //set seed and randomise computer's attack move
        srand(time(NULL));
        x = rand() % rows;
        y = rand() % columns;
        char r = x + '0';
        char c = y + '0';
        // check if there are duplicates from the dynamic array which stores all the attack positions
        auto pos1 = string(1,r) + c;
        for (int i = 0; i < count_comp; i++){
            if (pos1 == comp_attack[i]){
            duplicate++;
            incorrect = 1;
            break;
            }
        }
        // If no duplicates of input attack position
        if (duplicate == 0){
          attack_num++;
          // check if the number of computer's attacks is larger than the array size which stores all attack positions, and grow array if so
          if (count_user >= comp_attack_size){
            grow_attack_position(comp_attack, comp_attack_size, 3);
          }
          //write attack position in the dynamic array
          comp_attack[count_comp] = pos1;
          cout << "Computer attacks at position: " << x << " " << y << endl;
          //call AttackShips function which checks if the attack is a hit or miss and prints out the recording board
          AttackShips(x, y,indicator);
          //call CheckWinner function which determines the number of ships left in opponent's board and also determine a winner (whoever makes opponent's ship count go to zero first).
          CheckWinner(pos1, indicator);
          //if winner could be determined, the loop breaks and will stop inputting an attacking position.
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
    // clear the screen after two players have played their turn
    if(attack_num % 2 == 0 && duplicate_last == 0 && incorrect!= 1){
      string str;
      getline(cin, str);
      pause();
      system("clear");
    }
    //print a section divider after one player has played their turn
    if(attack_num % 2 != 0 && duplicate_last == 0 && incorrect != 1){
      print_section_divider();
    }
  }
  return 0;
}
