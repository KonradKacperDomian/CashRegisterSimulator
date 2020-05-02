#pragma once
#include "Product.h"
#include <vector>
class ProductListManager
{
	std::vector<Product>listOfProduct;
public:
	ProductListManager();
	~ProductListManager();
	void addProductToList();
	void removeProductFromList();
	void findProduct();
	void displayAllProductsFromList();
};

