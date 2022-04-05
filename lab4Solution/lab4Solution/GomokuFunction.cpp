#include "gameBase.h"

using namespace std;
GomokuGame::GomokuGame() {
	GomokuGame game;
	game.boardWidth = 19;
	game.boardHeight = 19;
	game.piece = "B";
	game.winner = " ";
	game.player1 = {};
	game.player2 = {};
}

bool GomokuGame::done() {

}
void GomokuGame::print() {
	cout << *this << endl;
}
