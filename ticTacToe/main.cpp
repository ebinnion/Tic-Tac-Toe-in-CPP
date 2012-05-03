// Tic Tac Toe Game
// Created by Eric Binnion
// 2 May 2012

#include <iostream>
#include "ticTac.h"

using namespace std;

int main()
{
    ticTac board;
    string play = "yes";
    while(play == "yes" || play == "Yes" || play == "YES") {
        cout << "Hello Human. Let's play a friendly game of Tic-Tac-Toe.";
        cout << "I have made the first move. I am X's. Play me if you dare!" << endl << endl;
        board.printBoard();
        cout << endl << endl;
        while(!board.checkWin() && !board.boardFull() ){
            board.dialogue();
            board.printBoard();
        }
        if(board.checkWin())
            board.printWin();
        else 
            board.printDraw();
        cout << "Would you like to play again? If so, type Yes and press enter." << endl << endl;
        cin >> play;
        board.initBoard();
    }
    
    cout << "Bye Bye Now!" << endl;
    return 0;
}