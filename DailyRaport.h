#pragma once
#include <vector>
#include <string>
#include "Bill.h"


class DailyRaport
{
	std::string NameOfDocument;
	double Tax;
	double makings;

public:
	DailyRaport();
	~DailyRaport();
	bool addData(std::vector<Bill>); //zwraca czy poprawnie zostal dodany rachunek do raportu dziennego
};

