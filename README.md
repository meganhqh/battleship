# battleship

**Group Members**

- Soo Sin Yun (3035451040)
- Ho Megan Qian Hua (3035832749)

**Game Description**
- The game is called Battleship, where players will place a number of ships on their own grid and the locations of the ships are hidden from each other. Players will take turns to guess the position of the opponent's ship. The first player to guess all positions correctly will win the game.

**Game Setup**
- The game is played by 2 players, the computer and player.
- Each player has 2 boards: Game Board & Recording Board
  - Game Board - place the ships
  - Recording Board - show if the guess is a hit or miss
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
- Player will first place the 3 ships on the game board by inputting the row number and column alphabet.
- Ships can only be placed vertically and horizontally, but not diagonally or overlapping with each other.
- "Invalid input" prints out if player fails to place the ship correctly by violating the rules.
- Player's and computer's game board is hidden from each other.
- Player and computer alternate turns to call out a row number and column alphabet.
- If the row number and column alphabet correspond to a space occupy by a ship, the specific coordinate on the recording board will be a 'X'(hit); otherwise, '0'(miss).
- Once all coordinates occupy by the ship are guessed correctly, the ship is sunk.
- The first player to sink all 3 ships of the opponent will win the game.

**Available Features**
1. Generation of random game sets or events
- Player can choose one of the 3 difficulty levels which are based on computer's placement and hitting moves
  - Easy = 1
    - Placement move  
      -  Ship placement is completely random on the game board
    - Hitting move
      -  Ship hitting is completely random
  - Medium = 2
    - Placement move
      -  Ship placement is set with 3 strict rules:
        -  Do not place the ships touching to each other
        -  Place the ships asymmetrically
        -  Place at least one or two ships at the edge of the game board
    - Hitting move
      -  Ship hitting is completely random
  - Hard = 3
    - Placement move
      -  Ship placement is set with 3 strict rules:
        -   Do not place the ships touching to each other
        -   Place the ships asymmetrically
        -   Place at least one or two ships at the edge of the game board
    - Hitting move
      -  Ship hitting is determined by hunt (with parity) and target algorithm

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






    


