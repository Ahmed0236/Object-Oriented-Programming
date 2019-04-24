#pragma once
#include "Pawn.h"
#include "King.h"
#include "Queen.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "Board.h"

class GamePlay : public Pawn, King, Queen, Rook, Bishop, Knight 
{
public:
	bool makeMove(int x1, int y1, int x2, int y2);
	bool doMove();
	bool playGame();
	void setBoard();
	bool Check();
	GamePlay();
	~GamePlay();
};

