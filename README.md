# battleship

**Group Members**

- Soo Sin Yun (3035451040)
- Ho Megan Qian Hua (3035832749)

**Game Description**
- This game is called Battleship. Players will place a number of ships on their own grid and the locations of the ships are hidden from each other. Players will then take turns to guess the positions of the opponent's ship. The first player to guess all the positions correctly will win the game.

**Game Setup**
- The game is played by 2 players, the computer and the player.
- Each player has 2 boards: Game Board & Recording Board
  - Game Board - for placing the ships
  - Recording Board - for showing if the guess is a hit or miss
- Each board size is a 6x6 grid (6 rows and 6 columns).

**Game Board**
|   | 0 | 1 | 2 | 3 | 4 | 5 |
| - | - | - | - | - | - | - |
| 0 | * | * | * | * | * | S | 
| 1 | S | S | S | * | * | S |
| 2 | * | * | * | * | * | S |           
| 3 | * | * | * | * | * | * |        
| 4 | * | * | S | S | S | * |            
| 5 | * | * | * | * | * | * |            


**Recording Board**
|   | 0 | 1 | 2 | 3 | 4 | 5 |
| - | - | - | - | - | - | - |
| 0 | * | 0 | * | * | * | X | 
| 1 | X | X | X | * | * | X |
| 2 | * | 0 | * | * | 0 | X |           
| 3 | 0 | 0 | * | * | 0 | * |        
| 4 | * | * | X | X | X | * |            
| 5 | * | * | * | * | 0 | * | 
  
- There are 3 ships for player to place on the gameboard. Each ship will occupy 3 spaces on the gameboard.

**Game Rules**
- Player will first place the 3 ships on the game board by inputting the row and column number of the first position of the ship, followed by the orientation (North, South, East, West) of the ship.
- E.g. 1, 2, W means the first position of the ship have coordinate (1,2) and the orientation would be west so the second and third position of the ship have coordinate (1,1) and (1,0) respectively. (as shown in the above gameboard)
- Ships cannot be placed overlapping with each other. (E.g. placing another ship at coordinate (1,1) again)
- The location of ships on the game board for both computer and player is hidden from each other.
- After placing the ships, player and computer will alternate turns to call out a row and column number to guess the positions.
- If the row and column number correspond to a space occupy by a ship, the specific coordinate on the recording board will be a 'X'(hit); otherwise, '0'(miss).
- Once all 3 consecutive coordinates occupy by the ship are guessed correctly, the ship is sunk. (E.g. (1,0), (1, 1) and (1, 2) are hit, the ship is considered sunk)
- The number of ships left will be shown to let user knows the ships left to hit before winning.
- The first player to sink all 3 ships of the opponent will win the game.

**Available Features**
1. Generation of random game sets or events
- Player can choose one of the 2 difficulty levels which are based on computer's hitting moves
  - Easy = 1
    - Placement move  
      -  Computer's ship placement is completely random 
    - Hitting move
      -  Computer's ship hitting is completely random throughout the game
  - Hard = 2
    - Placement move
      -  Computer's ship placement is completely random
    - Hitting move
      -  Computer first uses a random guess to find a hit, once there is a hit, it will use a "hunt and target" algorithm to find the remaining spaces occupy by a ship.
      -  Computer will identify the 4 orientation around a successful hit to facilitate the hitting for the next moves.


2. Data structures for storing game status
- Static array is used to store computer and player game board and recording board. 
- Static array is used to store the ship placement positions entered by player and computer.
- Dynamic array is used to store the increasing attacking positions by player and computer.
- Vectors is used to store the number of user ships left for the hard difficulty level when computer is attacking to eliminate the duplicates.
- Int data types is used to store difficulty level chosen by the player, input row and column number and etc.
- Bool data types is used to store the winner, orientation of the "hunt and target algorithm", input error, repeating input, quit process and ships attacking. 
- String data types is used to store the input interger row and column number as string.
- Char data types used to store the computer and player game board and recording board.

3. Dynamic memory management
- The number of attacking positions inputted during the game will depend on how fast there is a winner of the game, which we do not know initially. Thus, to record the attacking positions in an array, a dynamic array is used so that we could increase the size the dynamic array to store more attacking positions during the game.

4. File input/output
- The player can choose to quit at any time, and the current status of the game will be stored in a line separated by spaces in savefile.txt.
- Player can have the option to resume the last saved game, or to start a new game in the beginning. If player chooses to load from previous game, the game status will restore by reading savefile.txt.

5. Program codes in multiple files
- The program is divided into multiple functions and stored into different files.
- The programs involve in our text-based game:
  - battleship.cpp: Main function which manages the flow of the game
  - gameflow.cpp: Manages other stages of the game flow, such as: initialise start board, printing instructions, asking player to choose difficulty level, asking player to choose playing sequence, printing boards, having a pause on the screen, and etc
  - setship.cpp: Determines the ship placement move of user and computer
  - attack_easy.cpp: Determines the attacking move if user selects "easy" level
  - attack_difficult.cpp: Determines the attacking move if user selects "difficult" level
  - check_winner.cpp: Determines the number of ships left in opponent's board and hence determines a winner 
  - save_load.cpp: For saving and loading game status
  - quit.cpp: For allowing users to quit during the game
- Makefile is used to generate the program from all the files that are needed for our game


Compilation and Execution
- Download the makefile and the source files into a single folder. The commands are:
- Compilation: make battleship
- Execution: ./battleship
- Removal: make clean



    


