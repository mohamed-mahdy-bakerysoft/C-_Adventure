#pragma once
#include <string>
#include <vector>
#include "Point2D.h"
#include "Map.h"

class Player
{
private:
    std::string _name;
    int _health;
    int _attack;
    int _xp;
    Point2D _position;
    bool _hasKey;
    std::vector<std::string> _inventory;  // Inventory to store item names

public:
    Player(std::string name, int health, int attack);

    void move(char direction, Map& gameMap);  // Move player and interact with the map
    void collectItem(const std::string& itemName);  // Collect item and add it to inventory
    void openDoor();  // Try to open a door
    void gainXP(int xp);  // Gain experience points
    void showInventory();  // Display the inventory

    std::string getName() { return _name; }
    int getHealth() { return _health; }
    Point2D getPosition() { return _position; }
    void setHasKey(bool hasKey) { _hasKey = hasKey; }
};
