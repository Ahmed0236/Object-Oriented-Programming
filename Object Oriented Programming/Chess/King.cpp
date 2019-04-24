#include "King.h"
#include <math.h>



King::King()
{
}

bool King::moveKing(Space* thisKing, Space* thatSpace)
{	
	// can only move one space horizontally
	if (abs(thatSpace->getX() - thisKing->getX()) <= 1)
	{	
		//can move only 1 space vertically
		if (abs(thatSpace->getY() - thisKing->getY()) <= 1)
		{
			thatSpace->setSpace(thisKing);
			thisKing->setEmpty();
			return true;
		}
		return false;

	}
	return false;

}

King::~King()
{
}
