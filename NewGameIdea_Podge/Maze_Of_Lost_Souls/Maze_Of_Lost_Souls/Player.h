#pragma once
#include <string>
#include <vector>
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
    std::vector<Item*> _inventory;

public:
    Player(std::string name, int health, int attack);

    void move(char direction, Map& gameMap);
    void collectItem(Item* item);
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
