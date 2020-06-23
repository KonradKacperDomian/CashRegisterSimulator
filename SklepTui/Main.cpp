#include "MainMenu.h"
#include <iostream>
#include <Windows.h>
#include "ProductListManager.h"
#include "TakeFromUserData.h"
#include "DailyRaport.h"
int main()
{
	ProductListManager VectorOfProducts;//wczytywanie danych z pliku
	DailyRaport newDailyRaport;			//utworzenie raportu dnia
	MainMenu menu; //utworz menu //bedzie menu(&doListyProduktow, &doRaportuDziennego)
	menu.menuChooser(VectorOfProducts);

	
	return 0;
}