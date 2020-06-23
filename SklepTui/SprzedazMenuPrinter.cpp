#include "SprzedazMenuPrinter.h"
#include <iostream>
using namespace std;
void SprzedazMenuPrinter::english(int stepID)
{
	if(stepID==0||stepID==1)
	cout << "1.Create New Bill" << endl;
	if (stepID ==1)
	{
		cout << "2.Print the bill" << endl;
		cout <<"3.add new record/Procuct to cart" << endl;
		cout << "4. Enter Customer discount" << endl;
	}
	if (stepID == 2)
		cout << "enter Product Id" << endl;
	if (stepID == 3)
		cout << "enter Number Of Product"<< endl;
	if (stepID == 0)
	{
		cout << "." << endl << "." << endl << "." << endl;
		cout << "5.Back to MainMenu" << endl;
	}
	

}

void SprzedazMenuPrinter::polish(int stepID)
{
	cout << "Utworz nowy Rachunek" << endl;
	if (stepID == 1)
	{
		cout << "2.Wydrukuj Rachunek" << endl;
		cout << "3.Dodaj Produkt do Rachunku " << endl;
		cout << "4.Wpisz znizke klienta" << endl;
	}
	if (stepID == 2)
		cout << "wprowadz numer Produktu" <<endl;
	if (stepID == 3)
		cout << "wprowadz ilosc Produktu" << endl;
}
