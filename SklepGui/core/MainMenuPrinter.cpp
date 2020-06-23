#include "MainMenuPrinter.h"
#include <iostream>

void MainMenuPrinter::polish()
{
	std::cout << "MENU" << std::endl;
	std::cout << "1.Sprzedaz" << std::endl;
	std::cout << "2.Wymiana" << std::endl;
	std::cout << "3.Sprawdz Kod Produktu" << std::endl;
	std::cout << "4.Zarzadzaj Lista Produktow" << std::endl;
	std::cout << "5.Zakoncz sprzedaz" << std::endl;
}

void MainMenuPrinter::english()
{
	std::cout << "MAIN MENU" << std::endl;
	std::cout << "1.Sale" << std::endl;
	std::cout << "2.Replacement" << std::endl;
	std::cout << "3.Chceck product id" << std::endl;
	std::cout << "4.Product list management" << std::endl;
	std::cout << "5.Exit" << std::endl;
}


