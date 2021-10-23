# battleship

**Group Members**

- Soo Sin Yun (3035451040)
- Ho Megan Qian Hua (3035832749)

**Group Name**
- Battleship

**Game Setup**
- The game is played by 2 players, the computer and player A.
- Each player has a game board, which is a board for players to place their ships, and a recording board, which is a board for the attacking player to record if their guess is a hit or miss.
- Each board size is a 10x10 grid (10 rows and 10 columns). Rows are denoted by alphabets and columns are denoted by numbers.

**Game Board**
|   | A | B | C | D | E | F | G | H | I | J | 
| - | - | - | - | - | - | - | - | - | - | - |
| 1 |   |   |   |   |   |   |   |   |   |   |  
| 2 |   |   |   |   |   |   |   |   |   |   | 
| 3 |   |   |   |   |   |   |   |   |   |   |            
| 4 |   |   |   |   |   |   |   |   |   |   |            
| 5 |   |   |   |   |   |   |   |   |   |   |            
| 6 |   |   |   |   |   |   |   |   |   |   |            
| 7 |   |   |   |   |   |   |   |   |   |   |  
| 8 |   |   |   |   |   |   |   |   |   |   | 
| 9 |   |   |   |   |   |   |   |   |   |   | 
| 10|   |   |   |   |   |   |   |   |   |   |

**Recording Board**
|   | A | B | C | D | E | F | G | H | I | J | 
| - | - | - | - | - | - | - | - | - | - | - |
| 1 |   |   |   |   |   |   |   |   |   |   |  
| 2 |   |   |   |   |   |   |   |   |   |   | 
| 3 |   |   |   |   |   |   |   |   |   |   |            
| 4 |   |   |   |   |   |   |   |   |   |   |            
| 5 |   |   |   |   |   |   |   |   |   |   |            
| 6 |   |   |   |   |   |   |   |   |   |   |            
| 7 |   |   |   |   |   |   |   |   |   |   |  
| 8 |   |   |   |   |   |   |   |   |   |   | 
| 9 |   |   |   |   |   |   |   |   |   |   | 
| 10|   |   |   |   |   |   |   |   |   |   |
  
  
- There are 5 ships for each player to place on the board. Each ship occupy different number of spaces on the board. Carriers, battleships, cruisers, submarines, and destroyers occupy 5 spaces, 4 spaces, 3 spaces and 2 spaces respectively.
- Ships can only be placed vertically and horizontally, but not diagonally or overlapping with each other.

**Game Instructions**
- Each player will first place the 5 ships on their game board. Each player's game board is hidden from each other.
- Players alternate turns to call out a row alphabet and column number. 
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
- int data types is used to store difficulty level chosen by the player, rows and etc.
- string data types is used to 


    


