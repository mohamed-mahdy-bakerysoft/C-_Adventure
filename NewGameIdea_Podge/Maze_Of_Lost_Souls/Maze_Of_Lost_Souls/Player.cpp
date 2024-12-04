#include "Player.h"
#include "Item.h"
#include <iostream>

Player::Player(std::string name, int health, int attack)
    : _name(name), _health(health), _attack(attack), _xp(0), _hasKey(false)
{
}

void Player::move(char direction, Map& gameMap)
{
    int newX = _position.getX();
    int newY = _position.getY();

    switch (direction)
    {
    case 'w': newY--; break; // Move up
    case 's': newY++; break; // Move down
    case 'a': newX--; break; // Move left
    case 'd': newX++; break; // Move right
    default:
        return; // Invalid input
    }

    if (gameMap.isWalkable(newX, newY))
    {
        gameMap.setTile(_position.getX(), _position.getY(), ' '); // Clear old position
        _position.setX(newX);
        _position.setY(newY);
        gameMap.setTile(newX, newY, 'P'); // Mark new position
    }
}

void Player::collectItem(std::shared_ptr<Item> item)
{
    if (item)
    {
        _inventory.push_back(item);
        gainXP(1);
        if (item->getName() == "Key")
        {
            _hasKey = true;
        }
    }
}

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
            std::cout << "- " << item->getName() << std::endl;
        }
    }
}

void Player::gainXP(int xp)
{
    _xp += xp;
}

int Player::getLevel() const
{
    return _xp / 100;
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
