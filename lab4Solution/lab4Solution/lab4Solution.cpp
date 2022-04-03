// lab3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <ostream>
#include "game.h"
#include "lab3.h"
#include "usageFunction.h"

using namespace std;

TicTacToe::TicTacToe() :boardWidth(5), boardHeight(5), piece('X'), playerX({}), playerO({}), moves_num(0), winner(' ') {}

//prints the board
/*Modify the ostream insertion operator (from the previous lab) so that it takes a reference
to a const object of the derived class for your TicTacToe game, and uses the maximum
display string length stored by the base class to print the board out not just by putting a
space between consecutive piece symbols on a line, but also adjusting the widths of the
squares according to the maximum display string length so that columns of the board are
aligned vertically with at least a space between pieces when they are displayed. Hint: the
setw manipulator (and possibly other stream manipulators) and/or the stream width
method can help to simplify coding of that feature.
*/
ostream& operator<<(ostream& out, const TicTacToe& game) {
    //if there has been no moves made by any players, then fill the game board with empty cells.
    if (game.moves_num == 0) {
        for (int i = game.boardHeight - 1; i >= 0; i--)
        {
            for (int j = 0; j <= game.boardWidth - 1; j++)
            {
                int index = game.boardWidth * i + j;
                gamePiece piece;
                piece.boardDisplay = ' ';
                game.pieceList.push_back(piece);
            }
        }
    }

    //print out game pieces on the board.
    for (int i = game.boardHeight - 1; i >= 0; i--) {
        cout << i << ""; //print out vertical label
        for (int j = 0; j <= game.boardWidth - 1; j++) {
            int index = game.boardWidth * i + j;
            cout << setw(game.longestStrLen) << game.pieceList[index].boardDisplay;
        }
        cout << endl;
    }
    cout << setw(game.longestStrLen) << "0 " << "1 " << "2 " << "3 " << "4 "; //print out horizontal label
    return out;
}
int main(int argc, char* argv[])
{
    if (argc != commandLineNum) {
        cout << "To execute the program, you need two command line arguments." << endl;
        return userMessage();
    }
    else {
        string filename_check = argv[filename];
        if (filename_check != "TicTacToe") {
            cout << "Filename Incorrect." << endl;
            return userMessage();
        }
    }
    TicTacToe game;
    return game.play();
}