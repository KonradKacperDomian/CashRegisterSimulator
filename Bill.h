#pragma once
#include <string>
#include <vector>
#include "Product.h"
#include <string>
class Bill
{
	friend class DailyRaport;
protected:
	int numberOfBill;
	double vat;
	std::string dateOfBill;
public:
	Bill(int);
	std::vector<Product>listOfProductBuyByConsumer;
	~Bill();
	void addProductToBill();
	void removeProductFromBill();
	void printBill();
};

