/*****************************************
** File: proj1.cpp
** Project: CMSC 202 Project 1, Spring 2025
** Author: Isaam Sayed
** Date: 20 February 2025
** Section: 12
** E-mail: isaams1@umbc.edu
**
** This file contains project 1, which was to write a tic tac toe program.
** The program is able to notice the rules of the game such as draw and win condition.
**
***********************************************/


#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

const int BOARD_SIZE = 3; // num of both rows and columns
const char SYMBOL1 = 'X'; // one of playable characters
const char SYMBOL2 = 'O'; // other playable character

// function prototypes
void mainMenu(char board[BOARD_SIZE][BOARD_SIZE]);
void saveGame(char board[BOARD_SIZE][BOARD_SIZE]);
void displayBoard(char board[BOARD_SIZE][BOARD_SIZE]);
void clearBoard(char board[BOARD_SIZE][BOARD_SIZE]);
char chooseSymbol();
void playGame(char board[BOARD_SIZE][BOARD_SIZE]);
void makeMove(char board[BOARD_SIZE][BOARD_SIZE], char symbol);
int checkWin(char board[BOARD_SIZE][BOARD_SIZE], char symbol);

int main(){
    // intitalizing the empty board
    char board[BOARD_SIZE][BOARD_SIZE] = {'_', '_', '_', '_', '_', '_', '_', '_', '_'};
    cout << "Welcome to Tic-Tac-Toe" << endl;
    mainMenu(board);
    return 0;
}


//-------------------------------------------------------
// Name: mainMenu
// PreCondition: none
// PostCondition: starts game or ends program based on user input
//---------------------------------------------------------
void mainMenu(char board[BOARD_SIZE][BOARD_SIZE]){


    int num;
    do {
        cout << "What would you like to do? " << endl;
        cout << "1. Play New Game " << endl;
        cout << "2. Quit " << endl;
        cin >> num;
    } while (num != 1 && num != 2);

    // switch used for valid input to decide to play game or end it
    switch(num){
    case 1:
        clearBoard(board);
        playGame(board);
        break;
    case 2:
        cout << "Thank you for playing Tic-Tac-Toe" << endl;
        break;

   }
}


//-------------------------------------------------------
// Name: playGame
// PreCondition: if user decides to play game, mainMenu calls
// PostCondition: Returns to mainMenu after game finishes
//---------------------------------------------------------
void playGame(char board[BOARD_SIZE][BOARD_SIZE]){
    char userSymbol = chooseSymbol();
    bool gameOver = false;
    int result = 0;

    // while loop continues to run as long as gameOver is false
    //loop displays board, allows user to move, and saves the current board to file output
    while (!gameOver){
        displayBoard(board);
        makeMove(board, userSymbol);
        saveGame(board);

        // after it saves the board, we save a correspoding integer to won, draw, or continue the game
        result = checkWin(board, userSymbol);
        
        // if result retuned from checkWin is 1, it means the current player has won
        // exits loop once condition is met (gameOver being true)
        if (result == 1){
            displayBoard(board);
            cout << "Player " << userSymbol << " wins!" << endl;
            saveGame(board);
            gameOver = true;

        // if result retuned from checkWin is 2, it means neither play has won
        // exits loop once condition is met (gameOver being true)
        } else if (result == 2){
            displayBoard(board);
            cout << "The game is a draw!" << endl;
            saveGame(board);
            gameOver = true;

        // if neither condition above is met, the game continues
        } else {

            if (userSymbol == SYMBOL1){
                userSymbol = SYMBOL2;
            } else {
                userSymbol = SYMBOL1;
            }

        }
    }

    // called after the game finishes (gameOver has become true)
    mainMenu(board);
}


//-------------------------------------------------------
// Name: displayBoard
// PreCondition: symbol is choosen for player 1
// PostCondition: asks user to enter row and column
//---------------------------------------------------------
void displayBoard(char board[BOARD_SIZE][BOARD_SIZE]){
    cout << "Current board: " << endl;

    // iterates through row
    for (int i=0; i < BOARD_SIZE; i++){
        // iterates through each column in the current row
        for (int j=0; j < BOARD_SIZE; j++){
            cout << setw(2) << board[i][j];
        }
        cout << endl;
    }
}


