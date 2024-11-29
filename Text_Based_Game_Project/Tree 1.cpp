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

	while (isRunning)
	{
		int choice = 0;
		cout << "1 Head to Prison Yard" << '\n';
		cout << "2 Head to canteen " << '\n';
		cin >> choice;

		switch (choice) {

		case 1:
			ClearScreen(); // clear screen
			PrisonYardOption();
			break;

		case 2:
			ClearScreen(); // clear screen
			CanteenOption();
			break;




		}
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

	cout << "oh no that prisoner has a sharp object";
	int choice;
	while (isRunning) {
		cout << player.getHealth();
		cout << "1 Fight " << '\n';
		cin >> choice;

		switch (choice) {

		case 1:
			ClearScreen(); // clear screen
			chances.fight();
			break;

		}
		isRunning = false;


	}

}

void ManageWindow::PrisonYardOption() {
	bool isRunning = true;
	int choice=0;

	cout << "This place is very dangerous. I ought to be careful.\n";

	while (isRunning) {
		cout << "1 Examine yard\n";
		cout << "2 Leave Prison yard\n";
		cout << "Enter your choice: ";



		switch (choice) {
		case 1:
			ClearScreen(); // Clear screen
			ExamineYard(); // Examine yard
			break;

		case 2:
			ClearScreen(); // Clear screen
			Leave_Cell_Option(); // Transition to cell options
			isRunning = false; // Exit loop after leaving yard
			break;

		default:
			cout << "Invalid choice. Please try again.\n";
			break;
		}
	}
}





void::ManageWindow::CanteenOption()
{


	bool isRunning = true;
	cout << "Ah the canteen home of the slop, top and flop that we digest" << '\n';
	int choice = 0;

	while (isRunning)
	{
		cout << "1 Examine canteen " << '\n';
		cout << "2 Leave canteen" << '\n';
		cin >> choice;

		switch (choice) {

		case 1:
			ClearScreen(); // clear screen
			ExamineCanteen();
			break;

		case 2:
			ClearScreen(); // clear screen
			LeaveCanteen();
			PrisonerAmbush();
			break;

		case 3:
			break;

		default:
			cout << "something";




		}
		isRunning = false;

	}
}

