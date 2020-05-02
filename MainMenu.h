#pragma once
#include "ProductListManager.h"
class MainMenu
{
	friend int main();
	friend class SprzedazMenu;
public:
	MainMenu();
	~MainMenu();
	void menuChooser(ProductListManager&);
};

