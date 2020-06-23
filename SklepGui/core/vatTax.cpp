#include "vatTax.h"
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <iomanip> 


void VatTax::readPTUFromFile()
{
    std::string text;
    std::ifstream PTUInfoFile("PTUInfoFile.txt", std::ios::in);
    if (PTUInfoFile.is_open())
    {
        while (getline(PTUInfoFile, text))
        {
            std::istringstream iss(text);
            std::vector<std::string> tokens;
            copy(std::istream_iterator<std::string>(iss), std::istream_iterator<std::string>(), back_inserter(tokens));
               PTU a;
               a.PTUProcent = std::stoi(tokens[2]);
               a.PTUSymbol = tokens[1][0];
               PTUvector.push_back(a);
        }
    }
    else
    {
        exit(0);
    }
    PTUInfoFile.close();
}

double VatTax::Tax(std::vector<Product> listOfProductBuyByConsumer)
{
    readPTUFromFile();
    double vat = 0;
    int i = 0;
    for (auto elements : listOfProductBuyByConsumer)
    {
       
        while (elements.PTU == PTUvector.at(i).PTUSymbol)
            i++;
        vat+=((elements.price) * (PTUvector.at(i-1).PTUProcent)* 0.01);
    }
	return vat;
}
