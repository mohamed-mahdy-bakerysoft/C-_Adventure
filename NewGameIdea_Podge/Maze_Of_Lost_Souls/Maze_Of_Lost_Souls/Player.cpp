#include "Player.h"
#include "Item.h"
#include <iostream>

// Constructor sets player's name, health, and attack power
Player::Player(std::string name, int health, int attack)
    : _name(name), _health(health), _attack(attack), _xp(0), _hasKey(false)
{
}

// Moves the player in a direction on the map
void Player::move(char direction, Map& gameMap)
{
    int newX = _position.getX();
    int newY = _position.getY();

    // Move based on direction
    switch (direction)
    {
    case 'w': newY--; break;
    case 's': newY++; break;
    case 'a': newX--; break;
    case 'd': newX++; break;
    }

    // If the new position is walkable, move the player
    if (gameMap.isWalkable(newX, newY))
    {
        gameMap.setTile(_position.getX(), _position.getY(), ' '); // Clear old position
        _position.setX(newX);
        _position.setY(newY);
        gameMap.setTile(newX, newY, 'P'); // Place player at new position

        // Check for items or doors at the new position
        if (gameMap.isItem(newX, newY))
        {
            Item* item = new Item("Healing Potion", "Restores 50 health.", 50, 0);
            collectItem(item); // Collect item
            gameMap.setTile(newX, newY, ' '); // Remove item from map
        }
        else if (gameMap.isDoor(newX, newY))
        {
            openDoor(); // Open door if applicable
        }
    }
}

// Collect an item and show its details
void Player::collectItem(Item* item)
{
    std::cout << "You found a " << item->getName() << "!" << std::endl;
    item->printDetails(); // Show item details

    _inventory.push_back(item); // Add item to inventory

    // If item is consumable, use it immediately
    if (item->isConsumable())
    {
        item->useItem();
    }

    std::cout << "Current Inventory: ";
    for (const auto& invItem : _inventory)
    {
        std::cout << invItem->getName() << " "; // Show inventory items
    }
    std::cout << std::endl;
}

// Open the door if the player has the key
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

// Gain experience points
void Player::gainXP(int xp)
{
    _xp += xp;
    std::cout << "Gained " << xp << " XP!" << std::endl;
}

// Show the player's inventory
void Player::showInventory()
{
    if (_inventory.empty())
    {
        std::cout << "Your inventory is empty." << std::endl;
    }
    else
    {
        std::cout << "Inventory: " << std::endl;
        for (const auto& invItem : _inventory)
        {
            std::cout << "- " << invItem->getName() << std::endl;
        }
    }
}

// Calculate the player's level based on XP
int Player::getLevel() const
{
    return _xp / 100; // Example: level up every 100 XP
}
