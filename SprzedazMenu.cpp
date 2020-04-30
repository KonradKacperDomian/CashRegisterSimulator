#include "SprzedazMenu.h"
#include "TakeFromUserData.h"
#include "SprzedazMenuPrinter.h"

SprzedazMenu::~SprzedazMenu()
{
	system("cls");
}

SprzedazMenu::SprzedazMenu()
{
	SprzedazMenuPrinter menu;
	int userChoice;
	menu.english(0);
	TakeFromUserData input(userChoice);
}
