#pragma once
#include "DailyRaport.h"
#include "ProductListManager.h"
class Sale
{
public:
	void displayMenu();
	void menuChooser(ProductListManager&, DailyRaport&);
	void replacement(DailyRaport&);
};

