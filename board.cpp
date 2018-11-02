/*
Programming Assignmnet 4 (Board Game)
Programmers: Paul Dibble (paul.dibble@wsu.edu) and Marco Arceo (marco.arceo@wsu.edu)
*/

#include "board.h"

Board::Board(int m) // Clears the maps and assigns the size of the board
{
	this->m = m;
	position.clear();
	board.clear();
}

Board::~Board() // Clears the maps
{
	position.clear();
	board.clear();
}

bool Board::insert(int playerID, int newX, int newY)
{
	string pos = Player(playerID, newX, newY).getPlayerPosition(); // Converts the players coordinates into a position string

	if (checkPlayerSize()) // Checks the size of the board
	{
		if (!board_contains(playerID)) // Checks to see if the player is already inside the board
		{														
			if (position_contains(pos) == false) // Checks if there is already a player at that position
			{																			
				board[playerID] = Player(playerID, newX, newY); // Assigns the playerID as the key and makes the Player information the value
				position.insert(pair<string, int>(pos, playerID));	// Assigns the position string as the key and the playerID as the value
			}
			else
			{
				cout << "player " << board[position[Player(playerID, newX, newY).getPlayerPosition()]].getPlayerID() << " is already there\n"; // Prints that the player is already at that position
				return false;
			}
		}
		else
		{
			cout << "This player is already on the board: " << playerID << endl << endl; // Prints that the player is already on the board
			return false;
		}
	}
	else
	{
		return 0;
	}
	n++;
	return true;
}

Player Board::find(int playerID)
{
	Player temp(0, 0, 0); // Creates a temporary

	if (board_contains(playerID)) // Checks if the player is contained in the board
	{
		return board.find(playerID)->second; // Returns the players information
	}
	else
	{
		return temp; // Returns the temporary
	}
}


bool Board::remove(int playerID)
{
	if (this->board_contains(playerID)) // Checks if the player is contained in the board
	{
		this->position.erase(board[playerID].getPlayerPosition()); // Removes the player from the position map
		this->board.erase(playerID); // Removes the player from the board map
		n--; // Decrements the player size
		return true;															
	}
	else
	{
		return false;													
	}
}

bool Board::position_contains(string pos)
{
	map<string, int>::iterator foundIter = position.find(pos); // Creates an iterator for the position map

	if (foundIter != position.end()) // Checks if the position is already being used
	{
		return true;													//return true
	}
	else
	{
		return false;													//returrn false
	}
}

bool Board::board_contains(int playerID)
{
	map<int, Player>::iterator foundIter = board.find(playerID); // Creates an iterator for the board map

	if (foundIter != board.end()) // Checks if the player is in the board
	{
		return true;													//return true
	}
	else
	{
		return false;													//returrn false
	}

}

bool Board::moveTo(int playerID, int locationX, int locationY)
{
	// Check the position of insertion with the function checkNewPosition
	// Check if the player
	if (board_contains(playerID)) // Checks to see if the player is in the board
	{
		if (this->checkNewPosition(locationX, locationY)) // Checks if the new position is valid
		{																	
			if (checkMove(playerID, locationX, locationY)) // Checks if the movement is valid
			{
				position.erase(board[playerID].getPlayerPosition()); //erases the current position
				board[playerID].setPlayerPoisition(locationX, locationY); //changes player position to new position

				if (position_contains(board[playerID].getPlayerPosition())) //checks if there is another player at the new position
				{
					cout << playerID << " killed player " << this->position[board[playerID].getPlayerPosition()] << endl; //displays which player was killed

					this->remove(position[board[playerID].getPlayerPosition()]); // Removes the player at that position
					position[board[playerID].getPlayerPosition()] = playerID; // The new player is assigned the position
					return 1;
				}
				else
				{
					position[board[playerID].getPlayerPosition()] = playerID; //if there is not a player  create new position
					return 1;
				}
			}
		}
	}
	return 0;
}

void Board::printByID()
{
	map<int, Player>::iterator foundIter = board.begin(); // Creates an iterator for the board map
	//map<string, int>::iterator location = position.begin();
	do
	{
		cout << "Player: " << foundIter->first << " Postion: " << foundIter->second.getPlayerPosition() << endl; // Prints the player ID followed by the string position
		//cout << "Player: " << location->second << " Postion: " << location->first << endl;
		//location++;
		foundIter++; // Increments the iterator
	} while (foundIter != board.end()); //&& location != position.end());
	cout << endl;
}


bool Board::checkNewPosition(int newX, int newY)
{
	if ((newX > m) || (newY > m)) // Checks if either coordinate is greater than the board size
	{
		cout << "The player position is out of the board" << endl;
		return false;
	}
	else if ((newX < 0) || (newY < 0)) // Checks if either coordinate is less than the board size
	{
		cout << "The player positon is out of the board" << endl;
		return false;
	}
	else { return true; }
}


bool Board::checkPlayerSize()
{
	if (n > m || n == m) // Checks if the player size is equal to or greater than the board
	{
		cout << "Board capacity is full" << endl;
		return false;
	}
	else { return true; }
}

bool Board::checkMove(int playerID, int locationX, int locationY)
{
	int originalX, originalY;
	int xDirection, yDirection;

	map<int, Player>::iterator foundIter = board.find(playerID); // Creates an iterator for the board map

	originalX = foundIter->second.getlocationX(); // Assigns the players current x coordinate
	originalY = foundIter->second.getlocationY(); // Assigns the players current x coordinate

	xDirection = abs(originalX - locationX); // Subtracts the current coordinate and the new coordinate and gets a absolute value
	yDirection = abs(originalY - locationY);

	if (xDirection == yDirection || xDirection == 0 || yDirection == 0) // Checks if the movement is valid
	{
		return true;
	}
	else
	{
		cout << "The move is invalid" << endl << endl;
		return false;
	}
}