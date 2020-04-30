#pragma once
#include <string>
#include <vector>
#include "Product.h"
class Bill
{
	int numberOfBill;
	double vat;
	char dateOfBill[80];
public:
	Bill(int);
	std::vector<Product>listOfProductBuyByConsumer;
	~Bill();
	

};

