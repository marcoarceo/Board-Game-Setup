/*
Programming Assignmnet 4 (Board Game)
Programmers: Paul Dibble (paul.dibble@wsu.edu) and Marco Arceo (marco.arceo@wsu.edu)
*/

#ifndef BOARD_H
#define BOARD_H

#include "player.h"

class Board
{
public:
	Board(int m); // Initializes the board game
	~Board(); // Erases all dynamic memory

	bool insert(int playerID, int newX, int newY); // inserts a new player
	Player find(int playerID); // finds a player based on ID
	bool remove(int playerID); // removes a player based on ID
	bool moveTo(int playerID, int locationX, int locationY); // Moves a player based on ID to a new location
	void printByID(); // Prints all players ID and positions


	bool checkPlayerSize(); // Checks the size of the board
	bool checkNewPosition(int newX, int newY); // Checks if the new position is valid
	bool board_contains(int playerID);//checks if the player exists in board;
	bool position_contains(string pos);//checks if a player is at a position
	bool checkMove(int playerID, int locationX, int locationY); // Checks if the move is valid

private:
	int m; // size of the board --> m x m (can not change)
	int n; // number of players (allowed to change)

	map<int, Player> board; // This map holds the ID as the key and player information as the value
	map<string, int> position; // This map holds the position string as the key and ID as the value
};
#endif
