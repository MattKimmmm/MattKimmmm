#include "gamePiece.h"
#include "gameBase.h"
#include "lab3.h"
#include "gameBase.h"
#include <string>
#include <vector>
#include <iostream>
#include <istream>
#include <sstream>

using namespace std;

//Checks if the game is over by checking if one of the player
//has placed 3 consecutive game pieces on the board.
bool TicTacToe::done() {
	unsigned long long firstPieceIndex = 6;

	//checks if there are 3 horizontally consecutive pieces.
	for (unsigned long long i = 6; i < 17; i = i + 5)
	{
		if (pieceList[i].boardDisplay != ' ' && pieceList[i].boardDisplay == pieceList[i + 1].boardDisplay
			&& pieceList[i + 1].boardDisplay == pieceList[i + 2].boardDisplay)
		{
			winner = pieceList[i].boardDisplay; //assign the piece as winning piece.
			return true;
		}
	}

	//checks if there are 3 vertically consecutive pieces.
	for (unsigned long long i = firstPieceIndex; i < 9; i++) {
		if (pieceList[i].boardDisplay != ' ' && pieceList[i].boardDisplay == pieceList[i + 5].boardDisplay
			&& pieceList[i + 5].boardDisplay == pieceList[i + 10].boardDisplay)
		{
			winner = pieceList[i].boardDisplay;
			return true;
		}
	}

	//checks if there are 3 diagonally(from bottom-left to top-right) consecutive pieces. 
	if (pieceList[firstPieceIndex].boardDisplay != ' ' && pieceList[firstPieceIndex].boardDisplay == pieceList[firstPieceIndex * 2].boardDisplay
		&& pieceList[firstPieceIndex * 2].boardDisplay == pieceList[firstPieceIndex * 3].boardDisplay)
	{
		winner = pieceList[firstPieceIndex].boardDisplay;
		return true;
	}

	//checks if there are 3 diagonally(from top-left to bottom-right) consecutive pieces.
	if (pieceList[8].boardDisplay != ' ' && pieceList[8].boardDisplay == pieceList[12].boardDisplay && pieceList[12].boardDisplay == pieceList[16].boardDisplay) {
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

//prompts players to input coordinates for their piece. If the input is invalid, prompt the player again.
int GameBase::prompt(unsigned int& x, unsigned int& y) {
	string userInput;
	cout << "Input coordinate for your piece. Example: 1,1 : ";
	cin >> userInput; //receieve input from user.

	vector <string> coordinateInput; //vector to save x and y coordinate of piece.
	string coordinate;
	stringstream temp(userInput);
	getline(temp, coordinate);

	//check if the user input is quit, which then quits the game.
	if (coordinate == "quit")
	{
		cout << "Player " << piece << " quit the game" << endl;
		return quitGame;
	}
	//check if the coordinate input is 3, has comma in the middle, and each coordinate value is an integer.
	else if (coordinate.length() != 3 || coordinate.at(1) != ',' || !isdigit(coordinate.at(0)) || !isdigit(coordinate.at(2)))
	{
		cout << "Invalid Input Format, x and y coordinates must be between 1 - 3. Example: 1,1" << endl;
		prompt(x, y);
	}
	else
	{
		coordinate.at(1) = ' '; // change comma to space to pass the string to stringstream.
		istringstream iss(coordinate);
		if (iss >> x && iss >> y) {
			int index = boardWidth * y + x;
			//checks if the inputted coordinates are out of bounds.
			if (x < 1 || x > 3 || y < 1 || y > 3) {
				cout << "Coordinate out of bounds" << endl;
				prompt(x, y);
			}
			//check if the board coordinate is already occupied.
			else if (pieceList[index].boardDisplay != ' ') {
				cout << "Board coordinate has been played, choose another " << endl;
				prompt(x, y);
			}
			else {
				if (piece == 'X') {
					pieceList[index].boardDisplay = 'X';
					playerX.push_back(make_pair(x, y));
				}
				else if (piece == 'O') {
					pieceList[index].boardDisplay = 'O';
					playerO.push_back(make_pair(x, y));
				}



				//Updates the longestDispLen variable if the new game piece has a longer length
				int length = piece.boardDisplay.length(); //A temp variable that keeps the length of the game piece display
				if (length > longestDispLen) {
					longestDispLen = length;
				}
			}
		}
		else {
			cout << "coordinate extraction failure" << endl;
			return extractFailure;
		}
	}
	return success;
}

//Prompts game to change player turn.
int TicTacToe::turn() {
	unsigned int x_coor = 0;
	unsigned int y_coor = 0;
	int promptResult;
	if (piece == 'X') {
		cout << "current player: X" << endl;
		promptResult = prompt(x_coor, y_coor);
		if (promptResult == success) {
			cout << *this << endl; //print board
			cout << "Player X: "; //print player's past moves.
			for (unsigned int i = 0; i < playerX.size(); i++) {
				cout << playerX[i].first << "," << playerX[i].second << "; ";
			}
			cout << endl;
			piece = 'O'; // switch player turn
			moves_num++; //increment total moves played by both players.
		}
		else {
			return promptResult;
		}
	}
	else if (piece == 'O') {
		cout << "current player: O" << endl;
		promptResult = prompt(x_coor, y_coor);
		if (promptResult == success) {
			cout << *this << endl;
			cout << "Player O: ";
			for (unsigned int i = 0; i < playerO.size(); i++) {
				cout << playerO[i].first << "," << playerO[i].second << "; ";
			}
			cout << endl;
			piece = 'X';
			moves_num++;
		}
		else {
			//tracks whether a player quit game, the program failed to extract coordinates, or if the coordinate was valid.
			return promptResult;
		}
	}
	return success;
}

/*Move the play() method from your derived class to the base class and modify it so that
instead of printing the game board using the ostream operator directly, it instead calls the
print() method (that allows each derived class to override printing using its own ostream
insertion operator).
*/
int GameBase::play() {
	print(); //print initial board.
	int turnCheck;
	while (!done() && !draw()) {
		turnCheck = turn();
		if (turnCheck == quitGame) {
			cout << "Number of moves made: " << moves_num << endl;
			return quitGame;
		}
		else if (turnCheck == extractFailure) {
			return extractFailure;
		}
	}
	if (done()) {
		cout << "Player " << winner << " wins the game" << endl;
		return success;
	}
	else if (draw()) {
		cout << "Players Draw!" << endl;
		cout << "Number of Moves: " << moves_num << endl;
		return drawGame;
	}
	return success;
}

 void TicTacToe:: print() {
	cout << *this << endl;
}