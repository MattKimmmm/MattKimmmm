#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <istream>
#include <sstream>
#include "gamePiece.h"

//The TicTacToe game class.
class TicTacToe {
public:
	TicTacToe();
	friend std::ostream& operator<<(std::ostream& out, const TicTacToe& game);
	mutable std::vector<gamePiece> pieceList; //vector of all pieces on the board.
	bool done();
	bool draw();
	int prompt(unsigned int& x, unsigned int& y);
	int turn();
	int play();
	int moves_num; //tracks total number of moves made by both players.
private:
	int boardWidth; //5
	int boardHeight; //5
	char piece; //tracks current piece to be played by a player.
	char winner;//saves game piece of the player who won the game.
	std::vector<std::pair<int, int>> playerX; //vector of all moves by player X.
	std::vector<std::pair<int, int>> playerO; //vector of all moves by player O.
};