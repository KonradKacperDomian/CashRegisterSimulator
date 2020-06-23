#pragma once
#include <iostream>
#include <limits>
template <typename T=int>
struct TakeFromUserData
{
	TakeFromUserData(T &output)
	{
		for (;;)
		{
			std::cin >> output;
			if (std::cin.fail())
			{
				std::cin.clear();
				std::cout << "Error! incorrect data" << std::endl;
				std::cout << "Enter again data" << std::endl;
				std::cin.ignore(9999, '\n'); //std::cin.ignore(std::numeric_limits<int>::max(), '\n');
			}
			else
				break;
		}
	}
};

