#include "DailyRaport.h"
#include <fstream>
#include <string>
#include <iostream>
#include "TakeTime.h"
#include "TakeFromUserData.h"

DailyRaport::DailyRaport()
{
    TakeTime time;
    fileName = time.yearMonthDay;
    fileName=fileName+".txt";
    dailyRaport.open(fileName.c_str(), std::ios::out | std::ios::out);
    int x = 10;
    double f = 3.5;
}

DailyRaport::~DailyRaport()
{
    for (auto element : bills)
    {
        dailyRaport << fileName << "\n" << element.numberOfBill << "\n" << element.dateOfBill << "\n";
        for (auto element : element.listOfProductBuyByConsumer)
            dailyRaport << element.productID << ". " << element.productName << ". " << element.PTU << " ." << element.price << "\n";
        dailyRaport << element.vat << "\n";
    }
    dailyRaport.close();
}

void DailyRaport::addData(Bill bill)
{
    bills.push_back(bill);
    Tax += bill.vat;
}

void DailyRaport::removeData()
{
    system("cls");
    int numberOfTheBill;
    std::cout << "enter the product id you want to delete: ";
    TakeFromUserData<int> IDs(numberOfTheBill);
    std::cout << "Remove ?" << std::endl;
    bills[numberOfTheBill - 1].printBill();
    std::cout << "(y/n) : ";
    char yesOrNo;
    TakeFromUserData userChoice(yesOrNo);
    for (int i = 0; i < 1; i++)
    {
        switch (yesOrNo)
        {
        case 'y':
        {
            bills[numberOfTheBill - 1].dateOfBill.clear();
            bills[numberOfTheBill - 1].numberOfBill = NULL;
            Tax -= bills[numberOfTheBill = 1].vat;
            bills[numberOfTheBill - 1].vat = NULL;
            break;
        }
        case 'n':
            break;
        default:

            std::cout << "only (t/n)" << std::endl;
            TakeFromUserData input(userChoice);
            --i;
            break;
        }
    }
    
}


