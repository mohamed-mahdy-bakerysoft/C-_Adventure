#pragma once
#ifndef MANAGEWIN_H
#define MANAGEWIN_H


class ManageWindow {

private:

public:


	void DisplayTitle();

	void GameLoop(); // loop at game title

	void NewGame();

	void LoadGame();

	void IntroText();

	void IntroGameLoop(); // loop starts when new game option is picked

	void Rest_Option();

	//General stuff
	void Random_Enemie();

	void increment();

	//void Leave_Cell_Option();
	void Leave_Cell_Option();

	void PrisonYardOption();

	void CanteenOption();

	void BathroomOption();

	void SecuirityHoldingOption();


	//void Stay_in_Cell_Option();
	void Stay_In_Cell_Option();

	void Wait();

	void FileBars();

	void CraftRope();

	void Dont_Stay();

	void ClearScreen();

	//void Prison_Yard_Option();
	void Climb_Fence();

	void serveSentence();

	void ExamineYard();

	void LeaveYard();


};
#endif // MANAGEWIN_H
