#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <istream>
#include <sstream>
#include <memory>
#include "gamePiece.h"

//Enumeration values for program return values.
enum returnVal {
	success,
	failure,
	extractFailure,
	invalidInput,
	quitGame,
	drawGame,
	incorrectInput,
	bad_allocation
};

//Enumeration values for program input check.
enum programVal {
	programname,
	filename,
	commandLineNum
};

//Enumeration values for displacement in row or column
enum displacementNum {
	displace0,
	displace1,
	displace2,
	displace3,
	displace4,
	displace5,
	displace8 = 8,
	displace10 = 10,
	displace12 = 12,
	displace16= 16
};

//The TicTacToe game class.
class GameBase {
public:
	static GameBase* checkArg(int argc, char* argv[]);
	mutable std::vector<gamePiece> pieceList; //vector of all pieces on the board.
	virtual bool done() = 0;
	virtual bool draw() = 0;
	virtual int prompt(unsigned int& x, unsigned int& y);
	virtual int turn() = 0;
	int play();
	int moves_num; //tracks total number of moves made by both players.
	virtual void print() = 0;

	GameBase();

	int userMessage();

protected:
	int boardWidth; 
	int boardHeight; 
	std::string piece; //tracks current piece to be played by a player.
	std::string winner;//saves game piece of the player who won the game.
	std::vector<std::pair<int, int>> player1; //vector of all moves by player X.
	std::vector<std::pair<int, int>> player2; //vector of all moves by player O.

	unsigned int longestDispLen;//tracks the longest display string length of any piece on the board
};



class TicTacToe : public GameBase {
public:
	TicTacToe();
	friend std::ostream& operator<<(std::ostream& out, const TicTacToe& game);
	virtual int turn();
	virtual bool draw();
	//Prints the object
	virtual void print() override;
	virtual bool done();
};



class GomokuGame : public GameBase {
public:
	GomokuGame();
	friend std::ostream& operator<<(std::ostream& out, const GomokuGame& game);
	virtual int turn();
	virtual bool draw();
	//Prints the object
	virtual void print() override;
	virtual bool done();
};
int userMessage();

