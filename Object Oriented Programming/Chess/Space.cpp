#include "Space.h"



Space::Space()
{
	piece = EMPTY;
	color = NONE;
}

void Space::setSpace(Space* m)
{
	color = m->getColor();
	piece = m->getPiece();
}

void Space::setEmpty()
{
	color = NONE;
	piece = EMPTY;
}

Piece Space::getPiece()
{
	return piece;
}

Color Space::getColor()
{
	return color;
}

void Space::setPieceAndColor(Piece p, Color c)
{
	piece = p;
	color = c;

}

int Space::getX()
{
	return x;
}
int Space::getY()
{
	return y;
}
void Space::setX(int a)
{
	x = a;
}
void Space::setY(int b)
{
	y = b;
}


Space::~Space()
{
}
