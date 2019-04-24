#pragma once
#include "Board.h"
class King : public Board
{
public:
	bool moveKing(Space* , Space* );
	King();
	~King();
};

