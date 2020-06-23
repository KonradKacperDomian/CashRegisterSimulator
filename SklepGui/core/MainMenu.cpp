#include "MainMenu.h"
#include "MainMenuPrinter.h"
#include "Sale.h"
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

bool MainMenu::menuChooser(ProductListManager& productMenadzer, DailyRaport& dailyRaport)
{
	int userChoice;
	TakeFromUserData input(userChoice);
	for(int i=0;i<1;i++)
	{
		switch (userChoice)
		{
		case 1:
		{
			Sale sale;
			sale.displayMenu();
			sale.menuChooser(productMenadzer, dailyRaport);
			break;
		}
		case 2:
		{
			Sale sale;
			sale.replacement(dailyRaport);
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
					return true;
					break;
				case 'n':
				{
					return false;
					break;
				}	
				default:
				{
					std::cout << "only (t/n)" << std::endl;
					TakeFromUserData userChoice(yesOrNo);
					--i;
					break;
				}	
				}
			}
		}
		default:

			std::cout << "only 1,2,3,4,5" << std::endl;
			TakeFromUserData input(userChoice);
			--i;
			break;
		}
	}
	//return false;
}



