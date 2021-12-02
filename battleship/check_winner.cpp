//check_winner.cpp
//this program determines the number of ships left in opponent's board and also determine a winner (whoever makes opponent's ship count go to zero first).

#include <iostream>
#include <string>
#include "check_winner.h"
#include "battleship.h"

using namespace std;

// Check who is the winner by determining the number of ships left in both player's board
// Input: valid attacking position, indicator (whose turn to play the game)
// Output: number of ships left in computer's board
int CheckWinner(string position, int indicator){
  int comp_ship_left_last;

  // change ship position array to 'N' when the opponent attacks the ship correctly
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

  // count the number of boxes with 'N' (successful attacking positions with ship)
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

    // check the number of ships left based on how many ships are being sunk (all spaces occupy by the ship is hit)
    if (indicator % 2 == 0){
      if (sink_ship == 3){
        comp_ship_left = comp_ship_left - 1;
      }
    } else{
      if (sink_ship == 3){
        user_ship_left = user_ship_left - 1;
      }
    }
  }

  // output the final number of ships left
  if (indicator % 2 != 0){
    cout << "Number of ships left: " << user_ship_left << endl;
    cout << endl;
  }

  // if all 3 user ships are sunk first, computer wins and a sad face prints out
   if (user_ship_left == 0){
     cout << "     a$$$$$$$$$$$a" << endl;
     cout << "   a$$$$$$$$$$$$$$$a" << endl;
     cout << "  a$$$$$$$$$$$$$$$$$$a" << endl;
     cout << " a$$$$   $$$$$   $$$$$a" << endl;
     cout << "a$$$$     $$$     $$$$$a" << endl;
     cout << "a$$$$$$ $$$$$$$$$$$$$$$a" << endl;
     cout << "a$$$$$$$        $$$$$$$a" << endl;
     cout << " a$$$$$  $$$$$$  $$$$$a" << endl;
     cout << "  a$$$ $$$$$$$$$$ $$$a" << endl;
     cout << "   a$$$$$$$$$$$$$$$a" << endl;
     cout << "     a$$$$$$$$$$$a" << endl;
     cout << endl;
     cout << "You lose! Computer wins!" << endl;
     winner = true;
   // if all 3 computer ships are sunk first, user wins and a cute cat prints out
   } else if (comp_ship_left == 0){
     cout << "                         _" << endl;
     cout << "                        / )" << endl;
     cout << "                       ( (" << endl;
     cout << "                        ) )" << endl;
     cout << "    A.--.A    .--""--.   ) )" << endl;
     cout << "   / ,  , \\ /        \\/ / "<< endl;
     cout << "  =\\    t ;=        /   /" << endl;
     cout << "    `--,\'   .'''----|   /" << endl;
     cout << "       | |  |     \\\\   /" << endl;
     cout << "      ( (,__|     ( (__|" << endl;
     cout << "-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^" << endl;
     cout << endl;
     cout << "Congratulations! User wins!" << endl;
     winner = true;
   }
  return comp_ship_left;
}
