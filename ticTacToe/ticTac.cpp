//Tic Tac Toe
// By Eric Binnion
// 2 Mar 2012

#include "ticTac.h"
#include <iostream>
#include <string>

using namespace std;

// Let's get a little construction going on here.
ticTac::ticTac(){
    initBoard();  
}

// This function adds the user's move to the board, then adds the computer's move. 
void ticTac::addMove(string r, string c ) {
    int col, row;
    // Convert human input to computer input ;) 
    // Convert string into index for array.
    if (r == "t" || r == "T")
        row = 0;
    else if (r == "m" || r == "M")
        row =1;
    else
        row =2;
    if (c == "l" || c == "L")
        col = 0;
    else if (c == "m" || c == "M")
        col = 1;
    else
        col = 2;
    
    // Do some error checking to make sure the human's choice is open. If not, let them choose again.
    if (board[row][col] != " "){
        cout << "That is not an open spot. Please try again." << endl << endl;
        printBoard();
        dialogue();
    }
    board[row][col] = "O";  // This will add the human's move.
    
    // Check to see if X can make a move and win.
    if(winningMove() )
        return;

    // Check to see of the spot to the right of human's choice is available
    // and not off of the board. If so, add computer's move.
    if ((col+1) < 3 && board[row][col + 1] == " ")
        board[row][col+1] = "X";
    
    // Check to see if spot to left is available and not off the board. If so, take it.
    else if ((col-1) >= 0 && board[row][col-1] == " ")
        board[row][col-1] = "X";
    
    // Check to see if spot above is available and not off the board. If so, take it.
    else if ((row-1) >= 0 && board[row-1][col] == " ")
        board[row-1][col] = "X";
    
    // Else... Take the spot below human's choice.
    else if((row+1) <3 && board[row+1][col] == " ")  
        board[row+1][col]= "X";
    // Case for no spots left around human choice
    else{     
        // Loop through and find first available spot. Put X there, then return.
        for (int i=0; i<3; i++){
            for (int j=0; j<3; j++) {
                if (board[i][j] == " ") {
                    board[i][j] = "X";
                    return;
                }
            }
        }
    }
}

// If there are any open spaces, this function will return false.
bool ticTac::boardFull(){
    int count = 0; 
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
             if (board[i][j] == " ")
                 count++;
        }
    }
    if (count > 0)   
        return false;
    else 
        return true;
}

// This is a bool function that checks if there are any winners.

bool ticTac::checkWin() {
    // These next three statements check for left to right wins
    if (board[0][0] == board[0][1] && board[0][0] == board [0][2] && board[0][0] != " ")
        return true;
    else if (board[1][0] == board[1][1] && board[1][0] == board[1][2] && board[1][0] != " ")
        return true;
    else if (board[2][0] == board[2][1] && board[2][0] == board[2][2] && board[2][0] != " ")
        return true;
    
    // These next 3 statements check for up and down wins
    else if (board[0][0] == board[1][0] && board[0][0] == board[2][0] && board[0][0] != " ")
        return true;
    else if (board[0][1] == board[1][1] && board[0][1] == board[2][1] && board[0][1] != " ")
        return true;
    else if (board[0][2] == board[1][2] && board[0][2] == board[2][2] && board[0][2] != " ")
        return true;
    
    // Next 2 statements check for diagonal win
    else if (board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] != " ")
        return true;
    else if (board[0][2] == board[1][1] && board[0][2] == board[2][0] && board[0][2] != " ")
        return true;
    else 
        return false;
}

// This is a void function that we repeat until the board is full or until there is a winner. 
// This function prompts the user, accepts input, and then adds the move to the board.

void ticTac::dialogue() {
    string r,c;
    cout << "To tell me where you would like to put your O, tell me first which row you would like to select." << endl << endl;
    cout << "Use T for top, M for middle, or B for bottom followed by enter." << endl << endl;
    cin >> r;
    while (r!= "T" && r != "t" && r != "M" && r!= "m" && r != "B" && r != "b") {
        cout << "Ooops. Be sure that you are entering T for top, M for middle, or B for bottom. Then press enter please." << endl << endl;
        cin >> r;
    }
    cout << "Now tell me which column. Use L for left, M for middle, or R for right followed by enter." << endl << endl;
    cin >> c; 
    while (c!= "L" && c != "l" && c != "M" && c!= "m" && c != "R" && c != "r") {
        cout << "Ooops. Be sure that you are entering L for left, M for middle, and R for right. Then press enter please." << endl << endl;
        cin >> c;
    }
    addMove(r, c);
}

// This function is used to initialize the board, and reinitialize if the human wants to play again.
void ticTac::initBoard() {
    for (int i=0; i<3; i++){
        for (int j=0;j<3;j++){
            board[i][j] = " ";
        }
        cout << endl;
    }
    board[1][1] = "X";
}

// This function prints the board. Ugly, but it works.
void ticTac::printBoard() {
    cout << board[0][0] << "|" << board[0][1] << "|" << board[0][2] << endl;
    cout << "-----" << endl;
    cout << board[1][0] << "|" << board[1][1] << "|" << board[1][2] << endl;
    cout << "-----" << endl;
    cout << board[2][0] << "|" << board[2][1] << "|" << board[2][2] << endl;
    
}

// This function is used to printa message when there is a draw
void ticTac::printDraw() {
    cout << "There was a draw. You got lucky... Human. ";
}

// This function is used to print a message when there is a win.
void ticTac::printWin() {
    cout << "The computer won.";
}

// This function will loop through the board, fill all spaces with X's, and check if there is a win. If there is a win, 
// then leave the winning move and return true. If no winning move, return false.
bool ticTac::winningMove() {
    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++) {
            if (board[i][j] == " ") {
                board[i][j] = "X";
                if (checkWin())
                    return true;
                else 
                    board[i][j] = " ";
            }
        }
    }
    return false;
}

ticTac::~ticTac(){
    
}