#include <iostream>
#include "DayCounter.h"  // Include the header file for DayCounter class
//#include "Tree_3.h"      // Include other necessary header files
#include "ManageWin.h"

using namespace std;
ManageWindow Mw;
// The DayCounter class is already defined in the header file, no need to redefine it here

void DayCounter::increment() {
	currentDay++;  // Increment the day
	std::cout << "Day " << currentDay << " has passed.\n";

	if (currentDay >= maxDays) {
		Mw.serveSentence();  // Trigger the end of the game if max days are reached
	}
	else {
		Mw.Stay_In_Cell_Option();  // Call the Stay_In_Cell_Option function from Tree_3
	}
}
