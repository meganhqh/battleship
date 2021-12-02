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
// Input: difficulty, indicator (whose turn to play the game), load, quit
// Output
int SetAttack(int difficulty, int indicator, int load, int &quit){
  int row, column, x, y;
  int duplicate = 0, count_user = 0, count_comp =0, attack_num = 0;
  bool repeat = false;
  //temporary
  int ship_inputted = 4, quit_sequence = 2, comp_ship_left_last=3;
  bool valid = true;
  while(valid){
    int duplicate_last = 0;
    int incorrect = 0;
    if (load == 1) {
      load_file(quit_sequence, difficulty, start_player, indicator, ship_inputted, matrix, matrixComp, recording, recordingComp, ship_position, ship_positionComp, user_attack, comp_attack, count_user, comp_ship_left_last, hunt, target_N, target_S, target_E, target_W);
      user_attack_size = count_user - (count_user % 3);
      comp_attack_size = count_comp - (count_comp % 3);
      // for (int i = 0; i < 6; i++){
      //   cout << user_attack << " ";
      // }
      // for (int i = 0; i < 6; i++){
      //   cout << comp_attack << " ";
      // }

      cout << "Your ship placement board" << endl;
      PrintBoard(matrix);
      // cout << "Your recording board" << endl;
      // PrintBoard(recording);
      load = 0;
    }
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
      while(row == 9){
        if (Quit(quit_sequence, difficulty, start_player, indicator, ship_inputted, matrix, matrixComp, recording, recordingComp, ship_position, ship_positionComp, user_attack, comp_attack, count_user, comp_ship_left_last, hunt, target_N, target_S, target_E, target_W) == true){
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
      while(column == 9){
        if (Quit(quit_sequence, difficulty, start_player, indicator, ship_inputted, matrix, matrixComp, recording, recordingComp, ship_position, ship_positionComp, user_attack, comp_attack, count_user, comp_ship_left_last, hunt, taregt_N, target_S, target_E, target_W) == true){
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

      if (row < 0 || column < 0 || row > 5 || column > 5){
        cout << "Incorrect input. Please input the location again." << endl;
        incorrect = 1;
        repeat = true;
      }else{
        char r = row + '0';
        char c = column + '0';
        auto pos = string(1,r) + c;
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
        if (duplicate == 0){
          repeat = false;
          attack_num++;
          if (count_user >= user_attack_size){
            grow_attack_position(user_attack, user_attack_size, 3);
          }

          user_attack[count_user] = pos;
          AttackShips(row, column, indicator);
          comp_ship_left_last = CheckWinner(pos, indicator);
          //cout << "immediately after check winner in SA" << comp_ship_left_last << endl;
          if (winner == true){
            break;
          }
          valid == false;
          indicator++;
          count_user++;

        }
        duplicate = 0;
        user_ship_left = 3;

        //cout << "after check winner in SA" << comp_ship_left_last << endl;
      }
    } else {
        srand(time(NULL));
        x = rand() % rows;
        y = rand() % columns;
        char r = x + '0';
        char c = y + '0';
        auto pos1 = string(1,r) + c;
        for (int i = 0; i < count_comp; i++){
            if (pos1 == comp_attack[i]){
            duplicate++;
            incorrect = 1;
            break;
            }
        }

        // No duplicates of input attack position
        if (duplicate == 0){
          attack_num++;
          if (count_user >= comp_attack_size){
            grow_attack_position(comp_attack, comp_attack_size, 3);
          }
          comp_attack[count_comp] = pos1;
          cout << "Computer attacks at position: " << x << " " << y << endl;
          AttackShips(x, y,indicator);
          CheckWinner(pos1, indicator);
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
    if(attack_num % 2 == 0 && duplicate_last == 0 && incorrect!= 1){
      string str;
      getline(cin, str);
      pause();
      system("clear");
    }
    if(attack_num % 2 != 0 && duplicate_last == 0 && incorrect != 1){
      print_section_divider();
    }
  }
  return 0;
}
