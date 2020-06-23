#pragma once
#include "Product.h"
#include "Bill.h"
#include <vector>
class ProductListManager
{
	friend class Bill;
	std::vector<Product>listOfProduct;
public:
	ProductListManager();
	~ProductListManager();
	bool addProductToList(double price, char PTU, std::string productName);
	void removeProductFromList(int ID);
	bool findProduct(int);
	std::string displayOneProduct(int ID);
	bool corectPTU(char);
	int numberOfProducts();
};

