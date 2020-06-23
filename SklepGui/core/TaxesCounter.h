#pragma once
#include "Product.h"
#include <vector>
class TaxesCounter
{
public:
	virtual double Tax(std::vector<Product> listOfProductBuyByConsumer) =0;
	virtual ~TaxesCounter() {};

private:

};

