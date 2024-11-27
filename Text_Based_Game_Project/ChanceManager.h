#pragma once
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "Player.h"

using namespace std;

class chances {
public:

	Player player;

	void fight()
	{
		std::srand(std::time(0));

		int opponetDamage = rand() % 101;





		int newHP = opponetDamage -= player.getHealth();
		int gainedScore = player.getScore() + 2;
		std::cout << "player hp: " << newHP << "\n";
		if (newHP < 50)
		{
			cout << "was it really worth it?\n";
		}

	}




};
