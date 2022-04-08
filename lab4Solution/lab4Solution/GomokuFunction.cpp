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

bool GomokuGame::done() {
	return false;
}
void GomokuGame::print() {
	cout << *this << endl;
}
