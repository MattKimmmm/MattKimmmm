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
	size_t vert_inc = 19;
	size_t diag_inc_r = 20;
	size_t diag_inc_l = 18;
	for (size_t i = first_piece_index; i < static_cast<size_t>(boardHeight); i++) {
		for (size_t j = first_piece_index; j < static_cast<size_t>(boardWidth); j++) {
			size_t index = boardWidth * i + j;

			

			//Check for vertical 
			if (i + 4 < static_cast<size_t>(boardHeight)) {
				if (pieceList[index].boardDisplay != " " && pieceList[index].boardDisplay == pieceList[(long)index+vert_inc].boardDisplay 
					&& pieceList[index + vert_inc].boardDisplay == pieceList[(long)index + vert_inc* displace2].boardDisplay
					&& pieceList[(long)index + vert_inc* displace2].boardDisplay == pieceList[(long)index + vert_inc* displace3].boardDisplay
					&& pieceList[(long)index + vert_inc* displace3].boardDisplay == pieceList[(long)index + vert_inc* displace4].boardDisplay) {
					winner = pieceList[index].boardDisplay;
					return true;
				}
			}
			
			

			//check for horizontal
			if (j + 4 < static_cast<size_t>(boardWidth)) {
				if (pieceList[index].boardDisplay != " " && pieceList[index].boardDisplay == pieceList[index + displace1].boardDisplay
					&& pieceList[index + displace1].boardDisplay == pieceList[index + displace2].boardDisplay
					&& pieceList[index + displace2].boardDisplay == pieceList[index + displace3].boardDisplay
					&& pieceList[index + displace3].boardDisplay == pieceList[index + displace4].boardDisplay) {
					winner = pieceList[index].boardDisplay;
					return true;
				}
			}

			//diagonal to the right check
			if (i < 16 && j < 16) {
				if (pieceList[index].boardDisplay != " " && pieceList[index].boardDisplay == pieceList[(long)index + diag_inc_r].boardDisplay
					&& pieceList[(long)index + diag_inc_r].boardDisplay == pieceList[(long)index + diag_inc_r * displace2].boardDisplay
					&& pieceList[(long)index + diag_inc_r * displace2].boardDisplay == pieceList[(long)index + diag_inc_r * displace3].boardDisplay
					&& pieceList[(long)index + diag_inc_r * displace3].boardDisplay == pieceList[(long)index + diag_inc_r * displace4].boardDisplay) {
					winner = pieceList[index].boardDisplay;
					return true;
				}
			}
			
			//diagonal to the left check
			if (i < 16 && j >= 5) {
				if (pieceList[index].boardDisplay != " " && pieceList[index].boardDisplay == pieceList[index + diag_inc_l].boardDisplay
					&& pieceList[index + diag_inc_l].boardDisplay == pieceList[index + diag_inc_l * displace2].boardDisplay
					&& pieceList[index + diag_inc_l * displace2].boardDisplay == pieceList[index + diag_inc_l * displace3].boardDisplay
					&& pieceList[index + diag_inc_l * displace3].boardDisplay == pieceList[index + diag_inc_l * displace4].boardDisplay) {
					winner = pieceList[index].boardDisplay;
					return true;
				}
			}
		}
	}
	
	//game is not done yet
	return false;
}

/*Declare and define a public virtual (non-static) draw() method that takes no
parameters(other than the this pointer that's passed implicitly to all non-static methods
and operators) and has a bool return type. The method should return true if there is no
path left that can lead to 5 stones in a row, otherwise the method should return false.*/

