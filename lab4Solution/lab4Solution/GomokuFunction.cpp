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

int GomokuGame::turn() {
	unsigned int x_coor = 0;
	unsigned int y_coor = 0;
	int promptResult;
	if (piece == "B") {
		cout << "current player: B" << endl;
		promptResult = prompt(x_coor, y_coor);
		if (promptResult == success) {
			cout << *this << endl; //print board
			cout << "Player B: "; //print player's past moves.
			for (unsigned int i = 0; i < player1.size(); i++) {
				cout << player1[i].first << "," << player1[i].second << "; ";
			}
			cout << endl;
			piece = "W"; // switch player turn
			moves_num++; //increment total moves played by both players.
		}
		else {
			return promptResult;
		}
	}
	else if (piece == "W") {
		cout << "current player: W" << endl;
		promptResult = prompt(x_coor, y_coor);
		if (promptResult == success) {
			cout << *this << endl;
			cout << "Player W: ";
			for (unsigned int i = 0; i < player2.size(); i++) {
				cout << player2[i].first << "," << player2[i].second << "; ";
			}
			cout << endl;
			piece = "W";
			moves_num++;
		}
		else {
			//tracks whether a player quit game, the program failed to extract coordinates, or if the coordinate was valid.
			return promptResult;
		}
	}
	return success;
}
void GomokuGame::print() {
	cout << *this << endl;
}


*/

/*Declare and define a public virtual (non-static) draw() method that takes no
parameters(other than the this pointer that's passed implicitly to all non-static methods
and operators) and has a bool return type. The method should return true if there is no
path left that can lead to 5 stones in a row, otherwise the method should return false.*/
bool GomokuGame::draw() {

}