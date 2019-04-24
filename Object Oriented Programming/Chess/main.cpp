#include "GamePlay.h"
#include "Board.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	GamePlay Chess;
	bool newgame = true;

	string s;
	while (newgame == true)
	{	
		Chess.setBoard();
		while (Chess.playGame() == true);
		cout << "Do you want to play again? (y for yes, anything else for no) ";
		cin >> s;
		if (s != "y")
			newgame = false;
	}
	system("pause");
}
