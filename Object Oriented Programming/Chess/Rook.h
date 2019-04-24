#pragma once
#include "Board.h"
class Rook : public Board
{
public:
	bool MoveRook(Space*, Space*);
	Rook();
	~Rook();
};

