// Player.cpp

#include <iostream>
#include <vector>
#include <string>
#include "Player.h"

using namespace std;

// Constructor to initialize player attributes
Player::Player(string playerName) : name(playerName), health(100)
{

}

// Getters
string Player::getName() const
{
    return name;
}

int Player::getHealth() const
{
    return health;
}

size_t Player::getInventorySize() const
{
    return inventory.size();
}

const vector<string>& Player::getInventory() const
{
    return inventory;
}

// Setters
void Player::setName(const string& playerName)
{
    name = playerName;
}

void Player::setHealth(int newHealth)
{
    health = newHealth;
}

// Clear inventory
void Player::clearInventory()
{
    inventory.clear();
}

// Method to display player status
void Player::displayStatus()
{
    cout << "Player Name: " << name << endl;
    cout << "Health: " << health << endl;
    cout << "Inventory: ";

    if (inventory.empty())
    {
        cout << "Empty" << endl;
    }
    else {
        for (const string& item : inventory)
        {
            cout << item << " ";
        }
        cout << endl;
    }
}

// Method to add item to inventory
void Player::addItem(const string& item)
{
    inventory.push_back(item);
    cout << item << " has been added to your inventory." << endl;
}

// Method to use an item from inventory
bool Player::useItem(const string& item)
{
    for (size_t i = 0; i < inventory.size(); i++)
    {
        if (inventory[i] == item)
        {
            cout << "You used " << item << "." << endl;
            inventory.erase(inventory.begin() + i);
            return true;
        }
    }
    cout << "Item not found in inventory." << endl;
    return false;
}

// Method to take damage
void Player::takeDamage(int damage)
{
    health -= damage;
    if (health < 0)
    {
        health = 0; // Ensure health doesn't drop below zero
    }
    cout << "You took " << damage << " damage. Health is now " << health << "." << endl;
}

// Method to heal the player
void Player::heal(int amount)
{
    health += amount;
    if (health > 100)
    {
        health = 100; // Cap health at 100
    }
    cout << "You healed for " << amount << " points. Health is now " << health << "." << endl;
}
