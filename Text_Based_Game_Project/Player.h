#pragma once
#include <string>
#include <vector>
#include <iostream>

class Player
{
private:
    std::string name;            // Player's name
    int health;                  // Player's health
    int score;                   // Player's score
    std::vector<std::string> inventory;  // Player's inventory

public:
    // Constructor to initialize player
    Player(std::string playerName, int initialHealth = 100, int initialScore = 0)
        : name(playerName), health(initialHealth), score(initialScore)
    {}

    // Getter and Setter for name
    std::string getName() const
    {
        return name;
    }

    void setName(const std::string& playerName)
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
    std::vector<std::string> getInventory() const
    {
        return inventory;
    }

    // Methods to interact with player
    void takeDamage(int damage);        // Reduces health
    void heal(int amount);              // Restores health
    void collectItem(const std::string& item);   // Add an item
    void displayStats() const;         // Display current stats
};
