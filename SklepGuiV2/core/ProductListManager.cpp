#include "ProductListManager.h"
#include "Product.h"
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <iomanip> 


ProductListManager::ProductListManager()
{
    std::string text;
    std::ifstream productsListFile("productsList.txt", std::ios::in);
    if (productsListFile.is_open())
    {
        int ID = 1;
        while (getline(productsListFile, text))
        {
            Product readProduct;
            readProduct.productID = ID++;
            std::istringstream iss(text);
            std::vector<std::string> tokens;
            copy(std::istream_iterator<std::string>(iss), std::istream_iterator<std::string>(), back_inserter(tokens));
            if (std::stod(tokens[0])!=0)
            {
                readProduct.price = std::stod(tokens[0]);
                readProduct.PTU = tokens[1][0];
                readProduct.productName = tokens[2];
                listOfProduct.push_back(readProduct);
            }
           
        }
    }
    else
    {
        
        exit(0);
    }   
    productsListFile.close();
}

ProductListManager::~ProductListManager()
{
    std::string fileName;
    fileName = "productsList.txt";
    std::ofstream myTextFile;
    myTextFile.open(fileName.c_str(), std::ios::out | std::ios::out);
    for (auto element : listOfProduct)
    {
        myTextFile << element.price << " " << element.PTU << " " << element.productName << "\n";
  }
    
    myTextFile.close();
}


bool ProductListManager::addProductToList(double price, char PTU, std::string productName)
{
    Product newProduct;
    newProduct.price = price;
    if (!corectPTU(PTU))
        return false;                         
    newProduct.PTU = PTU;
    newProduct.productName = productName;
    newProduct.productID = listOfProduct.size() + 1;
    listOfProduct.push_back(newProduct);
    return true;
}


void ProductListManager::removeProductFromList(int ID)
{
    listOfProduct[ID - 1].productID = NULL;
    listOfProduct[ID - 1].price = NULL;
    listOfProduct[ID - 1].PTU = NULL;
    listOfProduct[ID - 1].productName = " ";
}



bool ProductListManager::findProduct(int ID)
{
    if (ID > listOfProduct.size() || ID - 1 < 0)
    {
        return false;
    }
    else
    {
        if (listOfProduct[ID - 1].productID == 0)
            return false;

        return true;
    }
}

std::string ProductListManager::displayOneProduct(int ID)
{
    return listOfProduct.at(ID).display();
}

bool ProductListManager::corectPTU(char corectPTU)
{
    if (corectPTU == 'A' || corectPTU == 'B' || corectPTU == 'C' || corectPTU == 'D' || corectPTU == 'E')
        return true;
    else
        return false;
}

int ProductListManager::numberOfProducts()
{
    return listOfProduct.size();
}
