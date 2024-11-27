#pragma once
#include <string>

class Player {
public:
    // Member variables
    std::string name;  // Player's name
    int health;        // Player's health
    int score;         // Player's score

    // Constructor to initialize player
    Player(std::string playerName, int initialHealth = 100, int initialScore = 0);

    // Method to take damage
    void takeDamage(int damage);

    // Method to heal
    void heal(int amount);

    // Method to display player's stats
    void displayStats();
};
