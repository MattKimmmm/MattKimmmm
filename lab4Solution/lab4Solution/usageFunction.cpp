#include "lab3.h"
#include <iostream>
#include "usageFunction.h"
using namespace std;

//Function to print out user message when the command line argument is invalid.
int userMessage() {
    cout << "Usage: lab3.exe TicTacToe" << endl;
    return failure;
}