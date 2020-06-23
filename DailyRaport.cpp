#include "DailyRaport.h"
#include <fstream>
#include <string>
#include <iostream>
#include <iomanip>
#include "TakeTime.h"
#include "TakeFromUserData.h"



DailyRaport::DailyRaport()
{
    TakeTime time;
    fileName = time.yearMonthDay;
    fileName=fileName+".txt";
    dailyRaport.open(fileName.c_str(), std::ios::out | std::ios::out);
    Tax = 0;
}

DailyRaport::~DailyRaport()
{
    TakeTime time;
    dailyRaport << "Report Day " << time.yearMonthDay<<"\n\n";
    for (auto element : bills)
    {
        dailyRaport << "\n" <<"Bill Number: " << element.numberOfBill << "\n" <<"Date of Bill: " << element.dateOfBill << "\n"<<"Produts List:\n";
        for (auto element : element.listOfProductBuyByConsumer)
        {
            dailyRaport << "     " << element.productID << " " << element.productName << " " << element.PTU << " " << element.price <<" "<< "\n";
            this->makings += element.price;
        }    
        dailyRaport <<"Taxes :" <<std::fixed << std::setprecision(2) << element.vat << "$\n";
        //if(element.vat!=0&&element.vat!=Tax)
          //  Tax = Tax + element.vat;
    }
    dailyRaport << "\n\n\nsummary: \n" << "makkings: " << this->makings<<"$\n all taxes:"<< this->Tax<<"$\n";
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
    std::cout << "enter the bill id you want to delete: ";
    TakeFromUserData <int> IDs(numberOfTheBill);
    if (findBill(numberOfTheBill))
    {
        std::cout << "Remove ?" << std::endl;
        bills[numberOfTheBill - 1].printBill();
        std::cout << "(y/n) : ";
        char yesOrNo;
        TakeFromUserData <char> userChoice(yesOrNo);
        for (int i = 0; i < 1; i++)
        {
            switch (yesOrNo)
            {
            case 'y':
            {
                bills[numberOfTheBill - 1].listOfProductBuyByConsumer.clear();
                bills[numberOfTheBill - 1].dateOfBill.clear();
                bills[numberOfTheBill - 1].numberOfBill = NULL;
                Tax -= bills[numberOfTheBill - 1].vat;
                bills[numberOfTheBill - 1].vat = NULL;
                break;
            }
            case 'n':
                break;
            default:

                std::cout << "only (t/n)" << std::endl;
                TakeFromUserData <char> userChoice(yesOrNo);
                --i;
                break;
            }
        }
    }
    else
    {
        std::cout << "Error!! The bill does not exist"<<std::endl;
        std::cout << "press any Key to countinue" << std::endl;
        char trash;
        TakeFromUserData Trash(trash);
    }
       
    
}

bool DailyRaport::findBill(int ID)
{
    if (ID - 1 < 0 || ID  > bills.size())
        return false;
    else
        return true;
}


