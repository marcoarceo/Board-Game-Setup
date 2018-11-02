/*
Programming Assignmnet 4 (Board Game)
Programmers: Paul Dibble (paul.dibble@wsu.edu) and Marco Arceo (marco.arceo@wsu.edu)
*/

#include "player.h"

Player::Player() // Iniializes the variables to 0
{
	this->playerID = 0;
	this->locationX = 0;
	this->locationY = 0;
}

Player::~Player(){}

Player::Player(int ID, int X, int Y) // Implements the values into the variables inside private
{
	this->playerID = ID;
	this->locationX = X;
	this->locationY = Y;
	this->position = generate_position_string();
}

string Player::generate_position_string()  // Converts the coordinates into a string
{
	int tempX = this->locationX;
	int tempY = this->locationY;
	string y = "";
	string ret = "";

	do {
		ret = (char)((tempX % 10) + 48) + ret;	//retrieves the last digit and adds it to the string
		tempX = tempX / 10;				//removes last digit from number

	} while (tempX != 0);

	ret = ret + ',';					//adds comma between the x and y cordinate

	do {
		y = (char)((tempY % 10) + 48) + y;//retrieves the last digit and adds it to the string
		tempY = tempY / 10;			//removes last digit from number

	} while (tempY != 0);
	ret = ret + y;					//adds the strings together

	return ret;
}

int Player::getPlayerID() // Returns the player ID
{
	return this->playerID;
}

int Player::getlocationX() // Returns the x coordinate
{
	return this->locationX;
}

int Player::getlocationY() // Returns the y coordinate
{
	return this->locationY;
}

string Player::getPlayerPosition() // Returns the players position
{
	return this->position;
}

void Player::setlocationX(int locationX) // Sets the variable to the passed in value
{
	this->locationX = locationX;
}

void Player::setlocationY(int locationY) // Sets the variable to the passed in value
{
	this->locationY = locationY;
}

void Player::setPlayerPoisition(int locationX, int locationY) // Sets the players position with the coordinates
{
	this->locationX = locationX;
	this->setlocationX(locationX);
	this->locationY = locationY;
	this->setlocationY(locationY);
	this->position = generate_position_string();
}