#pragma once
#include <vector>
#include <string>
#include <fstream>
#include "Bill.h"


class DailyRaport
{
	double Tax;
	double makings;
	std::string fileName;
	std::ofstream dailyRaport;
	std::vector<Bill> bills;
	
public:
	DailyRaport();
	~DailyRaport();
	std::string showOneBill(int id);
	int numberOfBills();
	void addData(Bill bill);
	void removeData(int numberOfTheBill);
	bool findBill(int);
};

