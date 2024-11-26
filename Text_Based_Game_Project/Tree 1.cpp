#include "ManageWin.h"
#include <iostream>
using namespace std;

void::ManageWindow::Leave_Cell_Option()
{
	bool isRunning = true;
	cout << "The Halls are empty time to move " << '\n';

	int choice;
	cout << "1 Head to Prison Yard" << '\n';
	cout << "2 Head to canteen " << '\n';
	cin >> choice;

	if (choice == 1)
	{
		PrisonYardOption();
	}
	else if (choice == 2)
	{
		CanteenOption();
	}
	else {
		isRunning = false;
	}

}

void ManageWindow::PrisonYardOption()

{
	cout << "This place is very dangerous I ought a be careful" << '\n';

}

void ManageWindow::CanteenOption()
{
	cout << "Ah the canteen home of the slop, top and flop that we digest" << '\n';

}
