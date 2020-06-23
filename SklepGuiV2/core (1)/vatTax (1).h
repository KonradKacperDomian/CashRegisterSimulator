#include "Product.h"
#include "TaxesCounter.h"
#include <vector>

struct PTU
{
	char PTUSymbol;
	double PTUProcent;
};

class VatTax : public TaxesCounter
{
	std::vector<PTU> PTUvector;
	void readPTUFromFile();
public:
	double Tax(std::vector<Product> listOfProductBuyByConsumer);
};

