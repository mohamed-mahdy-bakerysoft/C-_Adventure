#pragma once
#include <string>
class Player {
private:
	std::string name; // Player's name
	int health;  // Player's health
	int score; // Player's score


public:

	// Constructor to initialize player
	Player(std::string playerName, int initialHealth = 100, int initialScore = 0) : name(playerName), health(initialHealth), score(initialScore) {};


	int getHealth()
	{
		return health;
	}

	int getScore()
	{
		return score;
	}

	string getName()
	{
		return name;
	};

	// Method to take damage
	//void takeDamage(int damage);

	// Method to heal
	//void heal(int amount);

	// Method to display player's stats
//	void displayStats();

};