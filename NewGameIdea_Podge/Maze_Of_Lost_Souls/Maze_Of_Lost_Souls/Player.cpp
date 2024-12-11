#include "Player.h"
#include <iostream>
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
        gameMap.setTile(position.getX(), position.getY(), ' ');
        position.setX(newX);
        position.setY(newY);
        gameMap.setTile(newX, newY, '*');
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
    else if (hasKey)
    {
        if (item.getName() == "")
        {
            // TODO: Generate a new level if the player has the key and interacts with the door
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
