# battleship

**Group Members**

- Soo Sin Yun (3035451040)
- Ho Megan Qian Hua (3035832749)

**Group Name**
- Battleship

**Game Setup**
- The game is played by 2 players, the computer and player.
- Each player 2 boards: Game Board & Recording Board
  - Game Board - place the ships
  - Recording Board - record if the guess is a hit or miss
- Each board size is a 6x6 grid (6 rows and 6 columns). Rows are denoted by numbers and columns are denoted by alphabets.

**Game Board**
|   | A | B | C | D | E | F |
| - | - | - | - | - | - | - |
| 1 |   |   |   |   |   | * | 
| 2 | * | * | * |   |   | * |
| 3 |   |   |   |   |   | * |           
| 4 |   |   |   |   |   |   |        
| 5 |   |   |   | * | * |   |            
| 6 |   |   |   |   |   |   |            


**Recording Board**
|   | A | B | C | D | E | F |
| - | - | - | - | - | - | - |
| 1 |   | 0 |   |   |   |   | 
| 2 | X | X | X |   |   | X |
| 3 |   | 0 |   |   | 0 | X |           
| 4 | 0 | 0 |   |   | 0 | X |        
| 5 |   |   |   | X | X |   |            
| 6 |   |   |   |   | 0 |   |  
  
- There are 3 ships for player to place on the board. Each ship occupies different number of spaces with battleships, cruisers and submarines occupying 3 spaces, 3 spaces and 2 spaces respectively.

**Game Rules**
- Ships can only be placed vertically and horizontally, but not diagonally or overlapping with each other.

**Game Instructions**
- Player will first place the 3 ships on the game board. Player's and computer's game board is hidden from each other.
- Players alternate turns to call out a row number and column alphabet.
- If the row alphabet and column number correspond to a space occupied by a ship, the opponent has to reveal to the attacking player that it is a hit; otherwise, the opponent has to reveal that it is a miss.
- The results of hit or miss is recorded using X and O respectively on the recording board by the attacking player.
- Once all the spaces occupied by the ships is marked with a hit (X), the opponent's ship is sunk.
- The first player to sink all 5 ships of the opponent will win the game.

**Available Features**

1. Generation of random game sets or events
- There are 3 difficulty levels for both computer's placement and hitting moves
  - Easy = 1
    - Placement move  
      -  ship placement is completely random on the game board
    - Hitting move
      -  ship hitting is completely random
  - Medium = 2
    - Placement move
      -  ship placement is set with 3 strict rules:
        -   Do not place the ships touching to each other
        -   Place the ships asymmetrically
        -   Place at least one or two ships at the edge of the game board
    - Hitting move
      -  ship hitting is completely random
  - Hard = 3
    - Placement move
      -  ship placement is set with 3 strict rules:
        -   Do not place the ships touching to each other
        -   Place the ships asymmetrically
        -   Place at least one or two ships at the edge of the game board
    - Hitting move
      -  ship hitting is determined by hunt (with parity) and target algorithm

2. Data structures for storing game status
- int data types is used to store difficulty level chosen by the player, input row by player and etc.
- string data types is used to store input column by player and etc
- boolean data types is used to check the ship placement of the opponent's game board and identify whether it is a hit or miss
- dynamic array are used to store the player's and computer's ship placement and the latest hitting moves

3. Dynamic memory management
- in the beginning, the dynamic array of the gaming board and recording board are empty
- after players have done their ship placement, the dynamic array of the gaming board is updated
- the dynamic array of the recording board will be updated based on the attacking player move by referring to the ship placement in the dynamic array of the gaming board

4. File input/output
- The player can choose to quit at any time. The current status of the entire game will be saved into several files tracking both game and recording board.
- Player can have the option to resume the last saved game or to start a new game in the beginning.

5. Program codes in multiple files
- The program is divided into multiple functions and stored into different files.
- The programs involve in our text-based game
  - save and load files
  - determine the computer's ship placement and hitting moves
  - draw player's gaming and recording board
  - control the game flow
  - determining the winning player
  - inputting the player's ship placement
  - inputting the player's hitting moves
- Makefile is used to generate the program from all the files that are needed for the game






    


