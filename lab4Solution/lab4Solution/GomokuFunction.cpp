#include "gameBase.h"



using namespace std;
GomokuGame::GomokuGame() {
	
	boardWidth = 19;
	boardHeight = 19;
	piece = "B";
	winner = " ";
	player1 = {};
	player2 = {};
}
/*Declare and define a public virtual (non-static) done() method that takes no parameters
(other than the this pointer that's passed implicitly to all non-static methods and operators)
and has a bool return type. The method should return true if 5 stones of the same color
are in a row or column or diagonal (otherwise the method should return false.*/



bool GomokuGame::done() {
	unsigned int first_piece_index = 0;
	unsigned int boardsize = boardWidth * boardHeight;
	unsigned int diagonal_factor = boardWidth + 1;

	//diagonal
	for (int i = first_piece_index; i < boardHeight - 4; i += boardWidth) {
		for (int j = i; j % boardWidth < boardWidth - 4; j++) {
			if (pieceList[j].boardDisplay != "" && pieceList[j].boardDisplay == pieceList[j + diagonal_factor].boardDisplay && pieceList[j+diagonal_factor].boardDisplay == 
				pieceList[j + diagonal_factor * 2].boardDisplay && pieceList[j+diagonal_factor*2].boardDisplay == pieceList[j + diagonal_factor * 3].boardDisplay &&
				pieceList[j+diagonal_factor *3].boardDisplay == pieceList[j + diagonal_factor * 4].boardDisplay) {
				winner = pieceList[j].boardDisplay;
				return true;
			}
		}
	}

	//horizontal
	for (int i = first_piece_index; i < boardHeight; i += boardWidth) {
		for (int j = i; j % boardWidth < boardWidth - 4; j++) {
			if (pieceList[j].boardDisplay != " " && pieceList[j].boardDisplay == pieceList[j+1].boardDisplay &&  
				pieceList[j + 1].boardDisplay == pieceList[j + 2].boardDisplay && pieceList[j+2].boardDisplay ==  pieceList[j + 3].boardDisplay
				&& pieceList[j+3].boardDisplay == pieceList[j + 4].boardDisplay) {
				winner = pieceList[j].boardDisplay;
				return true;
			}
		}
	}

	//vertical
	for (int i = first_piece_index; i < boardHeight - 4; i += boardWidth) {
		for (int j = i; j % boardWidth < boardWidth; j++) {
			if (pieceList[j].boardDisplay == "" && pieceList[j].boardDisplay == pieceList[j + boardWidth].boardDisplay &&
				pieceList[j+boardWidth].boardDisplay ==  pieceList[j + boardWidth * 2].boardDisplay && pieceList[j+boardWidth *2].boardDisplay ==
				pieceList[j + boardWidth * 3].boardDisplay && pieceList[j+boardWidth*3].boardDisplay == pieceList[j + boardWidth * 4].boardDisplay) {
				winner = pieceList[j].boardDisplay;
				return true;
			}
		}
	}
}


void GomokuGame::print() {
	cout << *this << endl;
}


