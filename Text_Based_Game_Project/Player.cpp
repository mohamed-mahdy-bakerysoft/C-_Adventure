#include "Player.h"

// Method to reduce health
void Player::takeDamage(int damage)
{
    health -= damage;
    if (health < 0)
    {
        health = 0;  // Ensure health doesn't go below zero
    }
}

// Method to heal the player
void Player::heal(int amount)
{
    health += amount;
    if (health > 100)
    {
        health = 100;  // Cap health at 100
    }
}

// Method to collect an item
void Player::collectItem(const std::string& item)
{
    inventory.push_back(item);
}

// Method to display the player's current stats
void Player::displayStats() const
{
    std::cout << "Name: " << name << "\n";
    std::cout << "Health: " << health << "/100\n";
    std::cout << "Score: " << score << "\n";
    std::cout << "Inventory: ";
    if (inventory.empty())
    {
        std::cout << "No items collected.\n";
    }
    else
    {
        for (const auto& item : inventory)
        {
            std::cout << item << " ";
        }
        std::cout << "\n";
    }
}
