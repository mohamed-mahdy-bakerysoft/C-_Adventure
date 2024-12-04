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
    case 'w': newY--; break;  // Move up
    case 's': newY++; break;  // Move down
    case 'a': newX--; break;  // Move left
    case 'd': newX++; break;  // Move right
    }

    // If the new position is walkable, move the player
    if (gameMap.isWalkable(newX, newY))
    {
        // Clear the old position on the map
        gameMap.setTile(_position.getX(), _position.getY(), ' ');

        // Update player's position
        _position.setX(newX);
        _position.setY(newY);

        // Set the new position with 'P' (player)
        gameMap.setTile(newX, newY, 'P');

        // Check for items or doors at the new position
        if (gameMap.isItem(newX, newY))
        {
            // If the spacebar is pressed, collect the item
            std::cout << "Press SPACE to pick up the item." << std::endl;
        }
        else if (gameMap.isDoor(newX, newY))
        {
            openDoor(); // Open door if applicable
        }
        else if (gameMap.getTile(newX, newY) == 'K')  // If the tile is a key
        {
            std::cout << "You found a key!" << std::endl;
            gameMap.setTile(newX, newY, ' '); // Remove key from the map after collection
        }
    }
}

// Collect an item and show its details
void Player::collectItem(std::shared_ptr<Item> item)
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
    if (_xp == 0)
    {
        return 0; // Return level 0 if XP is 0 to avoid division by zero
    }
    return _xp / 100; // Level up every 100 XP
}
