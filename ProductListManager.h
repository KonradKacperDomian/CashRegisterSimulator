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
	void addProductToList();
	void removeProductFromList();
	void findProduct();
	bool findProduct(int);
	void displayAllProductsFromList();
	bool corectPTU(char);
};

