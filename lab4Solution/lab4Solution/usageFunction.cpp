//#include "lab3.h"
#include <iostream>

#include "gameBase.h"
using namespace std;

//Function to print out user message when the command line argument is invalid.
int GameBase::userMessage() {
    cout << "Usage: lab3.exe TicTacToe" << endl;
    return static_cast<int>(returnVal::incorrectInput);
}