#pragma once
#include "Board.h"
class Bishop :
	public Board
{
public:
	bool MoveBishop(Space*, Space*);
	Bishop();
	~Bishop();
};

