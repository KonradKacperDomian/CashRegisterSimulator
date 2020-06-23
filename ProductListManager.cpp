#include "ProductListManager.h"
#include "Product.h"
#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <iomanip> 
#include "TakeFromUserData.h"
#include "MainMenu.h"



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
            readProduct.price=std::stod(tokens[0]);
            readProduct.PTU = tokens[1][0];
            readProduct.productName = tokens[2];
            //std::cout << readProduct.productID << "." << readProduct.price << "." << readProduct.PTU << readProduct.productName << std::endl;
            listOfProduct.push_back(readProduct);
        }
    }
    else
    {
        std::cout << "Error cannot read a Products File" << std::endl;
        exit(0);
    }   
    productsListFile.close();
}

ProductListManager::~ProductListManager()
{
    std::string fileName;
    fileName = "productsList.txt";
    //std::cout << fileName;
    std::ofstream myTextFile;
    myTextFile.open(fileName.c_str(), std::ios::out | std::ios::out);
    for (auto element : listOfProduct)
    {
        myTextFile << element.price << " " << element.PTU << " " << element.productName << "\n";
  }
    
    myTextFile.close();
}

void ProductListManager::addProductToList()
{
    system("cls");
    char PTU;
    Product newProduct;
    std::cout << "Type Price of the Product:  ";
    TakeFromUserData priceOfTheProduct(newProduct.price);\
        for (;;)
        {
            std::cout << "Type PTU of the Productu:  ";
            TakeFromUserData PTUOfTheProduct(PTU);
            if (corectPTU(PTU))
                break;
            else
                std::cout << "HelpDesk! PTU Table: A-23% B-8% C-5% D-0% E-NULL\nYou can type only A,B,C,D,E " << std::endl;
        }
    newProduct.PTU = PTU;
    std::cout << "Type nameOfTheProduct:  ";
    TakeFromUserData nameOfTheProduct(newProduct.productName);
    newProduct.productID = listOfProduct.size() + 1;
    std::cout << "Add ?" << std::endl;
    newProduct.display(true);
    std::cout << "(y/n) : ";
    char yesOrNo;
    TakeFromUserData userChoice(yesOrNo);
    for (int i = 0; i < 1; i++)
    {
        switch (yesOrNo)
        {
        case 'y':
            listOfProduct.push_back(newProduct);
            break;
        case 'n':
            break;
        default:
            std::cout << "only (t/n)" << std::endl;
            TakeFromUserData userChoice(yesOrNo);
            --i;
            break;
        }
    }
}

void ProductListManager::removeProductFromList()
{
    system("cls");
    int ID;
    std::cout << "enter the product id you want to delete: ";
    TakeFromUserData<int> IDs(ID);
    std::cout << "Remove ?" << std::endl;
    listOfProduct[ID - 1].display(true);
    std::cout << "(y/n) : ";
    char yesOrNo;
    TakeFromUserData userChoice(yesOrNo);
    for (int i = 0; i < 1; i++)
    {
        switch (yesOrNo)
        {
        case 'y':
            listOfProduct[ID - 1].productID = NULL;
            listOfProduct[ID - 1].price = NULL;
            listOfProduct[ID - 1].PTU = NULL;
            listOfProduct[ID - 1].productName = " ";
            break;
        case 'n':
            break;
        default:

            std::cout << "only (t/n)" << std::endl;
            TakeFromUserData userChoice(yesOrNo);
            --i;
            break;
        }
    }
}

void ProductListManager::findProduct()
{
    system("cls");
    std::cout << "enter the product id:  ";
    int ID;
    TakeFromUserData IDs(ID);
    if (ID > listOfProduct.size()|| ID - 1 < 0)
    {
        std::cout << "product with given id does not exist" << std::endl;
    }
    else
    {
        if(listOfProduct[ID-1].productID==0)
            std::cout << "product with given id does not exist" << std::endl;
        listOfProduct[ID-1].display(true);
    }
    std::cout << "press any Key to countinue" << std::endl;
    char trash;
    TakeFromUserData Trash(trash);
}

bool ProductListManager::findProduct(int ID)
{
    system("cls");
    bool productExist;
    if (ID > listOfProduct.size() || ID - 1 < 0)
    {
        std::cout << "product with given id does not exist" << std::endl;
        productExist = false;
    }
    else
    {
        if (listOfProduct[ID - 1].productID == 0)
            std::cout << "product with given id does not exist" << std::endl;
        listOfProduct[ID - 1].display(true);
        productExist = true;
    }
    return productExist;
}

void ProductListManager::displayAllProductsFromList()
{
    system("cls");
    std::cout << "ID   Price   PTU    Name" << std::endl;
    for (auto element : listOfProduct)
        element.display(false);
    std::cout << "press any Key to countinue" << std::endl;
    char trash;
    TakeFromUserData Trash(trash);
}

bool ProductListManager::corectPTU(char corectPTU)
{
    if (corectPTU == 'A' || corectPTU == 'B' || corectPTU == 'C' || corectPTU == 'D' || corectPTU == 'E')
        return true;
    else
        return false;
}

