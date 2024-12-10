#include "Player.h"
#include <iostream>
#include "Map.h"

// Constructor
Player::Player(std::string name, int health, int attack)
    : _name(name), _health(health), _attack(attack), _xp(0), _hasKey(false)
{

}

// Move the player on the map
void Player::move(char direction, Map& gameMap)
{
    int newX = _position.getX();
    int newY = _position.getY();

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
        gameMap.setTile(_position.getX(), _position.getY(), ' ');
        _position.setX(newX);
        _position.setY(newY);
        gameMap.setTile(newX, newY, 'P');
    }
}

// Add an item to the inventory
void Player::collectItem(const Item& item)
{
    _inventory.push_back(item);
    gainXP(1);
    if (item.getName() == "Key")
    {
        _hasKey = true;
    }
    //Open nenoor
    else if (_hasKey == true)
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
    if (_inventory.empty())
    {
        std::cout << "Your inventory is empty." << std::endl;
    }
    else
    {
        for (const auto& item : _inventory)
        {
            std::cout << "- " << item.getName() << std::endl;
        }
    }
}

// Gain experience points
void Player::gainXP(int xp)
{
    _xp += xp;
}

// Calculate the player's level
int Player::getLevel() const
{
    return _xp / 100;
}

// Set the player's position
void Player::setPosition(int x, int y)
{
    _position.setX(x);
    _position.setY(y);
}

// Get the player's name
std::string Player::getName() const
{
    return _name;
}

// Get the player's health
int Player::getHealth() const
{
    return _health;
}

// Get the player's XP
int Player::getXP() const
{
    return _xp;
}

// Get the player's position
Point2D Player::getPosition() const
{
    return _position;
}

// Access the player's inventory
const std::vector<Item>& Player::getInventory() const
{
    return _inventory;
}