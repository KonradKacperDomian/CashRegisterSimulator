#pragma once
#include <vector>
#include <string>
#include <fstream>
#include "Bill.h"


class DailyRaport
{
	std::string NameOfDocument;
	double Tax;
	double makings;
	std::string fileName;
	std::ofstream dailyRaport;
	std::vector<Bill> bills;

public:
	DailyRaport();
	~DailyRaport();
	void addData(Bill bill);
	void removeData();
};

