#pragma once
#include <string>
#include <vector>
#include "Product.h"
#include "ProductListManager.h"
//#include "DailyRaport.h"
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
	void addProductToBill();
	//void addProductToBill(ProductListManager&);
	void removeProductFromBill();
	void printBill();
	void displayBillMenu();
	//void billMenuChooser(DailyRaport&, ProductListManager&);
	void billMenuChooser();
	void taxesCounter();
	void printBillForCustomer();
};

