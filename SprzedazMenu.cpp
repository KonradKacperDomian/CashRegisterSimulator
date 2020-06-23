#include "SprzedazMenu.h"
#include "TakeFromUserData.h"
#include "SprzedazMenuPrinter.h"
#include "Bill.h"
#include "MainMenu.h"


SprzedazMenu::~SprzedazMenu()
{
	system("cls");
}

void SprzedazMenu::userChoice(int userChoice)
{
	for (int i = 0; i < 1; i++)
	{
		switch (userChoice)
		{
		case 1:
		{
			system("cls");
			Bill newBill(1);
			//std::cout << "opcja 1";
			break;
		}
		case 5:
		{
			//std::cout << "opcja 5";
			MainMenu backToMenu;
			break; 
		}
		default:

			std::cout << "mozesz wybrac jedynie opcje 1,2,3,4,5" << std::endl;
			TakeFromUserData input(userChoice);
			--i;
			break;
		}
	}
}

SprzedazMenu::SprzedazMenu()
{
	menu.english(0);
	
}
