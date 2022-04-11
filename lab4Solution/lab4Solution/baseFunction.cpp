#include "gameBase.h"

using namespace std;
//prompts players to input coordinates for their piece. If the input is invalid, prompt the player again.
int GameBase::prompt(unsigned int& x, unsigned int& y) {
	string userInput;
	cout << "Input coordinate for your piece. Example: 1,1 : ";
	cin >> userInput; //receieve input from user.

	vector <string> coordinateInput; //vector to save x and y coordinate of piece.
	string coordinate;
	stringstream temp(userInput);
	getline(temp, coordinate);
	size_t maxCoor = 0;//keep track of the max value of a possible coordinate, changes depend on game type; e.g. maxCoor= 19 in Gomoku
	size_t minCoor = 0;
	size_t commaPos = -1;//tracks where the comma is in the input string (if present)
	bool isGomoku = false;

	//Determine the max value of input coordinates based on game type
	if ((piece == "X") || ((piece == "O"))) {
		maxCoor = 3;
		minCoor = 1;
	}
	else if ((piece == "B") || (piece == "W")) {
		maxCoor = 19;
		minCoor = 0;
		isGomoku = true;
	}

	//check if the user input is quit, which then quits the game.
	if (coordinate == "quit")
	{
		cout << "Player " << piece << " quit the game" << endl;
		return quitGame;
	}

	//find the position of comma
	commaPos = coordinate.find(',');

	//Checks if there is a comma in the input string; if so, execute codes
	if (commaPos != -1) {


		coordinate.at(commaPos) = ' '; // change comma to space to pass the string to stringstream.

		istringstream iss(coordinate);


		if (iss >> x && iss >> y) {
			int index = 0;
			if (isGomoku) {
				index = boardWidth * (y - 1) + (x - 1);
			}
			else {
				index = boardWidth * y + x;
			}
			//checks if the inputted coordinates are out of bounds.
			if (x < minCoor || x > maxCoor || y < minCoor || y > maxCoor) {
				cout << "Coordinate out of bounds" << endl;
				return prompt(x, y);
				
			}
			//check if the board coordinate is already occupied.
			else if (pieceList[index].boardDisplay != " ") {
				cout << "Board coordinate has been played, choose another " << endl;
				return prompt(x, y);
			}
			else {
				if (piece == "X") {
					pieceList[index].boardDisplay = "X";
					player1.push_back(make_pair(x, y));
				}
				else if (piece == "O") {
					pieceList[index].boardDisplay = "O";
					player2.push_back(make_pair(x, y));
				}
				else if (piece == "B") {
					pieceList[index].boardDisplay = "B";
					player1.push_back(make_pair(x, y));
				}
				else {
					pieceList[index].boardDisplay = "W";
					player2.push_back(make_pair(x, y));
				}

				//Updates the longestDispLen variable if the new game piece has a longer length
				unsigned int length = static_cast<unsigned int>(piece.length()); //A temp variable that keeps the length of the game piece display
				if (length > longestDispLen) {
					longestDispLen = length;
				}

				return success;
			}
		}
		else {
			cout << "coordinate extraction failure" << endl;
			return extractFailure;
		}


	}
	return failure;
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