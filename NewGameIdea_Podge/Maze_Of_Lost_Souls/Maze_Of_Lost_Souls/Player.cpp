#include "Player.h"
#include "Item.h"
#include <iostream>

// Constructor sets player's name, health, and attack power
Player::Player(std::string name, int health, int attack)
    : _name(name), _health(health), _attack(attack), _xp(0), _hasKey(false)
{
}

void Player::move(char direction, Map& gameMap)
{
    int newX = _position.getX();
    int newY = _position.getY();

    std::cout << "Current Position: (" << _position.getX() << ", " << _position.getY() << ")" << std::endl;

    // Determine the new position based on input
    switch (direction)
    {
    case 'w': newY--; break; // Move up
    case 's': newY++; break; // Move down
    case 'a': newX--; break; // Move left
    case 'd': newX++; break; // Move right
    }

    std::cout << "Attempting to move to: (" << newX << ", " << newY << ")" << std::endl;

    // Check if the new position is walkable
    if (gameMap.isWalkable(newX, newY))
    {
        gameMap.setTile(_position.getX(), _position.getY(), ' '); // Clear old position
        _position.setX(newX);
        _position.setY(newY);
        gameMap.setTile(newX, newY, 'P'); // Set new position
        std::cout << "Player moved to: (" << newX << ", " << newY << ")" << std::endl;
    }
    else
    {
        std::cout << "Position not walkable." << std::endl;
    }
}


void Player::collectItem(std::shared_ptr<Item> item)
{
    std::cout << "Attempting to collect item at position: (" << _position.getX() << ", " << _position.getY() << ")" << std::endl;
    if (item)
    {
        std::cout << "Collected: " << item->getName() << std::endl;
        _inventory.push_back(item); // Add item to inventory

        // If the item is a key, mark it as collected
        if (item->getName() == "Key")
        {
            _hasKey = true;
            std::cout << "You now have a key!" << std::endl;
        }

        // Gain XP for collecting the item
        gainXP(1);
        std::cout << "Gained 1 XP. Current XP: " << _xp << std::endl;
    }
    else
    {
        std::cout << "No item to collect!" << std::endl;
    }
}

void Player::showInventory()
{
    std::cout << "Displaying inventory..." << std::endl;
    if (_inventory.empty())
    {
        std::cout << "Your inventory is empty." << std::endl;
    }
    else
    {
        std::cout << "Inventory: " << std::endl;
        for (const auto& item : _inventory)
        {
            std::cout << "- " << item->getName() << std::endl;
        }
    }
}

void Player::openDoor()
{
    if (_hasKey)
    {
        std::cout << "You used the key to unlock the door!" << std::endl;
        _hasKey = false; // Consume the key
    }
    else
    {
        std::cout << "The door is locked. Find a key to open it!" << std::endl;
    }
}

void Player::gainXP(int xp)
{
    _xp += xp;
    std::cout << "Gained " << xp << " XP!" << std::endl;
}

int Player::getLevel() const
{
    return _xp / 100; // Level up every 100 XP
}

std::vector<std::shared_ptr<Item>> Player::getInventory() const
{
    return _inventory;
}

void Player::setPosition(int x, int y)
{
    _position.setX(x);
    _position.setY(y);
}
