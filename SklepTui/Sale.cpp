#include "Sale.h"
#include "Bill.h"
#include "TakeFromUserData.h"
#include <iostream>



void Sale::displayMenu()
{
	system("cls");
	std::cout << "1.Create New Bill" << std::endl;
	std::cout << "." << std::endl << "." << std::endl << "." << std::endl;
	std::cout << "5.Back to MainMenu" << std::endl;

}

void Sale::menuChooser(ProductListManager& vectorOfProducts, DailyRaport& dailyRaport)
{
	static int j = 1;
	int userChoice;
	TakeFromUserData input(userChoice);
	for (int i = 0; i < 1; i++)
	{
		switch (userChoice)
		{
		case 1:
		{
			system("cls");
			Bill newBill(j++);
				newBill.displayBillMenu();
				newBill.billMenuChooser();
				newBill.taxesCounter();
				dailyRaport.addData(newBill);
				newBill.printBillForCustomer();
			break;
		}
		case 5:
		{
			break;
		}
		default:

			std::cout << "mozesz wybrac jedynie opcje 1,5" << std::endl;
			TakeFromUserData input(userChoice);
			--i;
			break;
		}
	}
}

void Sale::replacement(DailyRaport& dailyRaport)
{
	dailyRaport.removeData();
}


