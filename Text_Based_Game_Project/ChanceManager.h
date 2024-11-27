#pragma once
#include <cstdlib>
#include <ctime>
#include <iostream>

class chances {


	void fight()
	{
		std::srand(std::time(0));

		int opponetDamage = rand() % 101;
		//bool FightPicked;




		int newHP = opponetDamage -= ;
		std::cout << "player hp: " << newHP << "\n";
		//	cout << "XP: " << gainedXP << '\n';
		if (newHP < 50)
		{
			cout << "was it really worth it?\n";
		}





	};