#include "ManageWin.h"
#include "Inventory.h"
#include "DayCounter.h"
#include "ChanceManager.h"
#include "Player.h"
#include <iostream>
using namespace std;

Inventory inventory; // reference to inventory class
DayCounter Dc; // reference to the day counter class
Chances chances; // reference to chances class
Player player; // reference to player class




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

void ManageWindow::ExamineYard()
{
	cout << "you find a small knife on the ground" << '\n';
	inventory.addItem("knife");
}

void ManageWindow::LeaveYard()
{
	cout << "Ah well that's me spent for the day" << '\n';
	Dc.increment();

}

void ManageWindow::ExamineCanteen()
{

	cout << "I think I'll take this spoon for the road" << '\n';
	inventory.addItem("spoon");

}

void ManageWindow::LeaveCanteen()
{
	cout << "The slop here never gets better" << '\n';




}


void ManageWindow::PrisonerAmbush()
{

	bool isRunning = true;

	int choice;
	cout << "oh no that prisoner has a sharp object";
	cout << player.getHealth();
	cout << "1 Fight " << '\n';
	cin >> choice;



	if (choice == 1)
	{
		chances.fight();
	}
	else {
		isRunning = false;
	}

}




void ManageWindow::PrisonYardOption()
{

	bool isRunning = true;
	cout << "This place is very dangerous I ought a be careful" << '\n';

	int choice;
	cout << "1 Examine yard " << '\n';
	cout << "2 Leave Prison yard" << '\n';
	cin >> choice;

	if (choice == 1)
	{
		ExamineYard();
	}
	else if (choice == 2)
	{
		LeaveYard();
	}
	else {
		isRunning = false;
	}
}

void ManageWindow::CanteenOption()
{


	bool isRunning = true;
	cout << "Ah the canteen home of the slop, top and flop that we digest" << '\n';


	int choice;
	cout << "1 Examine canteen " << '\n';
	cout << "2 Leave canteen" << '\n';
	cin >> choice;

	if (choice == 1)
	{
		void ExamineCanteen();

	}
	else if (choice == 2)
	{
		void LeaveCanteen();
		void PrisonerAmbush();
	}
	else {
		isRunning = false;
	}
}

