
Authors: Jinfeng Chen (c.jinfeng@wustl.edu), Daniel Ryu, Matthew Kim

CSE 332S  Lab 4

This program supports two games, Tic-Tac-Toe and Gomoku. 
Users can play Tic-Tac-Toe, Gomoku, or customized Gomoku with appropriate command line arguments:

	"TicTacToe" for the Tic-Tac-Toe game, 
	"Gomoku" for the standard Gomoku game, which has a 19 by 19 gameboard and winning condition of 5 pieces in any directions
	"Gomoku x y" for the customized Gomoku game, which has an x by x gameboard and wining condition of y pieces in any directions


Return Codes:

	0 - Success



Work Assignment

	6. Daniel R.
	7. Daniel R.
	8. Jinfeng C. -- need work on implementation of updating longestDispLen
	9. Matthew K.
	10.-12. Jinfeng C.
	13.-15. Daniel R.
	16. Jinfeng C.
	17. Daniel R.
	18. Daniel R. Jinfeng C.
	20.-23. Daniel R.
	24. Matthew K. Daniel R.
	25. Matthew k. 
	26. Jinfeng C. Daniel R.
	27. Daniel R.
	-----
	34. Daniel R.
	35. JinFeng C. Daniel R.
	36.	Daniel R.
	

Errors/Warnings:

	- When the coordinate contained a two digit integer value, its display on the board was relatively more shifted to the right compared to the pieces with single digit
	coordinate value. 

	- The program didnt take into account how the board was set up differently between TicTacToe and Gomoku. In TicTacToe, the x and y axis coordinate label
	begins from 0, while in Gomoku, it begins from 1. Also, coordinate value of 1 was out of bounds in TicTacToe, while in Gomoku, it represented the lowest
	possible value for an inbound coordinate.

	C4267: 'initializing': conversion from 'size_t' to 'int', possible loss of data
		Solved by redeclaring variable as size_t variable
	E0392	member function "TicTacToe::turn" may not be redeclared outside its class	
		Solved by adding a closing bracket to the previous code segment
	
	C26451  Arithmetic overflow: Using operator '+' on a 4 byte value and then casting the result to a 8 byte value. 
			Cast the value to the wider type before calling operator '+' to avoid overflow (io.2).	
		Solved by static_cast to size_t/ add (long) to cast the number bigger
	
	E0020	identifier "playerO" is undefined
		Solved by declaring the member variable and defined it in the constructor body


	C4018	'>': signed/unsigned mismatch
		Solved by changing one variable from int to size_t

Test Cases:

Case #1 - Well formed cmd line for TicTacToe, player X wins:

$ ./lab4Solution.exe TicTacToe
Input coordinate for your piece. Example: 1,1 : 1,3
4
3   X   O
2   X
1   X O
0
  0 1 2 3 4

Player X: 1,1; 1,2; 1,3;
Player X wins the game


Case #2 - Well formed cmd line for TicTacToe, draw:

$ ./lab4Solution.exe TicTacToe
Input coordinate for your piece. Example: 1,1 : 3,1
4
3   O X O
2   X X O
1   X O X
0
  0 1 2 3 4

Player X: 1,1; 1,2; 2,2; 2,3; 3,1;
Players Draw!
Number of Moves: 9


Case #3, #4 - Wrong cmd line argument(wrong game name, game name is missing):

$ ./lab4Solution.exe tictactoe
Usage: lab4Solution.exe TicTacToe OR lab4Solution.exe Gomoku
If you would like to play customized Gomoku,
Usage: lab4Solution.exe Gomoku [boardsize] [number of connected pieces to win]
Example: lab4Solution.exe Gomoku 8 4

$ ./lab4Solution.exe
Usage: lab4Solution.exe TicTacToe OR lab4Solution.exe Gomoku
If you would like to play customized Gomoku,
Usage: lab4Solution.exe Gomoku [boardsize] [number of connected pieces to win]
Example: lab4Solution.exe Gomoku 8 4


Case #5 - Invalid move inputs(move for an invalid coordinate, move for an already played coordinate, wrong input format):

Input coordinate for your piece. Example: 1,1 : 1,1
4
3
2
1   X
0
  0 1 2 3 4

