#include <iostream>
#include <string>
#include "check_winner.h"
#include "battleship.h"

using namespace std;



// Check who is the winner by eliminating from the dynamic array according to the attack position
// Input: valid attacking position, indicator (whose turn to play the game)
// Output: winner in the game?
int CheckWinner(string position, int indicator){
  int comp_ship_left_last;

  // change ship position board to 'N' when the attacks the ship correctly
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

    // check the number of ships left based on the sink ship
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

  // output the final number of ships lift
  if (indicator % 2 == 0){
    //cout << "Number of ships left: " << comp_ship_left << endl;
    //cout << endl;
  } else{
    cout << "Number of ships left: " << user_ship_left << endl;
    cout << endl;
  }

  // if all 3 ships are being hit
  // if all 3 ships are being hit
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
