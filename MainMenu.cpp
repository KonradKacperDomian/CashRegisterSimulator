#include "MainMenu.h"
#include "MainMenuPrinter.h"
#include "Sprzedaz.h"
#include "TakeFromUserData.h"
#include <iostream>

MainMenu::MainMenu()
{
	MainMenuPrinter displayMenu;
	displayMenu.english();
	int userChoice;
	TakeFromUserData input(userChoice);
	this->menuChooser(userChoice);
}

MainMenu::~MainMenu()
{
	system("cls");
}

void MainMenu::menuChooser(int userChoice)
{
	for(int i=0;i<1;i++)
	{
		switch (userChoice)
		{
		case 1:
		{
			system("cls");
			std::cout << "opcja 1";
			Sprzedaz sprzedaz; //utworz obiekt sprzedaz //bedzie sprzedaz(&doListyProduktow, &doRaportuDziennego)
			break;
		}
		case 2:
		{
			system("cls");
			std::cout << "opcja 2";
			//Wymiana wymiana;
			break;
		}
		case 3:
		{
			system("cls");
			std::cout << "opcja 3";
			//CheckId chceckid;
			break;
		}
		case 4:
		{
			system("cls");
			std::cout << "opcja 4";
			//ProductManagement productManagement;
			break;
		}
		case 5:
		{
			std::cout << "opcja 5"; 
			break; //wraca do funkcji main i tym samym konczy program
		}
		default:

			std::cout << "mozesz wybrac jedynie opcje 1,2,3,4,5" << std::endl;
			TakeFromUserData input(userChoice);
			--i;
			break;
		}
	}
}



