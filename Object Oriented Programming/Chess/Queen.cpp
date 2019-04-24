#include "Queen.h"




Queen::Queen()
{
}

bool Queen::MoveQueen(Space* myQueen, Space* thatSpace)
{
	int queenX = myQueen->getX();
	int queenY = myQueen->getY();
	int thatX = thatSpace->getX();
	int thatY = thatSpace->getY();

	int yIncrement;
	int xIncrement;

	bool invalid = false;
	if (queenX != thatX || queenY != thatY)
	{

		if (queenX == thatX)
		{
			yIncrement = (thatY - queenY) / (abs(thatY - queenY));
			for (int i = queenY + yIncrement; i != thatY; i += yIncrement)
			{

				if (grid[thatX][i].getColor() != NONE)
				{
					return false;
				}

			}
		}
		else
		{
			if (queenY == thatY)
			{

				xIncrement = (thatX - queenX) / (abs(thatX - queenX));
				for (int i = queenX + xIncrement; i != thatX; i += xIncrement)
				{
					if (grid[i][thatY].getColor() != NONE)
					{
						return false;
					}
				}
			}
			else
			{
				if (abs(queenX - thatX) == abs(queenY - thatY))
				{
					xIncrement = (thatX - queenX) / (abs(thatX - queenX));
					yIncrement = (thatY - queenY) / (abs(thatY - queenY));

					for (int i = 1; i < abs(queenX - thatX); i++)
					{

						if (grid[queenX + xIncrement * i][queenY + yIncrement * i].getColor() != NONE)
						{
							return false;
						}

					}
				}
				else
				{
					return false;
				}

			}
		}

	} 

	if (invalid == false)
	{
		thatSpace->setSpace(myQueen);
		myQueen->setEmpty();
		return true;
	}
	else
	{
		return false;
	}
}
Queen::~Queen()
{
}
