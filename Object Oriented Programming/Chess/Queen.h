#pragma once
#include "Board.h"
class Queen :public Board
{
public:
	bool MoveQueen(Space*, Space*);
	Queen();
	~Queen();
};

