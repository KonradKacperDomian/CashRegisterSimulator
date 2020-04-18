#pragma once
#include <iostream>
struct TakeFromUserData
{
	TakeFromUserData(int &output)
	{
		std::cin >> output;
		if (std::cin.fail())
		{
			std::cout << "Blad! Bledne dane" << std::endl;

		}
	}

};

