#pragma once
#include "ProductListManager.h"
#include "DailyRaport.h"
class MainMenu
{
public:
	MainMenu();
	~MainMenu();
	bool menuChooser(ProductListManager&, DailyRaport&);
};

