#include "GamePlay.h"
#include "Board.h"
#include <math.h>
#include <iostream>
#include <string>
using namespace std;


GamePlay::GamePlay()
{
}

bool GamePlay::makeMove(int x1, int y1, int x2, int y2) {

	using namespace std;
	if (x1 < 0 || x1>7 || y1 < 0 || y1>7 || x2 < 0 || x2>7 || y2 < 0 || y2>8)
	{
		return false;
	}
	Space* From = Board::getSpace(x1, y1);
	Space* To = Board::getSpace(x2, y2);

	if (From->getColor() == To->getColor() && To->getColor() != NONE)
	{
		cout << "Invalid move cannot move on your own piece" << endl;
		return false;
	}



	switch (From->getPiece())
	{
	case KING: 
		return moveKing(From, To);
		break;
	case QUEEN:
		return MoveQueen(From, To);
		break;
	case BISHOP: 
		return MoveBishop(From, To);
		break;
	case KNIGHT: 
		return MoveKnight(From, To);
		break;
	case ROOK: 
		return MoveRook(From, To);
		break;
	case PAWN: 
		return MovePawn(From, To);
		break;
	case EMPTY:  cout << "There is no piece present there !!" << std::endl;  return false;
		break;
	default: 
		cout << "bogawoga" << endl;
		break;
	}

	Check();
	
	return false;
} 

bool GamePlay::doMove() {
	
	int x1, x2, y1, y2;
	bool legal = false;

	bool KingAlive = false;
	
	while (!legal)
	{	
		//specify whose turn 
		if (Board::turn == WHITE)
		{
			cout << "White's turn" << endl;
		}
		else if (Board::turn == BLACK)
		{
			cout << "Black's turn" << endl;
		} 
		
		//ask for coordinates
		cout << "Enter your move " << endl;
		cout << "Current X-Corrdinate : ";
		cin >> x1;

		cout << "Current Y-Corrdinate : ";
		cin >> y1;
		cout << endl;

		cout << "New X-Corrdinate : ";
		cin >> x2;

		cout << "New Y-Corrdinate : ";
		cin >> y2;
		
		if (Board::getSpace(x2, y2)->getPiece() == KING && Board::getSpace(x2, y2)->getColor() != Board::turn)
		{
			cout << "CheckMate!!!" << endl;
			if (Board::getSpace(x1, y1)->getColor() == WHITE)
			{
				cout << "WHITE WINS" << endl;
				return false;
			}
			else
			{
				cout << "BLACK WINS" << endl;
				return false;
			}
		}

		//if my piece and my color
		if (Board::getSpace(x1, y1)->getColor() == Board::turn)
		{	
			//check if move is not legal stay in while loop
			if (makeMove(x1, y1, x2, y2) == false)
			{
				cout << "Invalid move, try again." << endl;
			}
			//if move is legal break away from while loop
			else
			{	
				legal = true;
			}
	
		}

		
		//if it is not my piece
		else if(Board::getSpace(x1, y1)->getColor() != Board::turn)
		{
			cout << "That's not your piece!!!" << endl;
		}
			
	}

	

	//wining condition 
	
	

	//for changing turn
	if (Board::turn == BLACK)
	{
		Board::turn = WHITE;
	}
		
	else
	{
		Board::turn = BLACK;
	}
	return true;
} 

