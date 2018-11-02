#include "board.h"

/*
Programming Assignmnet 4 (Board Game)
Programmers: Paul Dibble (paul.dibble@wsu.edu) and Marco Arceo (marco.arceo@wsu.edu)
*/

int main() {

	// This code is not a complete test code (won't even compile) and it may be syntactically inconsistent with your class definitions. 
	// So modify before use as appropriate. But the idea of testing should be clear. You are free to shuffle around the order of operations in order to devise more test cases of your own.

	ofstream results;
	Board B(100000);	// specifies that the game board size is 1000000 x 1000000 

					// the following is a sequence of calls to Board class methods assuming
					// 	the input example (m=10,n=8) given in the programming assignment.

	results.open("Results.txt", ios::app);
	auto start = high_resolution_clock::now();
	B.insert(1, 3, 2);	// assumed syntax: Insert(ID, x, y)
	B.insert(2, 4, 3);
	B.insert(3, 4, 6);
	B.insert(4, 5, 7);
	B.insert(5, 6, 3);
	B.insert(6, 8, 2);
	B.insert(7, 9, 3);
	B.insert(8, 9, 8);

	B.insert(3, 7, 6);	// should fail because player 3 is already there

	B.insert(10, 9, 8);	// should fail because 9,8 is occupied already
	B.printByID();

	B.moveTo(4, 9, 3);	//assumed syntax: MoveTo(ID,x,y) // removes 7 in the process
	B.printByID();

	B.moveTo(4, 9, 8);	// removes 8
	B.printByID();

	B.moveTo(4, 6, 3); // should fail because move to 6,3 is from 4's current position is not valid
	B.printByID();

	B.moveTo(2, 3, 3);
	B.printByID();

	B.moveTo(4, 3, 2);	// removes 1
	B.printByID();

	B.moveTo(4, 8, 2);	// removes 6
	B.printByID();

	B.moveTo(5, 3, 3);	// removes 2
	B.printByID();

	B.moveTo(4, 4, 6);	// removes 3
	B.printByID();

	B.moveTo(5, 4, 3);
	B.printByID();

	B.moveTo(4, 4, 3);	// removes 5
	B.printByID();

	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	cout << "Total Time: " << duration.count() << " microseconds" << endl;
	results << duration.count() << " microseconds" << endl;
	results.close();
	// the code should print only one player at this stage which is player 4 @ (4,3)

}