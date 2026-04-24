# Tic-Tac-Toe (C++)

## Project Overview
The project is just a simple implementation of the classic Tic Tac Toe game. It's written in C++
and allows two users to take turns and play the game, with the first person choosing the symbol of their choice.
The game continues until a 3 in a row win condition is met, or until the board is filled up.

## Purpose
The purpose of this project at the time I worked on it was a way to practice (at the time) new concepts
such as:
- 2D arrays
- Input validation
- Game logic implementation
- File input/output

## Compilation and Running:
```
g++ -o tictactoe tictactoe.cpp
./tictactoe
```

## Key Features
- 2 player based gameplay
- Input validation for row and column selection
- Dynamic board updates after each move
- Win detection (rows, columns, diagonals)
- Draw detection once board is full

## Sample Output:
```
Welcome to Tic-Tac-Toe
What would you like to do? 
1. Play New Game 
2. Quit 
1
What symbol would you like to be? (X or O) 
X
Current board: 
 _ _ _
 _ _ _
 _ _ _
Player X, enter row and column (0-2): 1 1
Current board: 
 _ _ _
 _ X _
 _ _ _
```

## My Contribution
This project was implemented entirely by me as part of core coursework. I used my knowledge of arrays, input, win conditions, and check to handle the game logic. This helped me condense and structure the program to get the functionalities I intended. 
