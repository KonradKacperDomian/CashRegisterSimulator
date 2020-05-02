#include "Bill.h"
#include "TakeTime.h"
#include <iostream>
#include <string>
#include "SprzedazMenuPrinter.h"
#include "ProductListManager.h"
Bill::Bill(int billNumber)
{
    numberOfBill = billNumber;
}

Bill::~Bill()
{
    TakeTime timeOfBill;
    SprzedazMenuPrinter menu;
    menu.english(1);
    this->addProductToBill();

}

void Bill::addProductToBill()
{
    Product newRecordOnBill;
    ProductListManager productList;//wyszukaj produkt
    productList.findProduct();//if produkt istnije
    listOfProductBuyByConsumer.push_back(newRecordOnBill);
}

void Bill::removeProductFromBill()
{

}

void Bill::printBill()
{

}