Player X: 1,1;
current player: O
Input coordinate for your piece. Example: 1,1 : 1,1
Board coordinate has been played, choose another
Input coordinate for your piece. Example: 1,1 : 1,0
Coordinate out of bounds
Input coordinate for your piece. Example: 1,1 : 1 2
Incorrect input format


case #6 - User quits:

current player: B
Input coordinate for your piece. Example: 1,1 : quit
Player B quit the game
Number of moves made: 4


Case #7 - Well formed cmd line for Gomoku, player B wins:

current player: B
Input coordinate for your piece. Example: 1,1 : 14,14
19
18
17
16
15
14                               B
13                         W  B  W
12                         B
11                      B
10                   B  W
 9                 W
 8
 7
 6
 5
 4
 3
 2
 1
 X 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19

Player B: 10,10; 11,11; 12,12; 13,13; 14,14;
Player B wins the game




--------Extra Credit--------------------------------------------------------------------------------------------------------

TEST CASE #1 - Gomoku game with two additional arguments 3 and 3:

$ ./lab4Solution.exe Gomoku 3 3
current player: B
Input coordinate for your piece. Example: 1,1 : 3,3
 3     B
 2   B
 1 B W W
 X 1 2 3

Player B: 1,1; 2,2; 3,3;
Player B wins the game


TEST CASE #2
Cmd Line: lab4Solution.exe Gomoku 5 4
5 B     W B
4       W W
3     B
2   W     B
1 B     B W
X 1 2 3 4 5

Result: Players Draw!

TEST CASE #3
Cmd Line: lab4Solution.exe Gomoku 5 3
5
4
3 B
2   B
1     B W W
X 1 2 3 4 5

Result: Player B Wins!

TEST CASE #4
Cmd Line: lab4Solution.exe Gomoku 10 5
10
 9
 8
 7
 6
 5 B
 4   B
 3     B
 2       B
 1         B W W W W
 X 1 2 3 4 5 6 7 8 9 10

 Result: Player B Wins!

 TEST CASE #5
 Cmd Line: lab4Solution.exe Gomoku 10 4
 10
 9
 8
 7
 6
 5
 4       B
 3     B
 2 W B
 1 B W   W
 X 1 2 3 4 5 6 7 8 9 10

 Result: Player B Wins!

 TEST CASE #6
 Cmd Line:lab4Solution.exe Gomoku

19
18
17
16
15
14
13
12
11
10
9
8
7
6
5     B
4     B W
3     B W
2 W W B W
1 B B B W
X 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19


TEST CASE #7 - Gomoku game without additional arguements:

$ ./lab4Solution.exe Gomoku
19
18
17
16
15
14
13
12
11
10
 9
 8
 7
 6
 5
 4
 3
 2
 1
 X 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19

current player: B
Input coordinate for your piece. Example: 1,1 :


TEST CASE #8 - Wrong cmd line argument(wrong number of additional arguments, invalid argument for board size - zero or negative number, 
										wrong argument format):

$ ./lab4Solution.exe Gomoku 3
Usage: lab4Solution.exe TicTacToe OR lab4Solution.exe Gomoku
If you would like to play customized Gomoku,
Usage: lab4Solution.exe Gomoku [boardsize] [number of connected pieces to win]
Example: lab4Solution.exe Gomoku 8 4

$ ./lab4Solution.exe Gomoku 0 4
Usage: lab4Solution.exe TicTacToe OR lab4Solution.exe Gomoku
If you would like to play customized Gomoku,
Usage: lab4Solution.exe Gomoku [boardsize] [number of connected pieces to win]
Example: lab4Solution.exe Gomoku 8 4

$ ./lab4Solution.exe Gomoku -3 4
Usage: lab4Solution.exe TicTacToe OR lab4Solution.exe Gomoku
If you would like to play customized Gomoku,
Usage: lab4Solution.exe Gomoku [boardsize] [number of connected pieces to win]
Example: lab4Solution.exe Gomoku 8 4

$ ./lab4Solution.exe Gomoku 3,3
Usage: lab4Solution.exe TicTacToe OR lab4Solution.exe Gomoku
If you would like to play customized Gomoku,
Usage: lab4Solution.exe Gomoku [boardsize] [number of connected pieces to win]
Example: lab4Solution.exe Gomoku 8 4
