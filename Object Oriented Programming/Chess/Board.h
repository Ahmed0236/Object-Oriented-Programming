#pragma once
#include "Space.h"
#include <math.h>
class Board
{
public:
	Space grid[8][8];
	Color turn = WHITE;
public:
	Space* getSpace(int , int );
	void setSpace(Space*, int , int );
	//void setBoard();
	void PrintBoard();
	
	Board();
	~Board();
};

