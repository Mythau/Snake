/* ascii codes as follows, tested on same system. _getch is platform specific to win.
w = 119			up arrow =		72
a = 97			down arrow =	80
d = 100			left arrow =	75
s = 115			right arrow =	77*/


#include <iostream>
#include <conio.h>
#include <windows.h>

int WaitPeriod = 1000;
int Gamestate = 0;
int SnakeLength = 3;
const int MapHeight = 20;
const int MapWidth = 20;

void GameSpeed()
{
	if (WaitPeriod > 300)
		WaitPeriod = (1000 - SnakeLength * 9);
};
//sets the pace of the game, via a decrease in wait time between ticks
//9ms per tick, to a floor of 300ms, from 1000ms at the games start.

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
			for (int j = 0; j < MapWidth; j++)
			{
					PrintGame(GamePlaneCartesian[i][j].x, j);
			};
		};
	};
};

class SNAKE
{
	int MoveKey = '0';
	enum Direction {Up, Down, Left, Right};
	Direction DirMov;

	void MoveKeyInput() //MUST BE CALLED IN A LOOP otherwise it will only take a singular valid input.
	{
		MoveKey = _getch();
		if (MoveKey == 0 || MoveKey == 224) // Check for extended key indicator
		{
			int key2 = _getch(); // Get the actual key code
			MoveKey = key2;

			switch (MoveKey) //if it's arrow keys, set DirMov to corresponding correct action
			{
			case 72: DirMov = Up; break;
			case 80: DirMov = Down; break; 
			case 75: DirMov = Left; break;
			case 77: DirMov = Right; break;
			default: break;
			};
		}
		else {
			switch (MoveKey) //if it's wasd, set DirMov to corresponding correct action
			{
			case 119: DirMov = Up; break;
			case 97: DirMov = Left; break;
			case 100: DirMov = Right; break;
			case 115: DirMov = Down; break;
			default: break;
			}
		};

	};

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
	}
};
