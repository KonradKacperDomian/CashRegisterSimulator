#include "Sprzedaz.h"
#include "SprzedazMenu.h"
#include "TakeFromUserData.h"
#include <iostream>

Sprzedaz::Sprzedaz()
{
	system("cls");
	SprzedazMenu menu;
	int userChoice;
	TakeFromUserData input(userChoice);
	menu.userChoice(userChoice);
	

}




