#include "ManageWin.h"
#include <iostream>

using namespace std;


void ManageWindow::DisplayText()
{
	const std::string BLUE = "\033[34m";
	std::cout << BLUE << "You have been in this hellhole for too long, and the days have begun to blur together, dark, cold, and endless.\n";
	std::cout << BLUE << "The prison is a labyrinth of cement and iron, and you have memorized every inch of it.\n";
	std::cout << BLUE << "You can feel the weight of the guards eyes on you every time you walk through the halls.\n";
	std::cout << BLUE << "But you have also learned the rhythms. You know when to stay invisible, when to be quiet, when to act.\n";

	cout << '\n';

	InGameLoop();
}
