#pragma once
#include "Product.h"
class ProductListManager
{
public:
	ProductListManager();
	~ProductListManager();
	void addProductToList();
	void removeProductFromList();
	Product findProduct();
};

