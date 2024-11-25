#include "ManageWin.h"
#include <iostream>

using namespace std;

void ManageWindow::DisplayTitle() {

	std::cout << R"(                                                                                                                                
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



void ManageWindow::GameLoop() {

	bool isRunning = true;
	int choice = 0;

	while (isRunning)
	{
		cout << "1 New Game" << '\n';
		cout << "2 Continue" << '\n';
		cout << "3 Quit" << '\n';

		cin >> choice;

		switch (choice) {

		case 1:

			break;

		case 2:
			break;

		case 3:

			break;

		default:
			cout << "quitting game ";


		}
		isRunning = false;


	}

}
