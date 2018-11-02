/*
Programming Assignmnet 4 (Board Game)
Programmers: Paul Dibble (paul.dibble@wsu.edu) and Marco Arceo (marco.arceo@wsu.edu)
*/

#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <string>
#include <chrono>
using namespace std;
using namespace chrono;


class Player
{
public:
	Player(); // Constructs the new player
	~Player(); // Erases all dynamic memory

	Player(int ID, int X, int Y);

	// GETTERS
	int getPlayerID(); // Gets the players ID number
	int getlocationX(); // Gets the x coordinate
	int getlocationY(); // Gets the y coordinate
	string getPlayerPosition(); // Gets the players position

	// SETTERS
	void setlocationX(int locationX); // Sets the x coordinate
	void setlocationY(int locationY); // Sets the y coordinate
	void setPlayerPoisition(int locationX, int locationY); // Sets the players Position

private:
	string generate_position_string(); // Converts the coordinates to a string

	int playerID; // player ID
	int locationX; // x coordinate
	int locationY; // y coordinate

	string position; // Position as a string
};

#endif // !PLAYER_H

