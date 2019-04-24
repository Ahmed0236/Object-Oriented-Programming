#pragma once
#include "Board.h"
class Knight :
	public Board
{
public:
	bool MoveKnight(Space*, Space*);
	Knight();
	~Knight();
};

