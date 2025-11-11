#include "pcatMainFunctions.h"
#include "coolaerotoolsmasterheader.h"
#include <iostream>
//Note: the main Atmosphere Maker Tool Function is located in pcatMainFunctions.h

int getTypeOfGame()
{
	int typeOfGame{};
	bool shouldLeaveMenu(false);
	std::cout << "Let's start with the basics. What type of game are you making?\n";
	std::cout << "1 - A game about flying aircraft.\n 2 - A game where you can fly aircraft.\n 3 - A simulator which is not a flight sim. ";

	while (!shouldLeaveMenu)
	{
		int menu{};
		getErrorCheckedInput(menu);
		switch (menu)
		{

		case 1:
		{
			typeOfGame = 1;
			shouldLeaveMenu = 1;
			break;
		}
		case 2:
		{
			typeOfGame = 2;
			shouldLeaveMenu = 1;
			break;
		}

		case 3:
		{
			typeOfGame = 3;
			shouldLeaveMenu = 1;
			break;
		}

		default:
		{
			shouldLeaveMenu = 0;
			std::cout << "Invalid input. Reenter selection." << '\n';
		}

		}
		return typeOfGame;
	}
}

/*
int getLevelSize ()
{


return levelSize;
}





*/