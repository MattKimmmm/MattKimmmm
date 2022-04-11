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
	int first_piece_index = 0;
	size_t diagonal_upper_right = static_cast<size_t>(boardWidth) + 1;
	size_t diagonal_lower_right = static_cast<size_t>(boardWidth) - 1; 

	//diagonal to upper right
	/*iterate through cases for every possible starting piece
	for (int i = first_piece_index; i < boardHeight - 4; i += boardWidth) {
		for (size_t j = i; j % boardWidth < static_cast<size_t>(boardWidth) - 4; j++) {
			//check the consecutive pieces in the path
			if (pieceList[j].boardDisplay != " " && pieceList[j].boardDisplay == pieceList[j + diagonal_upper_right].boardDisplay &&
				pieceList[j+ diagonal_upper_right].boardDisplay == pieceList[j + diagonal_upper_right * 2].boardDisplay &&
				pieceList[j+ diagonal_upper_right *2].boardDisplay == pieceList[j + diagonal_upper_right * 3].boardDisplay &&
				pieceList[j+ diagonal_upper_right *3].boardDisplay == pieceList[j + diagonal_upper_right * 4].boardDisplay) {

				cout << " diagonal " << endl;
				winner = pieceList[j].boardDisplay;
				return true;
			}
		}
	}
	*/
	//diagonal to bottom right
	/*iterate through cases for every possible starting piece
	for (int i = first_piece_index + 4; i < boardHeight; i += boardWidth) {
		for (size_t j = i; j % boardWidth < static_cast<size_t>(boardWidth) - 4; j++) {
			if (pieceList[j].boardDisplay != " " && pieceList[j].boardDisplay == pieceList[j - diagonal_lower_right].boardDisplay && pieceList[j - diagonal_lower_right].boardDisplay ==
				pieceList[j - diagonal_lower_right * 2].boardDisplay && pieceList[j - diagonal_lower_right * 2].boardDisplay == pieceList[j - diagonal_lower_right * 3].boardDisplay &&
				pieceList[j - diagonal_lower_right * 3].boardDisplay == pieceList[j - diagonal_lower_right * 4].boardDisplay) {
				cout << " diagonal2 " << endl;
				winner = pieceList[j].boardDisplay;
				return true;
			}
		}
	}
	*/
	//horizontal
	/*iterate through cases for every possible starting piece
	for (int i = first_piece_index; i < boardHeight; i += boardWidth) {
		for (size_t j = i; j % boardWidth < static_cast<size_t>(boardWidth) - 4; j++) {
			if (pieceList[j].boardDisplay != " " && pieceList[j].boardDisplay == pieceList[j+1].boardDisplay &&  
				pieceList[j + 1].boardDisplay == pieceList[j + 2].boardDisplay && pieceList[j+2].boardDisplay ==  pieceList[j + 3].boardDisplay
				&& pieceList[j+3].boardDisplay == pieceList[j + 4].boardDisplay) {
				cout << " horizontal " << endl;
				winner = pieceList[j].boardDisplay;
				return true;
			}
		}
	}
	*/
	//vertical
	/*iterate through cases for every possible starting piece
	for (int i = first_piece_index; i < boardHeight - 4; i += boardWidth) {
		for (size_t j = i; j % boardWidth < boardWidth; j++) {
			if (pieceList[j].boardDisplay != " " && pieceList[j].boardDisplay == pieceList[j + boardWidth].boardDisplay &&
				pieceList[j+boardWidth].boardDisplay ==  pieceList[j + static_cast<size_t>(boardWidth) * 2].boardDisplay && 
				pieceList[j+ static_cast<size_t>(boardWidth) * 2].boardDisplay == pieceList[j + static_cast<size_t>(boardWidth) * 3].boardDisplay &&
				pieceList[j+ static_cast<size_t>(boardWidth) * 3].boardDisplay == pieceList[j + static_cast<size_t>(boardWidth) * 4].boardDisplay) {
				cout << " vertical " << endl;
				winner = pieceList[j].boardDisplay;
				return true;
			}
		}
	}
	*/
	//game is not done yet
	return false;
}

