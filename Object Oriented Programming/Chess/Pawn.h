#pragma once
#include "Board.h"
class Pawn :
	public Board
{
public:
	bool MovePawn(Space*, Space*);
	bool Promote(Space*);
	Pawn();
	~Pawn();
};

