	#include "gamePiece.h"
#include "gameBase.h"
//#include "lab3.h"


using namespace std;

TicTacToe::TicTacToe(): GameBase()  {
	//TicTacToe game;
	boardWidth = 5;
	boardHeight = 5;
	piece = "X";
	winner = " ";
	player1 = {};
	player2 = {};

}

//Checks if the game is over by checking if one of the player
//has placed 3 consecutive game pieces on the board.
bool TicTacToe::done() {
	unsigned long long firstPieceIndex = 6;

	//checks if there are 3 horizontally consecutive pieces.
	for (unsigned long long i = 6; i < 17; i = i + 5)
	{
		if (pieceList[i].boardDisplay != " " && pieceList[i].boardDisplay == pieceList[i + 1].boardDisplay
			&& pieceList[i + 1].boardDisplay == pieceList[i + 2].boardDisplay)
		{
			winner = pieceList[i].boardDisplay; //assign the piece as winning piece.
			return true;
		}
	}

	//checks if there are 3 vertically consecutive pieces.
	for (unsigned long long i = firstPieceIndex; i < 9; i++) {
		if (pieceList[i].boardDisplay != " " && pieceList[i].boardDisplay == pieceList[i + 5].boardDisplay
			&& pieceList[i + 5].boardDisplay == pieceList[i + 10].boardDisplay)
		{
			winner = pieceList[i].boardDisplay;
			return true;
		}
	}

	//checks if there are 3 diagonally(from bottom-left to top-right) consecutive pieces. 
	if (pieceList[firstPieceIndex].boardDisplay != " " && pieceList[firstPieceIndex].boardDisplay == pieceList[firstPieceIndex * 2].boardDisplay
		&& pieceList[firstPieceIndex * 2].boardDisplay == pieceList[firstPieceIndex * 3].boardDisplay)
	{
		winner = pieceList[firstPieceIndex].boardDisplay;
		return true;
	}

	//checks if there are 3 diagonally(from top-left to bottom-right) consecutive pieces.
	if (pieceList[8].boardDisplay != " " && pieceList[8].boardDisplay == pieceList[12].boardDisplay && pieceList[12].boardDisplay == pieceList[16].boardDisplay) {
		winner = pieceList[8].boardDisplay;
		return true;
	}
	return false;
}

//Checks if the two players drew the game.
bool TicTacToe::draw() {
	if (moves_num < 8 || done()) { // starting from 0, 8 is the maximum number of moves that could be made by players combined.
		return false;
	}
	return true;
}




//Prompts game to change player turn.
int TicTacToe::turn() {
	unsigned int x_coor = 0;
	unsigned int y_coor = 0;
	int promptResult;
	if (piece == "X") {
		cout << "current player: X" << endl;
		promptResult = prompt(x_coor, y_coor);
		if (promptResult == success) {
			cout << *this << endl; //print board
			cout << "Player X: "; //print player's past moves.
			for (unsigned int i = 0; i < player1.size(); i++) {
				cout << player1[i].first << "," << player1[i].second << "; ";
			}
			cout << endl;
			piece = "O"; // switch player turn
			moves_num++; //increment total moves played by both players.
		}
		else {
			return promptResult;
		}
	}
	else if (piece == "O") {
		cout << "current player: O" << endl;
		promptResult = prompt(x_coor, y_coor);
		if (promptResult == success) {
			cout << *this << endl;
			cout << "Player O: ";
			for (unsigned int i = 0; i < player2.size(); i++) {
				cout << player2[i].first << "," << player2[i].second << "; ";
			}
			cout << endl;
			piece = "X";
			moves_num++;
		}
		else {
			//tracks whether a player quit game, the program failed to extract coordinates, or if the coordinate was valid.
			return promptResult;
		}
	}
	return success;
}

 void TicTacToe:: print() {
	cout << *this << endl;
}