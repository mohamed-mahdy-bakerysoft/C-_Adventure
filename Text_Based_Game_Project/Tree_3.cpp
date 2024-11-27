#include "ManageWin.h"
#include "DayCounter.h"
#include <iostream>
#include <string>
#include <vector>
#include "Inventory.h"

using namespace std;
Inventory playerInventory;

void::ManageWindow::Leave_Cell_Option()
{
	bool isRunning = true;
	cout << "The Halls are empty time to move " << '\n';

	int choice;
	cout << "1 Head to Prison Yard" << '\n';
	cout << "2 Head to canteen " << '\n';
	cout << "3 Head to Bathroom " << '\n';
	cout << "4 Head to Secuirity Holding " << '\n';
	cin >> choice;

	if (choice == 1)
	{
		//random_enemie_chance();
		PrisonYardOption();
	}
	else if (choice == 2)
	{
		//random_enemie_chance();
		CanteenOption();
	}
	else if (choice == 3)
	{
		//random_enemie_chance();
		BathroomOption();
	}
	else if (choice == 4)
	{
		//random_enemie_chance();
		SecuirityHoldingOption();
	}
	else {
		isRunning = false;
	}

}

void ManageWindow::Stay_In_Cell_Option()
{
	bool isRunning = true;
	cout << "Yea right lets stay here " << '\n';

	int choice;
	cout << "1 File Down Bars " << '\n';
	cout << "2 Craft Rope " << '\n';
	cout << "3 Wait " << '\n';
	cout << "4 Dont Stay " << '\n';
	cin >> choice;

	if (choice == 1)
	{
		FileBars();
	}
	else if (choice == 2)
	{
		CraftRope();
	}
	else if (choice == 3)
	{
		Wait();
	}
	else if (choice == 4)
	{
		Dont_Stay();
	}
	else {
		isRunning = false;
	}

}

void ManageWindow::Wait()
{
	cout << "... " << '\n';
	increment();
}

void ManageWindow::Dont_Stay()
{
	cout << "im leaving " << '\n';
	IntroGameLoop();
}

void ManageWindow::PrisonYardOption()

{
	cout << "The yard is wide open, but you feel the watchful eyes of guards on you.\n";
	cout << "Maybe there's a way to escape from here...\n";

}

void ManageWindow::CanteenOption()
{
	cout << "You enter the canteen. The smell of food isn't great, but it’s better than nothing.\n";
	cout << "You notice a suspicious prisoner trading items in the corner.\n";

}

void ManageWindow::BathroomOption()
{
	// Random chance to find an item
	if (rand() % 100 < 50) { // 50% chance
		if (!playerInventory.hasItem("Mirror Shard")) {
			cout << "You found a mirror shard on the floor!\n";
			playerInventory.addItem("Mirror Shard");
		}
		else {
			cout << "You found nothing new here.\n";
		}
	}
	else {
		cout << "You found nothing.\n";
	}

	// Random chance to encounter an enemy
	if (rand() % 100 < 30) { // 30% chance
		Random_Enemy(); // Call the enemy encounter function
	}
}

void ManageWindow::SecuirityHoldingOption()
{
	cout << "You enter the security holding area.\n";

	// Random chance for an enemy encounter
	if (rand() % 100 < 30) { // 30% chance
		Random_Enemy();
	}
	else {
		cout << "You manage to move quietly without being spotted.\n";
	}
}

void ManageWindow::Rest_Option()
{
	cout << "You lay down on your uncomfortable prison bed and try to rest.\n";
	cout << "After some time, you feel slightly better, though still stuck here.\n";
	increment(); // Assuming this increments days


}

void ManageWindow::serveSentence()
{
	cout << "You decide to stay and serve your sentence.\n";
	cout << "After many years, your time is up, and you're finally free.\n";
	cout << "It's a bittersweet ending, but at least you survived.\n";
}

void ManageWindow::Random_Enemie()
{

}

void ManageWindow::Climb_Fence()
{
	if (playerInventory.hasItem("Rope")) {
		cout << "You tie the rope to the fence and start climbing...\n";
		cout << "You manage to get over the fence and escape! Freedom at last!\n";
		cout << "Congratulations, you’ve won!\n";
	}
	else {
		cout << "You need a rope to climb the fence. Maybe you can craft one?\n";
	}


}
void ManageWindow::FileBars()
{
	if (playerInventory.hasItem("File")) {
		cout << "You quietly start filing the bars...\n";
		cout << "After a lot of effort, the bars are loose enough to push through.\n";
	}
	else {
		cout << "You don't have a file. Better find one first.\n";
	}
}
void ManageWindow::CraftRope()
{
	if (playerInventory.hasItem("Bedsheet")) {
		cout << "You twist and knot the bedsheets into a makeshift rope.\n";
		playerInventory.addItem("Rope");
	}
	else {
		cout << "You need bedsheets to craft a rope. Check the cell or other areas.\n";
	}
}
