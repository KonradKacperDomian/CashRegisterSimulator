#include "ProductManagementMenu.h"
#include "TakeFromUserData.h"
#include "ProductListManager.h"
#include "MainMenu.h"
#include <iostream>


ProductManagementMenu::ProductManagementMenu()
{
	system("cls");
}

void ProductManagementMenu::displayMenu()
{
	std::cout << "PRODUCT MANAGEMNT MENU" << std::endl;
	std::cout << "1.Display List of Product" << std::endl;
	std::cout << "2.Add Product to list" << std::endl;
	std::cout << "3.Remove Product From list" << std::endl;
	std::cout << "4.Back to Main Menu" << std::endl;
}

void ProductManagementMenu::userChooser(ProductListManager& productMenadzer)
{
	int userChoice;
	TakeFromUserData input(userChoice);
	for (int i = 0; i < 1; i++)
	{
		switch (userChoice)
		{
		case 1:
		{
			productMenadzer.displayAllProductsFromList();
			break;
		}
		case 2:
		{
			productMenadzer.addProductToList();
			break;
		}
		case 3:
		{

			productMenadzer.removeProductFromList();
			break;
		}
		case 4:
		{
			MainMenu menu;
			menu.menuChooser(productMenadzer);
			break;
		}
		default:

			std::cout << "mozesz wybrac jedynie opcje 1,2,3,4" << std::endl;
			TakeFromUserData input(userChoice);
			--i;
			break;
		}
	}

}

