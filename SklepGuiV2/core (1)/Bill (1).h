#pragma once
#include <string>
#include <vector>
#include "Product.h"
#include "ProductListManager.h"
#include <string>


#include <string>
class Bill
{
	friend class DailyRaport;
	friend class TaxesCounter;
	int numberOfBill;
	double vat;
	std::string dateOfBill;
public:
	Bill(int);
	std::vector<Product>listOfProductBuyByConsumer;
	~Bill();
	void addProductToBill(int id, int numberOfThings);
	std::string displayRekordOfBill();
	Bill();
	void taxesCounter();
	void printBillForCustomer();
};

