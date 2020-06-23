#include "DailyRaport.h"
#include <fstream>
#include <string>
#include <iomanip>
#include "TakeTime.h"



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
    }
    dailyRaport << "\n\n\nsummary: \n" << "makkings: " << this->makings<<"$\n all taxes:"<< this->Tax<<"$\n";
    dailyRaport.close();
}

std::string DailyRaport::showOneBill(int id)
{
    return bills[id].displayRekordOfBill();
}



int DailyRaport::numberOfBills()
{
    return bills.size();
}

void DailyRaport::addData(Bill bill)
{
    bills.push_back(bill);
    Tax += bill.vat;
}

void DailyRaport::removeData(int numberOfTheBill)
{
    if (findBill(numberOfTheBill))
    {
        bills[numberOfTheBill - 1].listOfProductBuyByConsumer.clear();
        bills[numberOfTheBill - 1].dateOfBill.clear();
        bills[numberOfTheBill - 1].numberOfBill = NULL;
        Tax -= bills[numberOfTheBill - 1].vat;
        bills[numberOfTheBill - 1].vat = NULL;
    }
}


bool DailyRaport::findBill(int ID)
{
    if (ID - 1 < 0 || ID  > bills.size())
        return false;
    else
        return true;
}


