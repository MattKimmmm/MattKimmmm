// lab3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iomanip>
#include <ostream>
#include <cstdlib>
#include "gameBase.h"


using namespace std;



static GameBase* checkArg(int argc, char* argv[]) {
    GameBase* game = 0;
    if (argc == 2) {
        if (strcmp( "TicTacToe", argv[gameType]) == 0) {
            game = new TicTacToe();
        }
        else if (strcmp("Gomoku", argv[gameType]) == 0) {
            game = new GomokuGame();
        }
    }
    else if (argc == 3) {
        if (strcmp("Gomoku", argv[gameType]) == 0) {

            if (atoi(argv[boardDimension]) == displace3) {
                int boardSize = atoi(argv[boardDimension]);
                int connectNumInput = 3;
                game = new GomokuGame(boardSize, connectNumInput);
            }

            if (atoi(argv[boardDimension]) >= 5) {
                int boardSize = atoi(argv[boardDimension]);
                int connectNumInput = 5;
                game = new GomokuGame(boardSize, connectNumInput);
            }
        }
    }
    else if (argc == 4) {
        if (strcmp("Gomoku", argv[gameType]) == 0) {
            if (atoi(argv[boardDimension]) >= 3) {
                if (atoi(argv[winLengthInput]) <= atoi(argv[boardDimension]) && (atoi(argv[winLengthInput]) > 0)) {
                    int boardSize = atoi(argv[boardDimension]);
                    int connectNumInput = atoi(argv[winLengthInput]);
                    game = new GomokuGame(boardSize, connectNumInput);
                }
            }
        }
    }
    return game;
} 

GameBase::GameBase() : boardWidth(0), boardHeight(0), piece(""), winner(""), player1({}), player2({}), longestDispLen(1), moves_num(0), connectNum(3) {

}


//prints the board
ostream& operator<<(ostream& out, const TicTacToe& game) {
    //if there has been no moves made by any players, then fill the game board with empty cells.
    if (game.moves_num == 0) {
        for (int i = game.boardHeight - 1; i >= 0; i--)
        {
            for (int j = 0; j <= game.boardWidth - 1; j++)
            {
                int index = game.boardWidth * i + j;
                gamePiece piece;
                piece.boardDisplay = " ";
                game.pieceList.push_back(piece);
            }
        }
    }

    int longestLen = game.longestDispLen + 1;
    //print out game pieces on the board.
    for (int i = game.boardHeight - 1; i >= 0; i--) {
        cout << i << ""; //print out vertical label
        for (int j = 0; j <= game.boardWidth - 1; j++) {
            int index = game.boardWidth * i + j;
            /*using setw manipulator for the spacings between displayed pieces*/
            
            cout << setw(longestLen) << game.pieceList[index].boardDisplay;
        }
        // same spacing for displayed pieces for horizontal alignment
        
        //for (int i = 0; i < game.boardHeight - 1; i++) {
            cout << endl;
        //}
    }

    //print out horizontal label
    cout << setw(longestLen)<< " " << 0;
    for (int i = 1; i < game.boardWidth; i++) {
        cout << setw(longestLen) << i;
    }
    cout << endl;
    return out;
}



ostream& operator<<(ostream& out, const GomokuGame& game) {
    //if there has been no moves made by any players, then fill the game board with empty cells.
    if (game.moves_num == 0) {
        for (int i = game.boardHeight - 1; i >= 0; i--)
        {
            for (int j = 0; j <= game.boardWidth - 1; j++)
            {
                int index = game.boardWidth * i + j;
                gamePiece piece;
                piece.boardDisplay = " ";
                game.pieceList.push_back(piece);
            }
        }
    }

    int longestLen_2 = game.longestDispLen + displace2;
    int longestLen_1 = game.longestDispLen + displace1;
    //print out game pieces on the board.
    for (int i = game.boardHeight - 1; i >= 0; i--) {
        if (i < 9) {
            cout << ' ' << i + 1;
        }
        else {
            cout << i + 1 << ""; //print out vertical label
        }
        for (int j = 0; j <= game.boardWidth - 1; j++) {
            int index = game.boardWidth * i + j;
            //using setw manipulator for the spacings between displayed pieces
            if (j >= 10) {
                cout << setw(longestLen_2) << game.pieceList[index].boardDisplay;
                continue;
            }
            cout << setw(longestLen_1) << game.pieceList[index].boardDisplay;
        }
        // same spacing for displayed pieces for horizontal alignment
        cout << endl;
    }

    //print out horizontal label
    cout << " X" << setw(longestLen_1);
    for (int i = 1; i <= game.boardWidth; i++) {
        if (i > 8) {
            cout << i << setw(longestLen_2);
        }
        else {
            cout << i << setw(longestLen_1);
        }
    }
    cout << endl;
    return out;
}

int main(int argc, char* argv[])
{
    
    try{
        GameBase* game = checkArg(argc, argv);

        if (game != 0) {
            
            //Create shared_ptr of the GameBase object
            shared_ptr<GameBase> sharedGameptr = shared_ptr<GameBase>(game);

            return game->play();
            
            
        }
        else {
            return game->userMessage();
        }

        delete game;
        
        
    }
    catch(bad_alloc){
        return bad_allocation;
    }

    
    
    
}