/* ascii codes as follows, tested on same system. _getch is platform specific to win.
w = 119			up arrow =		72
a = 97			down arrow =	80
d = 100			left arrow =	75
s = 115			right arrow =	77*/


#include <iostream>
#include <conio.h>
#include <windows.h>
#include <random>
#include "Header.h"


enum Direction { Up, Down, Left, Right };
Direction DirMov;
long long WaitPeriod = 1000;
const int MapHeight = 20;
const int MapWidth = 20;
int SnakeLength = 3;
bool GameOver = false;


void GameSpeed()
{
	if (WaitPeriod > 300)
		WaitPeriod = (1000 - SnakeLength * 9);
};
//sets the pace of the game, via a decrease in wait time between ticks
//9ms per tick, to a floor of 300ms, from 1000ms at the games start.


class CellEntity
{
public:
	char DisplayChar = '.';
	int DecayTimer = 0;

	void CellUpdate()
	{
		if (DecayTimer > 0)
		{
			DisplayChar = '#';
			DecayTimer--;
		}
		else
		{
			DisplayChar = '.';
		}
		std::cout << DisplayChar; //check to see if snake body is there via the decay timer & update the ascii char, then print to console.
	};
};

CellEntity EntityMap[MapWidth][MapHeight];

class SnakeHead :public CellEntity
{
	int xcoord = 10;
	int ycoord = 10;

	void HeadPosition()
	{
		EntityMap[xcoord][ycoord].DisplayChar = '@';
		EntityMap[xcoord][ycoord].DecayTimer = SnakeLength;
	};

	void HeadMove()
	{
		switch (DirMov)
		{
		case Up: MoveUp(); break;
		case Down: MoveDown(); break;
		case Left: MoveLeft(); break;
		case Right: MoveRight(); break;
		}
	};

	//following functions check to make sure it doesnt travel out of bounds & collision detection with it's body


	void MoveUp()
	{
		ycoord++;
		if (ycoord > 20 || ycoord < 0  || EntityMap[xcoord][ycoord].DecayTimer != 0) { GameOver = true; }
	}
	void MoveDown()
	{
		ycoord--;
		if (ycoord < 0 || ycoord > 20 || EntityMap[xcoord][ycoord].DecayTimer != 0) { GameOver = true; }
	}
	void MoveLeft()
	{
		xcoord--;
		if (xcoord < 0 || xcoord > 20 || EntityMap[xcoord][ycoord].DecayTimer != 0) { GameOver = true; }
	}
	void MoveRight()
	{
		xcoord++;
		if (xcoord > 20 || xcoord < 0 || EntityMap[xcoord][ycoord].DecayTimer != 0) { GameOver = true; }

	}



};

class Food
{

	std::random_device rd; // obtain a random number from hardware
	std::mt19937 gen(rd()); // seed the generator
	std::uniform_int_distribution<> distr(25, 63); // define the range



};

/*
class GameMap
{
	struct GamePlane
	{
		char x = '*';
		int PersistenceDuration = 0; //int countdown to delete the tail of the snake once the correct number of ticks/movement has passed
	};

	GamePlane GamePlaneCartesian[MapHeight][MapWidth]; //creates a baby text based "frame" buffer

	void PrintGame(const char message, int NewLnChk) //add colour changes etc later. too much mucking around not enough inputting game logic.
	{
		//HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		//SetConsoleTextAttribute(hConsole, 128);
		if (NewLnChk == 20)
		{
			std::cout << message << std::endl;
			//SetConsoleTextAttribute(hConsole, 7);
		}
		else
		{
			std::cout << message;
			//SetConsoleTextAttribute(hConsole, 7);
		}
	}

	void PrintMap() 
	{
		for (int i = MapHeight; i > 0; i--)
		{
			for (int j = 0; j < (MapWidth - 1); j++)
			{
					PrintGame(GamePlaneCartesian[i][j].x, j);
			};
		};
	};
};

*/

class SNAKE
{
private:
	enum KeyNames { UP_KEY = 72, DOWN_KEY = 80, LEFT_KEY = 75, RIGHT_KEY = 77, w_key = 119, a_key = 97, d_key = 100, s_key = 115 };
	KeyNames key;

public:

	int MoveKey = UP_KEY;

	void MoveKeyInput() //MUST BE CALLED IN A LOOP otherwise it will only take a singular valid input.
	{
		MoveKey = _getch();
		if (MoveKey == 0 || MoveKey == 224) // Check for extended key indicator
		{
			int key2 = _getch(); // Get the actual key code
			MoveKey = key2;

			switch (MoveKey) //if it's arrow keys, set DirMov to corresponding correct action
			{
			case UP_KEY: DirMov = Up; break;
			case DOWN_KEY: DirMov = Down; break; 
			case LEFT_KEY: DirMov = Left; break;
			case RIGHT_KEY: DirMov = Right; break;
			default: break;
			};
		}
		else {
			switch (MoveKey) //if it's wasd, set DirMov to corresponding correct action, 
			{
			case w_key: DirMov = Up; break;
			case a_key: DirMov = Left; break;
			case d_key: DirMov = Right; break;
			case s_key: DirMov = Down; break;
			default: break;
			}
		};

	};
/*
	void SnakePosition()
	{
		for (int i = 0; i < 10; i++) //this is height, aka y axis
		{
			for (int j = 0; j < 10; j++) //this is width, aka x axis
			{
				//insert stuff to do on row
				//if j = 0 & i > 0 or j = size limit m_GamePlaneCartesian[i][j].x = '|';
			};
			//insert stuff to do on completion of row.
		};
	} */
};