//-------------------------------------------------------
// Name: chooseSymbol
// PreCondition: user decides to play game
// PostCondition: first person gets choosen valid symbol
//---------------------------------------------------------
char chooseSymbol(){
    char symbol;
    // do while loop validates input to make sure X or O is chosen
    do{
        cout << "What symbol would you like to be? (X or O) " << endl;
        cin >> symbol;
    } while (symbol != SYMBOL1 && symbol != SYMBOL2);
    return symbol;
}


//-------------------------------------------------------
// Name: makeMove
// PreCondition: player chooses/assigned symbol and valid turn
// PostCondition: user makes valid move or prompted to re-enter
//---------------------------------------------------------
void makeMove(char board[BOARD_SIZE][BOARD_SIZE], char symbol){
    int row = 0;
    int col = 0;
    
    // do while loop makes sure user input is in bounds/empty or asks to re-enter
    do{
        cout << "Player " << symbol << ", enter row and column (0-2): ";
        cin >> row >> col;

        if (row < 0 || row > 2 || col < 0 || col > 2){
            cout << "Invalid move. Try again." << endl;
            displayBoard(board);

        } else if (board[row][col] != '_'){
            cout << "Invalid move (Spot taken). Try again." << endl;
            displayBoard(board);
        }

    } while (board[row][col] != '_' || row < 0 || row > 2 || col < 0 || col > 2);

    // moves symbol to valid spot
    board[row][col] = symbol;

}


//-------------------------------------------------------
// Name: saveGame
// PreCondition: called in playGame after player move
// PostCondition: saves current board to text file
//---------------------------------------------------------
void saveGame(char board[BOARD_SIZE][BOARD_SIZE]){
    // opens file to output into it
    ofstream myfile("proj1_data.txt");

    if (myfile.is_open()){
        for (int i=0; i < BOARD_SIZE; i++){
            for (int j=0; j < BOARD_SIZE; j++){
                myfile << board[i][j] << " ";
            }   
            myfile << endl;
        }
    myfile.close();
    } else {
        cout << "Unable to open file" << endl;
    }

}


//-------------------------------------------------------
// Name: clearBoard
// PreCondition: function is called when game ends
// PostCondition: clears board in  preparation for next game
//---------------------------------------------------------
void clearBoard(char board[BOARD_SIZE][BOARD_SIZE]){
        for (int i=0; i < BOARD_SIZE; i++){
            for (int j=0; j < BOARD_SIZE; j++){
	      // resets all row and column spaces to '_'
                board[i][j] = '_';
            }   
        }
	// saves empty board
	saveGame(board);
}


//-------------------------------------------------------
// Name: checkWin
// PreCondition: player makes valid move
// PostCondition: declares win, draw, or continues game
//---------------------------------------------------------
int checkWin(char board[BOARD_SIZE][BOARD_SIZE], char symbol){
   
    // for loop interates through each row and column in row to see if they all are the same symbol
    for (int i = 0; i < BOARD_SIZE; i++){
        bool rowWin = true;
        for (int j = 0; j < BOARD_SIZE; j++){
            if (board[i][j] != symbol) {
                rowWin = false;
            }
        }
    
    // if all symbols in row are indeed the same, returns 1 to playGame for win
    if (rowWin){
        return 1;
   }
}
    // similar to the previous nested loop, this one interates through each column and row in column to see if they are the same symbol
    for (int j = 0; j < BOARD_SIZE; j++){
        bool colWin = true;
        for (int i = 0; i < BOARD_SIZE; i++){
            if (board[i][j] != symbol) {
                colWin = false;
        }
    }
    // if all symbols in column are indeed the same, returns 1 to playGame for win
    if (colWin){
        return 1;
    }
}
    // these 2 if statements return 1 to playGame for win, if there is a diagnol win
    if (board[0][0] == symbol &&  board[1][1] == symbol && board[2][2] == symbol){
        return 1;
    }  
    if (board[2][0] == symbol &&  board[1][1] == symbol && board[0][2] == symbol){
         return 1;
    } 

    // for loop for if there is no win yet and board not filled, so returns 0 to playGame to keep playing
    for (int i = 0; i < BOARD_SIZE; i++){
        for ( int j = 0; j < BOARD_SIZE; j++){
            if (board[i][j] == '_'){
                return 0;
            }
        }

    }

    //returns 2 for filled up board, but no winners (draw)
    return 2;

}