bool GamePlay::Check()
{	
	
	//1. find my king
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{	
			//my king and my turn
			if (Board::getSpace(i, j)->getPiece() == KING && Board::getSpace(i,j)->getColor() == Board::turn)
			{	
				cout << "found king!" << endl;
				
				//2. find enemies if any nearby my king
				for (int k = 1; k < 7; k++)
				{
					if (Board::getSpace(i + k, j)->getColor() != Board::turn && Board::getSpace(i+k,j)->getPiece()!= EMPTY)
					{
						if (makeMove(i + k, j, i, j) == true)
						{
							cout << "your King is in Check!" << endl;
							return true;
						}
						
					}
					else if (Board::getSpace(i - k, j)->getColor() != Board::turn && Board::getSpace(i - k, j)->getPiece() != EMPTY)
					{
						if (makeMove(i - k, j, i, j) == true)
						{
							cout << "your King is in Check!" << endl;
							return true;
						}
					}
					else if (Board::getSpace(i ,k +j)->getColor() != Board::turn && Board::getSpace(i, k + j)->getPiece() != EMPTY)
					{
						if (makeMove(i,k+j, i, j) == true)
						{
							cout << "your King is in Check!" << endl;
							return true;
						}
					}
					else if (Board::getSpace(i, j-k)->getColor() != Board::turn && Board::getSpace(i, j - k)->getPiece() != EMPTY)
					{
						if (makeMove(i, j-k, i, j) == true)
						{
							cout << "your King is in Check!" << endl;
							return true;
						}
					}
					else if (Board::getSpace(i+k, k + j)->getColor() != Board::turn && Board::getSpace(i + k, k + j)->getPiece() != EMPTY )
					{
						if (makeMove(i+k, k + j, i, j) == true)
						{
							cout << "your King is in Check!" << endl;
							return true;
						}
					}
					else if (Board::getSpace(i - k, j-k)->getColor() != Board::turn && Board::getSpace(i - k, j - k)->getPiece() != EMPTY)
					{
						if (makeMove(i - k, j-k, i, j) == true)
						{
							cout << "your King is in Check!" << endl;
							return true;
						}
					}
					else if (Board::getSpace(i + k, j-k)->getColor() != Board::turn && Board::getSpace(i + k, j - k)->getPiece() !=EMPTY )
					{
						if (makeMove(i + k, j-k, i, j) == true)
						{
							cout << "your King is in Check!" << endl;
							return true;
						}
					}
					else if (Board::getSpace(i - k, k + j)->getColor() != Board::turn && Board::getSpace(i - k, k + j)->getPiece() != EMPTY )
					{
						if (makeMove(i - k, k + j, i, j) == true)
						{
							cout << "your King is in Check!" << endl;
							return true;
						}
					}
					return false;
				}
				return false;
			}
		}
	}
}

bool GamePlay::playGame()
{
	system("cls");
	Board::PrintBoard();
	return GamePlay::doMove();
}

 void GamePlay::setBoard()
{
	Board::grid[0][0].setPieceAndColor(ROOK, WHITE);
	Board::grid[0][1].setPieceAndColor(KNIGHT, WHITE);
	Board::grid[0][2].setPieceAndColor(BISHOP, WHITE);
	Board::grid[0][3].setPieceAndColor(QUEEN, WHITE);
	Board::grid[0][4].setPieceAndColor(KING, WHITE);
	Board::grid[0][5].setPieceAndColor(BISHOP, WHITE);
	Board::grid[0][6].setPieceAndColor(KNIGHT, WHITE);
	Board::grid[0][7].setPieceAndColor(ROOK, WHITE);

	Board::grid[7][0].setPieceAndColor(ROOK, BLACK);
	Board::grid[7][1].setPieceAndColor(KNIGHT, BLACK);
	Board::grid[7][2].setPieceAndColor(BISHOP, BLACK);
	Board::grid[7][3].setPieceAndColor(QUEEN, BLACK);
	Board::grid[7][4].setPieceAndColor(KING, BLACK);
	Board::grid[7][5].setPieceAndColor(BISHOP, BLACK);
	Board::grid[7][6].setPieceAndColor(KNIGHT, BLACK);
	Board::grid[7][7].setPieceAndColor(ROOK, BLACK);

	for (int i = 0; i < 8; i++)
	{
		Board::grid[1][i].setPieceAndColor(PAWN, WHITE);
		Board::grid[6][i].setPieceAndColor(PAWN, BLACK);

	}
	for (int i = 2; i < 6; i++)
	{
		for (int j = 0; j < 8; j++)
			Board::grid[i][j].setPieceAndColor(EMPTY, NONE);

	}
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
		{
			Board::grid[i][j].setX(j);
			Board::grid[i][j].setY(i);
		}

} 

GamePlay::~GamePlay()
{
}
