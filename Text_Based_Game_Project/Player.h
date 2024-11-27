#pragma once
#include <string>
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
