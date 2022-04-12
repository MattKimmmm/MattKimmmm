
CSE 332S

Lab 4

Jinfeng Chen, Daniel Ryu, Matthew Kim

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
	

Test Cases:

TEST CASE #1
Cmd Line: lab4Solution.exe Gomoku 5 4
5 B     W B
4       W W
3     B
2   W     B
1 B     B W
X 1 2 3 4 5

Result: Players Draw!

TEST CASE #2
Cmd Line: lab4Solution.exe Gomoku 5 3
5
4
3 B
2   B
1     B W W
X 1 2 3 4 5

Result: Player B Wins!

TEST CASE #3
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

 TEST CASE #4
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

 TEST CASE #5
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

Result: Player B Wins!
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


