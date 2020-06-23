#include "Bill.h"
#include "TakeTime.h"
#include "TaxesCounter.h"
#include <string>
#include <iomanip>
#include "ProductListManager.h"
#include "DailyRaport.h"
#include "vatTax.h"

Bill::Bill(int billNumber)
{
	TakeTime timeOfBill;
    numberOfBill = billNumber;
	this->dateOfBill = timeOfBill.hourMinutes;
    
}

Bill::Bill()
{
	TakeTime timeOfBill;
	numberOfBill = 0;
	this->dateOfBill = timeOfBill.hourMinutes;
}

Bill::~Bill()
{
	
}

void Bill::addProductToBill(int ID, int numberOfThings)
{
	Product newRecordOnBill;
	ProductListManager productList;
	newRecordOnBill.price = productList.listOfProduct.at(ID - 1).price;
	newRecordOnBill.productID = productList.listOfProduct.at(ID - 1).productID;
	newRecordOnBill.PTU = productList.listOfProduct.at(ID - 1).PTU;
	newRecordOnBill.productName = productList.listOfProduct.at(ID - 1).productName;
	for (int j = 0; j < numberOfThings; j++)
		listOfProductBuyByConsumer.push_back(newRecordOnBill);
}


std::string Bill::displayRekordOfBill()
{
	double toPay = 0;
	std::string textOfRecord = "Bill Number: ";
	textOfRecord += std::to_string(numberOfBill);
	textOfRecord += "\n";
	textOfRecord+="ID   Price   PTU    Name \n";
	for (auto element : listOfProductBuyByConsumer)
	{
		textOfRecord += element.display();
		toPay += element.price;
	}
	textOfRecord += "To Pay :";
	std::string toPaytext= std::to_string(toPay);
	int lenghtOfString=0;
	while (toPaytext[lenghtOfString] != '.')
		lenghtOfString++;
	textOfRecord += toPaytext.substr(0,lenghtOfString+3);
	return textOfRecord;
}



void Bill::taxesCounter() 
{
	TaxesCounter *tax = new VatTax;
	vat =  tax->Tax(listOfProductBuyByConsumer);

}

void Bill::printBillForCustomer()
{
	taxesCounter();
	double toPay = 0;
	TakeTime timeOfBill;
	std::string fileName;
	fileName = std::to_string(numberOfBill);
	fileName += ".txt";
	std::ofstream bill;
	bill.open(fileName.c_str(), std::ios::out | std::ios::out);
	bill << "Shop SP. Z.O.O\nUL.JanII 324\n02-273 Warsaw\n";
	bill << "\n" << "Bill Number: " << numberOfBill << "\n" << "Date of Bill: " << fileName << "\n" << "Produts List:\n";
	for (auto element : listOfProductBuyByConsumer)
	{
		bill << "     " << element.productID << " " << element.productName << " " << element.PTU << " " << element.price << " " << "\n";
		toPay += element.price;
	}
	bill << "To Pay: " << toPay<<"\n";
	bill << "Taxes: " <<std::fixed << std::setprecision(2)<<vat;
	bill.close();
}
