#include "ManageWin.h"
#include <iostream>
#include "Player.h"

using namespace std;

//this will contain tree 2 of possible  outcomes

Player player;



void ManageWindow::Rest_Option()
{

	cout << "Sleep sleep sleep" << '\n';
	cout << "dang I feel so much better" << '\n';
	cout << "well I don't know if that helped much" << '\n';
	player.heal(2);

}
