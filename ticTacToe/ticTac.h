// Tic Tac Toe
// By Eric Binnion
// 2 Mar 2012

#include <string>

using namespace std;

class ticTac {
private:
    string board[3][3];

public:
    ticTac();
    void addMove(string,string);
    bool boardFull();
    bool checkWin();
    void dialogue();
    void initBoard();
    void printBoard();
    void printDraw();
    void printWin();
    bool winningMove();
    ~ticTac();
};