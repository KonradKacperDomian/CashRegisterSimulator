#include "Bill.h"
#include "TakeTime.h"
#include <iostream>
#include <string>
#include "ProductListManager.h"
#include "DailyRaport.h"
#include "TakeFromUserData.h"
#include "Display.h"

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

void Bill::addProductToBill()
{
	//Display display;
	system("cls");
    Product newRecordOnBill;
	//display.statementEnterProductID;
	std::cout << "enter the product id:  ";
	int ID;
	TakeFromUserData <int> IDs(ID);
    ProductListManager productList;
	if (productList.findProduct(ID))
	{
		//display.statementHowMuch;
		std::cout << "How much?" << std::endl;
		int howMuch;
		TakeFromUserData numOfProduct(howMuch);
		//display.verification();
		std::cout << "Add Product to bill? (y/n)" << std::endl;
		char yesOrNo;
		TakeFromUserData Trash(yesOrNo);
		int i;
		for (i=0; i < 1; i++)
		switch (yesOrNo)
		{
		case 'y':
		{
			newRecordOnBill.price = productList.listOfProduct.at(ID-1).price;
			newRecordOnBill.productID = productList.listOfProduct.at(ID - 1).productID;
			newRecordOnBill.PTU = productList.listOfProduct.at(ID - 1).PTU;
			newRecordOnBill.productName = productList.listOfProduct.at(ID - 1).productName;
			for(int j=0;j<howMuch;j++)
				listOfProductBuyByConsumer.push_back(newRecordOnBill);
			break;
		}
		case 'n':
		{
			break;
		}
		default:
			//display.displayOnlyYesNo();
			std::cout << "only (y/n): " << std::endl;
			TakeFromUserData userChoice(yesOrNo);
			--i;
			break;
		}
	}
	std::cout << "Your bill: " << std::endl;
	this->printBill();
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



void Bill::removeProductFromBill()
{

}

void Bill::printBill()
{
	system("cls");
    std::cout << "ID   Price   PTU    Name" << std::endl;
    for (auto element : listOfProductBuyByConsumer)
        element.display(0);
}

void Bill::displayBillMenu()
{
    std::cout << "2.Print the bill" << std::endl;
    std::cout << "3.add new record/Procuct to cart" << std::endl;
}

void Bill::billMenuChooser()
{
	int userChoice;
	TakeFromUserData<int> input(userChoice);
	for (int i = 0; i < 1; i++)
	{
		switch (userChoice)
		{
		case 2:
		{
			
			break;
		}
		case 3:
		{
			this->addProductToBill();
			this->displayBillMenu();
			this->billMenuChooser();
			break;
		}
		default:

			std::cout << "mozesz wybrac jedynie opcje 2,3" << std::endl;
			TakeFromUserData <int> input(userChoice);
			--i;
			break;
		}
	}
}

void Bill::taxesCounter()
{
	for (auto elements : listOfProductBuyByConsumer)
		switch (elements.PTU)
		{
		case 'A':
		{
			vat = vat + (elements.price * 0.23);
			break;
		}
		case 'B':
		{
			vat += elements.price * 0.08;
			break;
		}
		case 'C':
		{
			vat += elements.price * 0.05;
			break;
		}
		case 'D':
		{
			vat += 0;
			break;
		}
		case 'E':
		{
			vat += 0;
			break;
		}
		default:
		{
			std::cout << "Error! Incorrectly given tax!" << std::endl;
			elements.display(1);
			break;
		}

		}
}

void Bill::printBillForCustomer()
{
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
	bill << "Taxes: " << vat;
	bill.close();
}
