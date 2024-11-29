#pragma once
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Player
{
private:
	string name;            // Player's name
	int health;                  // Player's health
	int score;                   // Player's score
	vector<string> inventory;  // Player's inventory

public:
	// Constructor to initialize player
	Player(string playerName, int initialHealth = 100, int initialScore = 0)
		: name(playerName), health(initialHealth), score(initialScore)
	{}
	Player() = default;

	// Getter and Setter for name
	string getName() const
	{
		return name;
	}

	void setName(const string& playerName)
	{
		name = playerName;
	}

	// Getter and Setter for health
	int getHealth() const
	{
		return health;
	}

	void setHealth(int newHealth)
	{
		health = newHealth;
	}

	// Getter and Setter for score
	int getScore() const
	{
		return score;
	}

	void setScore(int newScore)
	{
		score = newScore;
	}

	// Getter for inventory
	vector<string> getInventory() const
	{
		return inventory;
	}

	void takeDamage(int damage);        // Reduces health
	void heal(int amount);              // Restores health
	void collectItem(const string& item);   // Add an item
	void displayStats() const;         // Display current stats
};
