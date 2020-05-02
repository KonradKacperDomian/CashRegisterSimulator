#pragma once
#include "Sprzedaz.h"
#include "SprzedazMenuPrinter.h"
class SprzedazMenu
{
	friend class Sprzedaz;
	SprzedazMenuPrinter menu;
	SprzedazMenu();
	~SprzedazMenu();
	void userChoice(int userChoice);
};