/*Declare and define a public virtual (non-static) draw() method that takes no
parameters(other than the this pointer that's passed implicitly to all non-static methods
and operators) and has a bool return type. The method should return true if there is no
path left that can lead to 5 stones in a row, otherwise the method should return false.*/
bool GomokuGame::draw() {
	size_t first_piece_index = 0;
	size_t diagonal_upper_right = static_cast<size_t>(boardWidth) + 1;
	size_t diagonal_lower_right = static_cast<size_t>(boardWidth) - 1;

	//horizontal check for black
	for (size_t i = first_piece_index; i < boardHeight; i += boardWidth) {
		for (size_t j = i; j % boardWidth < static_cast<size_t>(boardWidth) - 4; j++) {
			//starting from the initial piece, check all 5 spots in the path if there is a white stone.
			//Path is valid if there are no white stones
			if (pieceList[j].boardDisplay != "W" && pieceList[j + 1].boardDisplay != "W" && pieceList[j + 2].boardDisplay != "W" &&
				pieceList[j + 3].boardDisplay != "W" && pieceList[j + 4].boardDisplay != "W") {
				return false;
			}
		}
	}

	//horizontal check for white
	for (size_t i = first_piece_index; i < boardHeight; i += boardWidth) {
		for (size_t j = i; j % boardWidth < static_cast<size_t>(boardWidth) - 4; j++) {
			if (pieceList[j].boardDisplay != "B" && pieceList[j + 1].boardDisplay != "B" && pieceList[j + 2].boardDisplay != "B" &&
				pieceList[j + 3].boardDisplay != "B" && pieceList[j + 4].boardDisplay != "B") {
				return false;
			}
		}
	}

	//vertical check for black
	for (size_t i = first_piece_index; i < static_cast<size_t>(boardHeight) - 4; i += boardWidth) {
		for (size_t j = i; j % boardWidth < boardWidth; j++) {
			if (pieceList[j].boardDisplay != "W" && pieceList[j + boardWidth].boardDisplay != "W" &&
				pieceList[j + 2 * static_cast<size_t>(boardWidth)].boardDisplay != "W" &&
				pieceList[j + 3 * static_cast<size_t>(boardWidth)].boardDisplay != "W" &&
				pieceList[j + 4 * static_cast<size_t>(boardWidth)].boardDisplay != "W") {
				return false;
			}
		}
	}

	//vertical check for white
	for (size_t i = first_piece_index; i < static_cast<size_t>(boardHeight) - 4; i += boardWidth) {
		for (size_t j = i; j % boardWidth < boardWidth; j++) {
			if (pieceList[j].boardDisplay != "B" && pieceList[j + boardWidth].boardDisplay != "B" && 
				pieceList[j + 2* static_cast<size_t>(boardWidth)].boardDisplay != "B" &&
				pieceList[j + 3* static_cast<size_t>(boardWidth)].boardDisplay != "B" &&
				pieceList[j + 4* static_cast<size_t>(boardWidth)].boardDisplay != "B") {
				return false;
			}
		}
	}

	//diagonal to upper right, black
	for (size_t i = first_piece_index; i < static_cast<size_t>(boardHeight) - 4; i += boardWidth) {
		for (size_t j = i; j % boardWidth < static_cast<size_t>(boardWidth) - 4; j++) {
			if (pieceList[j].boardDisplay != "W" && pieceList[j + diagonal_upper_right].boardDisplay != "W" &&
				pieceList[j + 2 * diagonal_upper_right].boardDisplay != "W" &&
				pieceList[j + 3 * diagonal_upper_right].boardDisplay != "W" &&
				pieceList[j + 4 * diagonal_upper_right].boardDisplay != "W") {
				return false;
			}
		}
	}

	//diagonal to upper right, white
	for (size_t i = first_piece_index; i < static_cast<size_t>(boardHeight) - 4; i += boardWidth) {
		for (size_t j = i; j % boardWidth < static_cast<size_t>(boardWidth) - 4; j++) {
			if (pieceList[j].boardDisplay != "B" && pieceList[j + diagonal_upper_right].boardDisplay != "B" && 
				pieceList[j + 2* diagonal_upper_right].boardDisplay != "B" &&
				pieceList[j + 3* diagonal_upper_right].boardDisplay != "B" && 
				pieceList[j + 4* diagonal_upper_right].boardDisplay != "B") {
				return false;
			}
		}
	}

	//diagonal to bottom right, black
	for (size_t i = first_piece_index; i < static_cast<size_t>(boardHeight) - 4; i += boardWidth) {
		for (size_t j = i; j % boardWidth < static_cast<size_t>(boardWidth) - 4; j++) {
			if (pieceList[j].boardDisplay != "W" && pieceList[j + diagonal_lower_right].boardDisplay != "W" &&
				pieceList[j + 2 * diagonal_lower_right].boardDisplay != "W" &&
				pieceList[j + 3 * diagonal_lower_right].boardDisplay != "W" &&
				pieceList[j + 4 * diagonal_lower_right].boardDisplay != "W") {
				return false;
			}
		}
	}

	//diagonal to upper right, white
	for (size_t i = first_piece_index; i < static_cast<size_t>(boardHeight) - 4; i += boardWidth) {
		for (size_t j = i; j % boardWidth < static_cast<size_t>(boardWidth) - 4; j++) {
			if (pieceList[j].boardDisplay != "B" && pieceList[j + diagonal_lower_right].boardDisplay != "B" &&
				pieceList[j + 2 * diagonal_lower_right].boardDisplay != "B" &&
				pieceList[j + 3 * diagonal_lower_right].boardDisplay != "B" &&
				pieceList[j + 4 * diagonal_lower_right].boardDisplay != "B") {
				return false;
			}
		}
	}

	// no possible path for a winning condition
	return true;
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
			piece = "B";
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



