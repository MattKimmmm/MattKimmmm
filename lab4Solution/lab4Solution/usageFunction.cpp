//#include "lab3.h"
#include <iostream>

#include "gameBase.h"
using namespace std;

//Function to print out user message when the command line argument is invalid.
int GameBase::userMessage() {
    cout << "Usage: lab4Solution.exe TicTacToe OR lab4Solution.exe Gomoku" << endl;
    cout << "If you would like to play customized Gomoku," << endl;
    cout << "Usage: lab4Solution.exe Gomoku[boardsize][number of connected pieces to win]" << endl;
    cout << "Example: lab4Solution.exe Gomoku 8 4" << endl;
    return static_cast<int>(returnVal::incorrectInput);
}