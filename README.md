# battleship

**Group Members**

- Soo Sin Yun (3035451040)
- Ho Megan Qian Hua (3035832749)

**Game Description**
- The game is called Battleship. Players will place a number of ships on their own grid and the locations of the ships are hidden from each other. Players will take turns to guess the position of the opponent's ship. The first player to guess all positions correctly will win the game.

**Game Setup**
- The game is played by 2 players, the computer and player.
- Each player has 2 boards: Game Board & Recording Board
  - Game Board - place the ships
  - Recording Board - show if the guess is a hit or miss
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
  
- There are 3 ships for player to place on the board. Each ship occupies 3 spaces on the board.

**Game Rules**
- Player will first place the 3 ships on the game board by inputting the row and column number of the first position of the ship, followed by the orientation (North, South, East, West) of the ship.
- E.g. 1, 2, West means the first position of the ship have coordinate (1,2), the second and third position of the ship have coordinate (1,1) and (1,0) respectively.
- Ships cannot be placed overlapping with each other.
- The location of ships on the game board for both computer and player is hidden from each other.
- After placing the ships, player and computer alternate turns to call out a row and column number.
- If the row and column number correspond to a space occupy by a ship, the specific coordinate on the recording board will be a 'X'(hit); otherwise, '0'(miss).
- Once all coordinates occupy by the ship are guessed correctly, the ship is sunk.
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
      -  Computer first uses a random guess to find a hit, once there is a hit, it will use a "hunt and target" algorithm to find the remaining spaces occupy by a ship


2. Data structures for storing game status
- Int data types is used to store difficulty level chosen by the player, input row number by player and etc
- String data types is used to store input column alphabet by player and etc
- Boolean data types is used to check the ship placement of the opponent's game board and identify whether it is a hit or miss
- Dynamic array are used to store the player's and computer's ship placement and the latest hitting moves

3. Dynamic memory management
- In the beginning, the dynamic array of the gaming board and recording board are empty
- After player and computer have done their ship placement, the dynamic array of the game board is updated
- The dynamic array of the attacking player's recording board will be updated  by referring to the opponent's ship placement in the game board

4. File input/output
- The player can choose to quit at any time. The current status of the entire game will be saved into several files tracking both game and recording board.
- Player can have the option to resume the last saved game or to start a new game in the beginning.

5. Program codes in multiple files
- The program is divided into multiple functions and stored into different files.
- The programs involve in our text-based game:
  - draw player's game and recording board 
  - input the player's ship placement and hitting moves
  - determine the computer's ship placement and hitting moves
  - determine the winning player
  - control the game flow
  - save and load files
- Makefile is used to generate the program from all the files that are needed for our game


Compilation and Execution
- Download the makefile and the source files into a single folder. The commands are:
- Compilation: make battleship
- Execution: ./battleship
- Removal: make clean



    


