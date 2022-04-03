#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <istream>
#include <sstream>
#include "gamePiece.h"

//The TicTacToe game class.
class GameBase {
public:
	friend std::ostream& operator<<(std::ostream& out, const TicTacToe& game);
	mutable std::vector<gamePiece> pieceList; //vector of all pieces on the board.
	virtual bool done() = 0;
	bool draw();
	bool done();
	virtual bool draw();
	int prompt(unsigned int& x, unsigned int& y);
	virtual int turn();
	int play();
	int moves_num; //tracks total number of moves made by both players.

	virtual void print() = 0;

	

protected:
	int boardWidth; //5
	int boardHeight; //5
	std::string piece; //tracks current piece to be played by a player.
	std::string winner;//saves game piece of the player who won the game.
	std::vector<std::pair<int, int>> playerX; //vector of all moves by player X.
	std::vector<std::pair<int, int>> playerO; //vector of all moves by player O.

	unsigned int longestDispLen;//tracks the longest display string length of any piece on the board
};

class TicTacToe : public GameBase {
public:
	TicTacToe();
	virtual int turn();
	virtual bool draw();

	//Prints the object
	virtual void print() override;
	
	virtual bool done();
};