#include "Player.h"
#include <iostream>

Player::Player(std::string name, int health, int attack)
    : _name(name), _health(health), _attack(attack), _xp(0), _hasKey(false) {
}

void Player::move(char direction, Map& gameMap) {
    int newX = _position.getX();
    int newY = _position.getY();

    switch (direction) {
    case 'w': newY--; break;  // Move up
    case 's': newY++; break;  // Move down
    case 'a': newX--; break;  // Move left
    case 'd': newX++; break;  // Move right
    }

    if (gameMap.isWalkable(newX, newY)) {
        gameMap.setTile(_position.getX(), _position.getY(), ' ');  // Empty the old tile
        _position.setX(newX);
        _position.setY(newY);
        gameMap.setTile(newX, newY, 'P');  // Place player at new position

        if (gameMap.isItem(newX, newY)) {
            collectItem("Sample Item");  // Replace with actual item collection logic
        }
        else if (gameMap.isDoor(newX, newY)) {
            openDoor();
        }
    }
}

void Player::collectItem(const std::string& itemName) {
    std::cout << "You found an item: " << itemName << std::endl;
    _inventory.push_back(itemName);  // Add item to the inventory
}

void Player::openDoor() {
    if (_hasKey) {
        std::cout << "You unlocked and opened the door!" << std::endl;
    }
    else {
        std::cout << "The door is locked. Find a key to open it!" << std::endl;
    }
}

void Player::gainXP(int xp) {
    _xp += xp;
    std::cout << "Gained " << xp << " XP!" << std::endl;
}

void Player::showInventory() {
    if (_inventory.empty()) {
        std::cout << "Your inventory is empty." << std::endl;
    }
    else {
        std::cout << "Inventory: " << std::endl;
        for (const auto& item : _inventory) {
            std::cout << "- " << item << std::endl;
        }
    }
}
