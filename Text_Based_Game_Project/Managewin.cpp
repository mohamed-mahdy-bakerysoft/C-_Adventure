#include "ManageWin.h"
#include <iostream>

using namespace std;

void ManageWindow::DisplayTitle() {
	const std::string RED = "\033[31m";
	std::cout << RED << R"(                                                                                                                                
88888888ba               88                                          88888888ba                                       88         
88      "8b              ""                                          88      "8b                                      88         
88      ,8P                                                          88      ,8P                                      88         
88aaaaaa8P'  8b,dPPYba,  88  ,adPPYba,   ,adPPYba,   8b,dPPYba,      88aaaaaa8P'  8b,dPPYba,   ,adPPYba,  ,adPPYYba,  88   ,d8   
88""""""'    88P'   "Y8  88  I8[    ""  a8"     "8a  88P'   `"8a     88""""""8b,  88P'   "Y8  a8P_____88  ""     `Y8  88 ,a8"    
88           88          88   `"Y8ba,   8b       d8  88       88     88      `8b  88          8PP"""""""  ,adPPPPP88  8888[      
88           88          88  aa    ]8I  "8a,   ,a8"  88       88     88      a8P  88          "8b,   ,aa  88,    ,88  88`"Yba,   
88           88          88  `"YbbdP"'   `"YbbdP"'   88       88     88888888P"   88           `"Ybbd8"'  `"8bbdP"Y8  88   `Y8a  
                                                                                                                                 
                                                                                                                                 
)" << std::endl;

}

void ManageWindow::NewGame()
{
	DisplayText();
}

void ManageWindow::LoadGame()
{
	// save and load
}







void ManageWindow::GameLoop() {

	bool isRunning = true;
	int choice = 0;
	const std::string RESET = "\033[0m"; // Reset to default color
	while (isRunning)
	{
		cout << RESET << "1 New Game" << '\n';
		cout << RESET << "2 Continue" << '\n';
		cout << RESET << "3 Quit" << '\n';

		cin >> choice;

		switch (choice) {

		case 1:
			system("cls"); // clear screen
			NewGame();
			break;

		case 2:
			system("cls"); // clear screen

			LoadGame();
			break;

		case 3:

			break;

		default:
			cout << "quitting game ";


		}
		isRunning = false;


	}

}

void ManageWindow::InGameLoop()  // loop used after main menu
{
	bool isRunning = true;
	int choice = 0;
	const std::string YELLOW = "\033[33m";

	while (isRunning)
	{
		cout << YELLOW << "1 Leave cell" << '\n';
		cout << YELLOW << "2 Stay in cell" << '\n';
		cout << YELLOW << "3 Rest" << '\n';
		cout << YELLOW << "4 Quit Game" << '\n';


		cin >> choice;

		switch (choice) {

		case 1:
			system("cls"); // clear screen

			break;

		case 2:

			break;

		case 3:

			break;

		case 4:
			cout << "quitting game ";
			break;


		}
		isRunning = false;


	}

}