/*
bool GomokuGame::draw() {
	size_t first_piece_index = 0;
	size_t diagonal_upper_right = static_cast<size_t>(boardWidth) + 1;
	size_t diagonal_lower_right = static_cast<size_t>(boardWidth) - 1;

	//horizontal check for black
	for (size_t i = first_piece_index; i < boardHeight; i += boardWidth) {
		for (size_t j = i; j % boardWidth < static_cast<size_t>(boardWidth) - displace4; j++) {
			//starting from the initial piece, check all 5 spots in the path if there is a white stone.
			//Path is valid if there are no white stones
			if (pieceList[j].boardDisplay != "W" && pieceList[j + displace1].boardDisplay != "W" && pieceList[j + displace2].boardDisplay != "W" &&
				pieceList[j + displace3].boardDisplay != "W" && pieceList[j + displace4].boardDisplay != "W") {
				return false;
			}
		}
	}

	//horizontal check for white
	for (size_t i = first_piece_index; i < boardHeight; i += boardWidth) {
		for (size_t j = i; j % boardWidth < static_cast<size_t>(boardWidth) - displace4; j++) {
			if (pieceList[j].boardDisplay != "B" && pieceList[j + displace1].boardDisplay != "B" && pieceList[j + displace2].boardDisplay != "B" &&
				pieceList[j + displace3].boardDisplay != "B" && pieceList[j + displace4].boardDisplay != "B") {
				return false;
			}
		}
	}

	//vertical check for black
	for (size_t i = first_piece_index; i < static_cast<size_t>(boardHeight) - displace4; i += boardWidth) {
		for (size_t j = i; j % boardWidth < boardWidth; j++) {
			if (pieceList[j].boardDisplay != "W" && pieceList[j + boardWidth].boardDisplay != "W" &&
				pieceList[j + displace2 * static_cast<size_t>(boardWidth)].boardDisplay != "W" &&
				pieceList[j + displace3 * static_cast<size_t>(boardWidth)].boardDisplay != "W" &&
				pieceList[j + displace4 * static_cast<size_t>(boardWidth)].boardDisplay != "W") {
				return false;
			}
		}
	}

	//vertical check for white
	for (size_t i = first_piece_index; i < static_cast<size_t>(boardHeight) - displace4; i += boardWidth) {
		for (size_t j = i; j % boardWidth < boardWidth; j++) {
			if (pieceList[j].boardDisplay != "B" && pieceList[j + boardWidth].boardDisplay != "B" && 
				pieceList[j + displace2* static_cast<size_t>(boardWidth)].boardDisplay != "B" &&
				pieceList[j + displace3* static_cast<size_t>(boardWidth)].boardDisplay != "B" &&
				pieceList[j + displace4* static_cast<size_t>(boardWidth)].boardDisplay != "B") {
				return false;
			}
		}
	}

	//diagonal to upper right, black
	for (size_t i = first_piece_index; i < static_cast<size_t>(boardHeight) - displace4; i += boardWidth) {
		for (size_t j = i; j % boardWidth < static_cast<size_t>(boardWidth) - displace4; j++) {
			if (pieceList[j].boardDisplay != "W" && pieceList[j + diagonal_upper_right].boardDisplay != "W" &&
				pieceList[j + displace2 * diagonal_upper_right].boardDisplay != "W" &&
				pieceList[j + displace3 * diagonal_upper_right].boardDisplay != "W" &&
				pieceList[j + displace4 * diagonal_upper_right].boardDisplay != "W") {
				return false;
			}
		}
	}

	//diagonal to upper right, white
	for (size_t i = first_piece_index; i < static_cast<size_t>(boardHeight) - displace4; i += boardWidth) {
		for (size_t j = i; j % boardWidth < static_cast<size_t>(boardWidth) - displace4; j++) {
			if (pieceList[j].boardDisplay != "B" && pieceList[j + diagonal_upper_right].boardDisplay != "B" && 
				pieceList[j + displace2* diagonal_upper_right].boardDisplay != "B" &&
				pieceList[j + displace3* diagonal_upper_right].boardDisplay != "B" &&
				pieceList[j + displace4* diagonal_upper_right].boardDisplay != "B") {
				return false;
			}
		}
	}

	//diagonal to bottom right, black
	for (size_t i = first_piece_index; i < static_cast<size_t>(boardHeight) - displace4; i += boardWidth) {
		for (size_t j = i; j % boardWidth < static_cast<size_t>(boardWidth) - displace4; j++) {
			if (pieceList[j].boardDisplay != "W" && pieceList[j + diagonal_lower_right].boardDisplay != "W" &&
				pieceList[j + displace2 * diagonal_lower_right].boardDisplay != "W" &&
				pieceList[j + displace3 * diagonal_lower_right].boardDisplay != "W" &&
				pieceList[j + displace4 * diagonal_lower_right].boardDisplay != "W") {
				return false;
			}
		}
	}

	//diagonal to upper right, white
	for (size_t i = first_piece_index; i < static_cast<size_t>(boardHeight) - displace4; i += boardWidth) {
		for (size_t j = i; j % boardWidth < static_cast<size_t>(boardWidth) - displace4; j++) {
			if (pieceList[j].boardDisplay != "B" && pieceList[j + diagonal_lower_right].boardDisplay != "B" &&
				pieceList[j + displace2 * diagonal_lower_right].boardDisplay != "B" &&
				pieceList[j + displace3 * diagonal_lower_right].boardDisplay != "B" &&
				pieceList[j + displace4 * diagonal_lower_right].boardDisplay != "B") {
				return false;
			}
		}
	}

	// no possible path for a winning condition
	return true;
}

*/

bool GomokuGame::draw() {

	int num2Win = 5;//Number of pieces to connect to win

	//Rows are from bottom to top, columns are from left to right
	

	//Iterate through each row
	for (int row = boardHeight - 1; row >= 0; --row) {

		//Iterate through each column (of each row)
		for (int col = 0; col < boardWidth - 1; ++col) {

			int index = row * boardWidth + col;

			//Only check horizontal empty spaces for pieces at 0 to (boardwidth -num2Win) columns
			if (col <= boardWidth - num2Win) {

				//Check if this and the next four pieces are empty, if so, not draw

				bool allEmpty = true;//Tracks if all horizontal pieces are emtpy
				for (int i = index; i < index + num2Win; ++i) {
					if (pieceList[index].boardDisplay.compare(" ") != 0) {

					}
				}

				
				//if()

			}


		}
	}
	return false;
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



