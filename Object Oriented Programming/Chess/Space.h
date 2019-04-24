#pragma once


enum Piece { KING, QUEEN, BISHOP, KNIGHT, ROOK, PAWN, EMPTY };
enum Color { WHITE, BLACK, NONE };


class Space
{
public:
	Piece piece;
	Color color;
	int x, y;
public:
	void setSpace(Space*);
	void setEmpty();
	void setPieceAndColor(Piece, Color);
	Piece getPiece();
	Color getColor();
	void setX(int);
	void setY(int);
	int getX();
	int getY(); 
	Space();
	~Space();
};

