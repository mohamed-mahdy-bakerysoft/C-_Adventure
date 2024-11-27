#pragma once
#include <string>
<<<<<<< HEAD
#include <vector>
#include <iostream>

class Player
{
public:
    std::string name;            // Player's name
    int health;                  // Player's health
    int score;                   // Player's score
    std::vector<std::string> inventory;  // Player's inventory

    // Constructor to initialize player
    Player(std::string playerName, int initialHealth = 100, int initialScore = 0)
        : name(playerName), health(initialHealth), score(initialScore) {}

    void takeDamage(int damage);        // Reduces health
    void heal(int amount);              // Restores health
    void collectItem(const std::string& item);   // Add an item
    void displayStats() const;         // Display current stats
};
=======
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
>>>>>>> 9ddff4b3243310614f42f6809fcd49080599edea
