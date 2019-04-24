#include "Pawn.h"
#include <string>
#include <iostream>
using namespace std;



Pawn::Pawn()
{
}
bool Pawn::MovePawn(Space* thisPawn, Space* thatSpace) {
	
	using namespace std;
	bool invalid = false;
	int pawnX = thisPawn->getX();
	int pawnY = thisPawn->getY();
	int thatX = thatSpace->getX();
	int thatY = thatSpace->getY();

	//Promote when pawn reaches the end of the board

	if (thisPawn->getColor() == WHITE)
	{

		if (pawnX == thatX && thatY == pawnY + 1 && thatSpace->getColor() == NONE)
		{
			thatSpace->setSpace(thisPawn);
			thisPawn->setEmpty();
			Promote(thatSpace);
			return true;
		}
		else
		{
			if ((pawnX + 1 == thatX || pawnX - 1 == thatX) && pawnY + 1 == thatY && thatSpace->getColor() == BLACK)
			{
				thatSpace->setSpace(thisPawn);
				thisPawn->setEmpty();
				Promote(thatSpace);
				return true;
			}
			else
			{
				return false;
			}
		}
		//white has reached row 7 i.e last ros
		
	}
	else
	{
		if (thisPawn->getColor() == BLACK)
		{
			if (pawnX == thatX && thatY == pawnY - 1 && thatSpace->getColor() == NONE)
			{
				thatSpace->setSpace(thisPawn);
				thisPawn->setEmpty();
				Promote(thatSpace);
				return true;
			}
			else
			{
				if ((pawnX + 1 == thatX || pawnX - 1 == thatX) && pawnY - 1 == thatY && thatSpace->getColor() == WHITE)
				{
					thatSpace->setSpace(thisPawn);
					thisPawn->setEmpty();
					Promote(thatSpace);
					return true;
				}
				else
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

bool Pawn::Promote(Space* thisPawn)
{
	if (thisPawn->getY() == 0 && thisPawn->getColor() == BLACK)
	{
		int q;
	peche:
		cout << "En passant" << endl;
		cout << "Select Converted Pice : " << endl;
		cout << "1. King\n";
		cout << "2. Queen\n";
		cout << "3. Rook\n";
		cout << "4. Bishop\n";
		cout << "5. Knight\n";
		cin >> q;

		switch (q)
		{
		case 1:
			thisPawn->setPieceAndColor(KING, BLACK);
			break;
		case 2:
			thisPawn->setPieceAndColor(QUEEN,BLACK);
			break;
		case 3:
			thisPawn->setPieceAndColor(ROOK, BLACK);
			break;
		case 4:
			thisPawn->setPieceAndColor(BISHOP, BLACK);
			break;
		case 5:
			thisPawn->setPieceAndColor(KNIGHT, BLACK);
			break;
		default:
			cout << "Invalid Selection" << endl;
			goto peche;
			break;
		}
		return true;
	}

	else if (thisPawn->getY() == 7 && thisPawn->getColor() == WHITE)
	{
		int q;
	peche2:
		cout << "En passant" << endl;
		cout << "Select Converted Pice : " << endl;
		cout << "1. King\n";
		cout << "2.	Queen\n";
		cout << "3. Rook\n";
		cout << "4. Bishop\n";
		cout << "5. Knight\n";
		cin >> q;

		switch (q)
		{
		case 1:
			thisPawn->setPieceAndColor(KING, WHITE);
			break;
		case 2:
			thisPawn->setPieceAndColor(QUEEN, WHITE);
			break;
		case 3:
			thisPawn->setPieceAndColor(ROOK, WHITE);
			break;
		case 4:
			thisPawn->setPieceAndColor(BISHOP, WHITE);
			break;
		case 5:
			thisPawn->setPieceAndColor(KNIGHT, WHITE);
			break;
		default:
			cout << "Invalid Selection" << endl;
			goto peche2;
			break;
		}
		return true;
	}
	
	else
	{
		return false;
	}
}


Pawn::~Pawn()
{
}
