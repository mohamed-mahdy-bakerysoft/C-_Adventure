#include "Player.h"
#include <iostream>

Player::Player(std::string name, int health, int attack) : _name(name), _health(health), _attack(attack), _xp(0), _hasKey(false) {}

void Player::move(char direction, Map& gameMap)
{
    int newX = _position.getX();
    int newY = _position.getY();

    // Calculate new position based on input direction
    switch (direction)
    {
    case 'w': newY--; break;  // Move up
    case 's': newY++; break;  // Move down
    case 'a': newX--; break;  // Move left
    case 'd': newX++; break;  // Move right
    }

    // Check if the new position is walkable
    if (gameMap.isWalkable(newX, newY))
    {
        // Remove the player symbol from the old position
        gameMap.setTile(_position.getX(), _position.getY(), ' ');  // Empty the old tile

        // Set the player symbol at the new position
        _position.setX(newX);
        _position.setY(newY);
        gameMap.setTile(newX, newY, 'P');  // Place player at new position

        // Check for interactions with items or doors
        if (gameMap.isItem(newX, newY))
        {
            collectItem();  // Collect the item
        }
        else if (gameMap.isDoor(newX, newY))
        {
            openDoor();  // Try to open the door
        }
    }
}

void Player::collectItem()
{
    std::cout << "You found an item!" << std::endl;
    // You can add specific item effects here (e.g., health potions, keys)
}

void Player::openDoor()
{
    if (_hasKey)
    {
        std::cout << "You unlocked and opened the door!" << std::endl;
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
