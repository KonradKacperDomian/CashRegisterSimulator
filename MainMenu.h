#pragma once
#include "ProductListManager.h"
#include "DailyRaport.h"
class MainMenu
{
	friend int main();
	friend class SprzedazMenu;
public:
	MainMenu();
	~MainMenu();
	bool menuChooser(ProductListManager&, DailyRaport&);
};

