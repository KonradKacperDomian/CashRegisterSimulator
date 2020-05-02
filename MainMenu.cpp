#include "MainMenu.h"
#include "MainMenuPrinter.h"
#include "Sprzedaz.h"
#include "TakeFromUserData.h"
#include "ProductListManager.h"
#include "ProductManagementMenu.h"
#include <iostream>

MainMenu::MainMenu()
{
	system("cls");
	MainMenuPrinter displayMenu;
	displayMenu.english();
}

MainMenu::~MainMenu()
{
	system("cls");
}

void MainMenu::menuChooser(ProductListManager& productMenadzer)
{
	int userChoice;
	TakeFromUserData input(userChoice);
	for(int i=0;i<1;i++)
	{
		switch (userChoice)
		{
		case 1:
		{
			//sd::cout << "opcja 1";
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
			productMenadzer.findProduct();
			break;
		}
		case 4:
		{
			
			ProductManagementMenu productManagement;
			productManagement.displayMenu();
			productManagement.userChooser(productMenadzer);
			break;
		}
		case 5:
		{
			std::cout << "Exit ?" << std::endl;
			std::cout << "(y/n) : ";
			char yesOrNo;
			TakeFromUserData userChoice(yesOrNo);
			for (int i = 0; i < 1; i++)
			{
				switch (yesOrNo)
				{
				case 'y':
					break;
				case 'n':
				{
					MainMenu menu;
					menu.menuChooser(productMenadzer);
					break;
				}	
				default:
				{
					std::cout << "only (t/n)" << std::endl;
					TakeFromUserData input(userChoice);
					--i;
					break;
				}	
				}
			}
			break; //wraca do funkcji main i tym samym konczy program
		}
		default:

			std::cout << "only 1,2,3,4,5" << std::endl;
			TakeFromUserData input(userChoice);
			--i;
			break;
		}
	}
}



