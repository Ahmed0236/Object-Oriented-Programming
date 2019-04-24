#include "Board.h"
#include <math.h>
#include <iostream>
using namespace std;



Board::Board()
{
}

// void Board::setBoard()
//{
//	grid[0][0].setPieceAndColor(ROOK, WHITE);
//	grid[1][0].setPieceAndColor(KNIGHT, WHITE);
//	grid[2][0].setPieceAndColor(BISHOP, WHITE);
//	grid[3][0].setPieceAndColor(QUEEN, WHITE);
//	grid[4][0].setPieceAndColor(KING, WHITE);
//	grid[5][0].setPieceAndColor(BISHOP, WHITE);
//	grid[6][0].setPieceAndColor(KNIGHT, WHITE);
//	grid[7][0].setPieceAndColor(ROOK, WHITE);
//
//	grid[0][7].setPieceAndColor(ROOK, BLACK);
//	grid[1][7].setPieceAndColor(KNIGHT, BLACK);
//	grid[2][7].setPieceAndColor(BISHOP, BLACK);
//	grid[3][7].setPieceAndColor(QUEEN, BLACK);
//	grid[4][7].setPieceAndColor(KING, BLACK);
//	grid[5][7].setPieceAndColor(BISHOP, BLACK);
//	grid[6][7].setPieceAndColor(KNIGHT, BLACK);
//	grid[7][7].setPieceAndColor(ROOK, BLACK);
//
//	for (int i = 0; i < 8; i++)
//	{
//		grid[i][1].setPieceAndColor(PAWN, WHITE);
//		grid[i][6].setPieceAndColor(PAWN, BLACK);
//
//	}
//	for (int i = 2; i < 6; i++)
//	{
//		for (int j = 0; j < 8; j++)
//			grid[j][i].setPieceAndColor(EMPTY, NONE);
//
//	}
//	for (int i = 0; i < 8; i++)
//		for (int j = 0; j < 8; j++)
//		{
//			grid[i][j].setX(i);
//			grid[i][j].setY(j);
//		}
//
//} 


void Board::setSpace(Space* s, int x, int y) 
{
	grid[x][y] = *s;
}

Space* Board::getSpace(int x, int y) 
{
	return &grid[x][y];
}

void Board::PrintBoard()
{	
	cout << "White are CAPS" << endl;
	cout << "   y: 0  1  2  3  4  5  6  7 " << endl << "x:" << endl;
	for (int i = 0; i < 8; i++)
	{
		cout << " " << i << "   ";
		for (int j = 0; j < 8; j++)
		{
			Piece p = grid[i][j].getPiece();
			Color c = grid[i][j].getColor();

			switch (p)
			{
			case KING: 
				if (c == WHITE)
				{
					cout << " K ";
				}
				else
				{
					cout << " k ";
				}  
				break;


			case QUEEN: 
				if (c == WHITE) 
				{ 
					cout << " Q ";
				}
				else 
				{ 
					cout << " q "; 
				}
				break;

			case BISHOP:
				if (c == WHITE)
				{
					cout << " B ";
				}
				else
				{
					cout << " b ";
				}
				break;


			case KNIGHT:
				if (c == WHITE)
				{
					cout << " H ";
				} 
				else
				{
					cout << " h ";
				}

				break;


			case ROOK: 
				if (c == WHITE)
				{
					cout << " R ";
				}
				else 
				{
					cout << " r ";
				}
				break;


			case PAWN: 
				if (c == WHITE)
				{
					cout << " P ";
				} 
				else
				{
					cout << " p ";
				}
				break;


			case EMPTY: cout << " " << " " << " ";
				break;


			default: cout << "  ";
				break;
			}

		}
		cout << endl;
	}
}

Board::~Board()
{
}
