#pragma once
#include <string>
#include <vector>
#include "Product.h"
#include "ProductListManager.h"
#include <string>
//#include "ProductListManager.h"

#include <string>
class Bill
{
	friend class DailyRaport;
	int numberOfBill;
	double vat;
	std::string dateOfBill;
public:
	Bill(int);
	std::vector<Product>listOfProductBuyByConsumer;
	~Bill();
	void addProductToBill(int id, int numberOfThings);
	void addProductToBill();
	std::string displayRekordOfBill();
	Bill();
	void removeProductFromBill();
	void printBill();
	void displayBillMenu();
	void billMenuChooser();
	void taxesCounter();
	void printBillForCustomer();
};

