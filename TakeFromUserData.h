#pragma once
#include <iostream>
#include <string>
struct TakeFromUserData
{
	TakeFromUserData(int &output)
	{
		for(;;)
		{
			std::cin >> output;
			if (std::cin.fail())
			{
				std::cin.clear();
				std::cout << "Blad! Bledne dane" << std::endl;
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
			else
				break;
		}
		
	}

	TakeFromUserData(std::string& output)
	{
		for (;;)
		{
			std::cin >> output;
			if (std::cin.fail())
			{
				std::cin.clear();
				std::cout << "Blad! Bledne dane" << std::endl;
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
			else
				break;
		}

	}

};

