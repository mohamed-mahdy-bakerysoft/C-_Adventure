#pragma once
#include <string>
#include <vector>
#include <memory>  // For std::shared_ptr
#include "Point2D.h"
#include "Map.h"
#include "Item.h"

class Player
{
private:
    std::string _name;
    int _health;
    int _attack;
    int _xp;
    Point2D _position;
    bool _hasKey;
    std::vector<std::shared_ptr<Item>> _inventory; // Change to shared_ptr

public:
    Player(std::string name, int health, int attack);

    void move(char direction, Map& gameMap);
    void collectItem(std::shared_ptr<Item> item); // Change to shared_ptr
    void openDoor();
    void gainXP(int xp);
    void showInventory();

    std::string getName() { return _name; }
    int getHealth() { return _health; }
    int getXP() { return _xp; } // Getter for XP
    int getLevel() const; // Method to calculate level based on XP
    Point2D getPosition() { return _position; }
    void setHasKey(bool hasKey) { _hasKey = hasKey; }
};
