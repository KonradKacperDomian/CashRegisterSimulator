#include "MainMenu.h"
#include "TakeFromUserData.h"
#include <iostream>
#include <Windows.h>
int main()
{
	MainMenu menu;
	int userChoice;
	TakeFromUserData input(userChoice);
	menu.MenuswitchBox(userChoice);
	return 0;
}