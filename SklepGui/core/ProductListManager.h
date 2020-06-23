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
	bool addProductToList(double price, char PTU, std::string productName);
	void removeProductFromList();
	void removeProductFromList(int ID);
	void findProduct();
	bool findProduct(int);
	void displayAllProductsFromList();
	std::string displayOneProduct(int ID);
	bool corectPTU(char);
	int numberOfProducts();
};

