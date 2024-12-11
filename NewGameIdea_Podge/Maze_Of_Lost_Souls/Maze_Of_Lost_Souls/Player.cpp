#include "Player.h"
#include <iostream>
#include <chrono> // Sleep
#include <thread>// Sleep
#include "Map.h"

// Constructor
Player::Player(std::string name, int health, int attack)
    : name(name), health(health), attack(attack), xp(0), hasKey(false)
{

}

Player::Player()
{

}

// Move the player on the map
void Player::move(char direction, Map& gameMap)
{
    int newX = position.getX();
    int newY = position.getY();

    switch (direction)
    {
    case 'w':
        newY--;
        break;
    case 's':
        newY++;
        break;
    case 'a':
        newX--;
        break;
    case 'd':
        newX++;
        break;
    default:
        return;
    }

    if (gameMap.isWalkable(newX, newY))
    {
        if (gameMap.getTile(newX, newY) == 'D') // Check for door
        {
            if (hasKey)
            {
                std::cout << "Door Unlocked. Proceeding to next level." << std::endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(500));
                // Need to make level 2
            }
            else
            {
                std::cout << "Key Needed." << std::endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(500));
            }
        }
        else
        {
            gameMap.setTile(position.getX(), position.getY(), ' ');
            position.setX(newX);
            position.setY(newY);
            gameMap.setTile(newX, newY, '*');
        }
    }
}

// Add an item to the inventory
void Player::collectItem(const Item& item)
{
    inventory.push_back(item);
    gainXP(1);

    if (item.getName() == "Key")
    {
        hasKey = true;
    }
}

// Display the player's inventory
void Player::showInventory()
{
    if (inventory.empty())
    {
        std::cout << "Your inventory is empty." << std::endl;
    }
    else
    {
        for (const auto& item : inventory)
        {
            std::cout << "- " << item.getName() << std::endl;
        }
    }
}

// Checks Players Inventory for Item
bool Player::hasItem(const std::string& itemName)
{
    for (const Item& item : inventory)
    {
        if (item.getName() == itemName)
        {
            return true;
        }
    }
    return false;
}
// Player uses an Item, discards one instance
void Player::discardItem(const std::string& itemName)
{
    for (auto it = inventory.begin(); it != inventory.end(); ++it)
    {
        if (it->getName() == itemName)
        {
            inventory.erase(it);
            break;
        }
    }
}

// Gain experience points
void Player::gainXP(int xp)
{
    this->xp += xp;
}

// Heal the player
void Player::heal(int amount)
{
    health += amount;

    if (health > 100) // Assuming max health is 100
    {
        health = 100;
    }
}

// Calculate the player's level
int Player::getLevel() const
{
    return xp / 100;
}

// Set the player's position
void Player::setPosition(int x, int y)
{
    position.setX(x);
    position.setY(y);
}

// Set the player's health
void Player::setHealth(int health)
{
    this->health = health;
}

// Get the player's name
std::string Player::getName() const
{
    return name;
}

// Get the player's health
int Player::getHealth() const
{
    return health;
}

// Get the player's XP
int Player::getXP() const
{
    return xp;
}

// Get the player's position
Point2D Player::getPosition() const
{
    return position;
}

// Access the player's inventory
const std::vector<Item>& Player::getInventory() const
{
    return inventory;
}
