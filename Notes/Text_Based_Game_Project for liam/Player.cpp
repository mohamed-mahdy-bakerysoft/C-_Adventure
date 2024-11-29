#include "Player.h"
using namespace std;

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
    cout << "Name: " << name << "\n";
    cout << "Health: " << health << "/100\n";
    cout << "Score: " << score << "\n";
    cout << "Inventory: ";
    if (inventory.empty())
    {
        cout << "No items collected.\n";
    }
    else
    {
        for (const auto& item : inventory)
        {
            cout << item << " ";
        }
        cout << "\n";
    }
}
