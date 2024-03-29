//attack_difficult.cpp
//this program determines the attacking move if user select "difficult" level
//in the difficult level, computer first uses a random guess to find a hit, and once they find a hit, it will use a "hunt and target" algorithm to find the remaining spaces occupy by a ship
//hunt means random guess until a succcesful hit is found
//once hunt is sucessful, computer will set it target to the 4 surrounding orientation to figure out where does the consecutive row/columns ships will be placed

#include <iostream>
#include <string>
#include <ctime>
#include <algorithm>
#include <vector>

#include "gameflow.h"
#include "check_winner.h"
#include "save_load.h"
#include "quit.h"
#include "attack_difficult.h"
#include "battleship.h"

using namespace std;


// Check the 4 direction surrounded the attacked ship
// Input: valid row and column
// Output: true if there is ship at the specific row and column for targetting, othewise false
bool CompTarget(int row, int column){
  if(matrix[row][column] == 'S')
  {
    return true;
  }else{
    return false;
  }
}

// Set the location to attack ships
// Inputs: difficulty level, indicator (whose turn to play the game), load (if we are loading from load file), and quit (to capture if user quits halfway)
// Output: return 1 if quit halfway, else return 0; and successful and insuccessful of hunt and target
int SetAttackDifficult(int difficulty, int indicator, int load, int &quit){
  bool repeat = false;
  int row, column, x, y, temp_x, temp_y, size, attack_num = 0;
  int count_size = 0;
  int count = 1;
  int duplicate = 0, count_user = 0, count_comp =0;
  int ship_inputted = 4, quit_sequence = 2, comp_ship_left_last=3;
  bool valid = true;
  vector<int> count_sink;
  while(valid){
    int incorrect = 0;
    int duplicate_last = 0;

    // check if user wants to load from previous game and there is a save game
    if (load == 1) {
      load_file(quit_sequence, difficulty, start_player,  indicator, ship_inputted, matrix, matrixComp, recording, recordingComp, ship_position, ship_positionComp, user_attack, comp_attack, count_user, count_comp, comp_ship_left_last, hunt, target_N, target_S, target_E, target_W);
      user_attack_size = count_user - (count_user % 3);
      comp_attack_size = count_comp - (count_comp % 3);
      cout << "Your ship placement board" << endl;
      PrintBoard(matrix);
      load = 0;
    }
    
    // check whose turn to play
    // even number for user and odd number for computer (depends if user wants to be the first to attack)
    if (indicator % 2 == 0){
      // no repeating input
      if (repeat == false){
        cout << "Your Recording Board" << endl;
        PrintBoard(recording);
        cout << "Number of ships left: " << comp_ship_left_last << endl;
        cout << endl;
      }
      cout << "Please input the location of the ships to attack: ";
      cout << "[Select 9 to save or quit]" << endl;
      cout << "Location: ";
      cin >> row;
      
      // check if user wants to quit with 9 in input row
      while(row == 9){
        if (Quit(quit_sequence, difficulty, start_player,  indicator, ship_inputted, matrix, matrixComp, recording, recordingComp, ship_position, ship_positionComp, user_attack, comp_attack, count_user, count_comp, comp_ship_left_last, hunt, target_N, target_S, target_E, target_W) == true){
          quit =1;
          return 1;
        }
        else{
          cout << "Please input the location of the ships to attack: ";
          cout << "[Select 9 to save or quit]" << endl;
          cout << "Location: ";
          cin >> row;
        }
      }
      cin >> column;
      
      // check if user wants to quit with 9 in input column
      while(column == 9){
        if (Quit(quit_sequence, difficulty, start_player, indicator, ship_inputted, matrix, matrixComp, recording, recordingComp, ship_position, ship_positionComp, user_attack, comp_attack, count_user,count_comp, comp_ship_left_last, hunt, target_N, target_S, target_E, target_W) == true){
          quit =1;
          return 1;
        }
        else{
          cout << "Please input the location of the ships to attack: ";
          cout << "[Select 9 to save or quit]" << endl;
          cout << "Location: ";
          cin >> row >> column;
        }
      }

      // check if the input row and column are in the valid range
      if (row < 0 || column < 0 || row > 5 || column > 5){
        incorrect = 1;
        repeat = true;
        cout << "Incorrect input. Please input the location again." << endl;
      }else{
        
        // covert valid row and column to string to make comparisons for duplication
        char r = row + '0';
        char c = column + '0';
        auto pos = string(1,r) + c;
        
        // check if there are duplicates from the sotred dynamic array which stores all the previous attacking positions
        // loop will run again to get the new input row and column
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

          //write attack position in the dynamic array for the valid attacking positions
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
        comp_ship_left = 3;
      }
    } else {
      
      // hunt and target algorithm
      // initialise hunt as false (random guessing)
      if (hunt == false){
        srand(time(NULL));
        x = rand() % rows;
        y = rand() % columns;
        
        // convert to string to check if there are duplicates in the previous attacks stored in dynamic array
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

        // no duplicates
        if (duplicate == 0){
          attack_num++;
          // increase the size of dynamic array for every valid attack positions
          if (count_comp >= comp_attack_size){
            grow_attack_position(comp_attack, comp_attack_size, 3);
          }
          comp_attack[count_comp] = pos1;
          cout << "Computer attacks at position: " << x << " " << y << endl;
          // check if hit or miss
          AttackShips(x, y,indicator);
          // check if there is a sink ship
          CheckWinner(pos1, indicator);

          // if the number of ships left is 0, the loop will break
          if (winner == true){
            break;
          }
          valid == false;
          indicator++;
          count_comp++;
        }
        user_ship_left = 3;
        duplicate = 0;
        
        // computer successfully identify a successful hit by random guessing
      } else if (hunt == true){
        attack_num++;
        temp_x = x;
        temp_y = y;
        int check = 0;

        bool position = true;

        while(position == true){
          position = false;

          //check target from north
          if ((target_N == true) && ((temp_x -= count) >= 0)){
            if (temp_x == x){
              temp_x -= count;
            }
            // check if there is a ship in the north
            if (CompTarget(temp_x, y) == true){
              if (temp_x - 1 >= 0){
               // check if there is a blank space to attack 2 steps up the north
              }if ((recordingComp[temp_x][y] != '*') && (recordingComp[temp_x - 1][y] != '*')){
                  temp_x = x;
                  target_N = false;
                  count = 1;
                  position = true;
                  continue;
                }else if (recordingComp[temp_x][y] != '*'){
                  temp_x -= 1;
                  target_N = false;
                  count = 1;
              }
              cout << "Show computer attack position: " << temp_x << " " << y << endl;
              // check if it could attack the ships
              if (AttackShips(temp_x, y, indicator) == false){
                target_N = false;
              }else{
                count++;
              }
            }
            else{
              check = 1;
              target_N = false;
              count = 1;
            }

          //check target from west
          }else if ((target_W == true) && ((temp_y -= count) >= 0)){
            if (temp_y == y){
              temp_y -= count;
            }
            // check if there is a ship in the west
            if (CompTarget(x, temp_y) == true){
              if (temp_y - 1 >= 0){
                // check if there is a blank space to attack 2 steps to the west
                if ((recordingComp[x][temp_y] != '*') && (recordingComp[x][temp_y-1] != '*')){
                  temp_y = y;
                  target_W = false;
                  count = 1;
                  position = true;
                  continue;
                }else if (recordingComp[x][temp_y] != '*'){
                  temp_y -= 1;
                  target_W = false;
                  count = 1;
                }
              }
              cout << "Show computer attack position: " << x << " " << temp_y << endl;
              // check if it could attack the ships
              if (AttackShips(x, temp_y, indicator) == false){
                target_W = false;
              }else{
                count++;
              }
            }else{
              check = 1;
              target_W = false;
              count = 1;
            }

          //check target from south
          }else if (target_S == true && (temp_x += count) < 6){
            if (temp_x == x){
              temp_x += count;
            }
            // check if there is a ship in the south
            if (CompTarget(temp_x, y) == true){
              if (temp_x + 1 >= 0){
                // check if there is a blank space to attack 2 steps down to the south
                if ((recordingComp[temp_x][y] != '*') && (recordingComp[temp_x+1][y] != '*')){
                  temp_x = x;
                  target_S = false;
                  count = 1;
                  position = true;
                  continue;
                }else if (recordingComp[temp_x][y] != '*'){
                  temp_x += 1;
                  target_S = false;
                  count = 1;
                }
              }
              cout << "Show computer attack position: " << temp_x << " " << y << endl;
              // check if it could attack the ships
              if (AttackShips(temp_x, y, indicator) == false){
                target_S = false;
              }else{
                count++;
              }
            }else{
              check = 1;
              target_S = false;
              count = 1;
            }

          //check target from east
          }else if (target_E == true && (temp_y += count) < 6) {
            if (temp_y == y){
              temp_y += count;
            }
            // check if there is a ship to the east
            if (CompTarget(x, temp_y) == true){
              if (temp_y + 1 >= 0){
                // check if there is a blank space to attack 2 steps down to the east
                if ((recordingComp[x][temp_y] != '*') && (recordingComp[x][temp_y+1] != '*')){
                  temp_y = y;
                  target_E = false;
                  count = 1;
                  position = true;
                  continue;
                }else if (recordingComp[x][temp_y] != '*'){
                  temp_y += 1;
                  target_E = false;
                  count = 1;
                }
              }
              cout << "Show computer attack position: " << x << " " << temp_y << endl;
              // check if it could attack the ships
              if (AttackShips(x, temp_y, indicator) == false){
                target_E = false;
              }else{
                count++;
              }
            }else{
              check = 1;
              target_E = false;
              count = 1;
            }
          }else{
            hunt = false;
          }
        }

        // if all the targets are set to false, this indicates that a ship is sunk
        // hunt will be reset to false to random guess a successful hit again
        if (target_N == false && target_S == false && target_W == false && target_E == false){
          hunt = false;
          count = 1;
          target_N = true;
          target_S = true;
          target_W = true;
          target_E = true;
        }
        
        // make sure the positions is not out of bound during targetting
        if (temp_x < 0){
          temp_x = x;
          target_N = false;
        }else if (temp_x > 5){
          temp_x = x;
          target_S = false;
        }else if (temp_y < 0){
          temp_y = y;
          target_W = false;
        }else if (temp_y > 5){
          temp_y = y;
          target_E = false;
        }
        char r = temp_x + '0';
        char c = temp_y + '0';
        auto pos1 = string(1,r) + c;
        // grow dynamic array with increasing valid attack positions
        if (count_user >= comp_attack_size){
          grow_attack_position(comp_attack, comp_attack_size, 3);
        }
        comp_attack[count_comp] = pos1;
        // insuccessful target
        if (check == 1){
          cout << "Show computer attack position: " << temp_x << " " << temp_y << endl;
          AttackShips(temp_x, temp_y, indicator);
        }
        // check winner
        CheckWinner(pos1, indicator);
        if (winner == true){
            break;
        }
        // add the number of ships life into the vector
        if (user_ship_left < 3){
          count_sink.push_back(user_ship_left);
        }
        // remove duplicates and identify the size
        auto it = unique(begin(count_sink), end(count_sink));
        count_sink.erase(it, end(count_sink));
        size = count_sink.size();
        
        // if size of vecotr is not the same as previous, this indicates that there is another sink ship
        if(size != count_size){
          count_size = size;
          hunt = false;
          count = 1;
          target_N = true;
          target_S = true;
          target_W = true;
          target_E = true;
        }
        valid == false;
        indicator++;
        count_comp++;
        user_ship_left = 3;
      }
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
