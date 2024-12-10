#include "Player.h"
#include <iostream>
#include "Map.h"

// Constructor
Player::Player(std::string name, int health, int attack)
    : name(name), health(health), attack(attack), xp(0), hasKey(false)
{

}

// Move the player on the map
void Player::move(char direction, Map& gameMap)
{
    int newX = position.getX();
    int newY = position.getY();

    switch (direction)
    {
    case 'w': newY--; break;
    case 's': newY++; break;
    case 'a': newX--; break;
    case 'd': newX++; break;
    default: return;
    }

    if (gameMap.isWalkable(newX, newY))
    {
        gameMap.setTile(position.getX(), position.getY(), ' ');
        position.setX(newX);
        position.setY(newY);
        gameMap.setTile(newX, newY, 'P');
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
    //Open nenoor
    else if (hasKey == true)
    {
        if (item.getName() == "")
        {
            //if player has key and tries to pick up the door it generates a new level
            //implement that shit here

        }
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

// Gain experience points
void Player::gainXP(int xp)
{
    xp += xp;
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