#pragma once
#include <string>
struct Product
{
	int productID;
	double price;
	char PTU; //Stawka Vat A,B,C,D,E poszczeegolnie 23%, 8%, 5%, 0%, zwolniony
	std::string productName;
	void display(bool displayLegend);
};

