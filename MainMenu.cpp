#include "MainMenu.h"
#include "MainMenuPrinter.h"
#include "Sprzedaz.h"
#include <iostream>

MainMenu::MainMenu()
{
	MainMenuPrinter menuInPolish;
	menuInPolish.mainMenuPrinterPolish();
}

MainMenu::~MainMenu()
{
	system("cls");

}

void MainMenu::MenuswitchBox(int &input)
{
	switch (input)
	{
	case 1:
	{
		system("cls");
		Sprzedaz sprzedaz;
		break;
	}
	case 2:
	{

		break;
	}
	case 3:
	{

		break;
	}
	case 4:
	{

		break;
	}
	case 5:
	{

		break;
	}
	default:
	{
		std::cout << "blad";
		break;
	}
	}
}

