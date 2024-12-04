#pragma once
#include <string>
#include <vector>
#include <memory> // For std::shared_ptr
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
    std::vector<std::shared_ptr<Item>> _inventory; // Use shared_ptr for inventory items

public:
    Player(std::string name, int health, int attack);

    void move(char direction, Map& gameMap);
    void collectItem(std::shared_ptr<Item> item);
    void openDoor();
    void gainXP(int xp);
    void showInventory();
    int getLevel() const;
    std::vector<std::shared_ptr<Item>> getInventory() const;
    void setPosition(int x, int y);
    void setHasKey(bool hasKey)
    {
        _hasKey = hasKey;
    }

    std::string getName() const
    {
        return _name;
    }
    int getHealth() const
    {
        return _health;
    }
    int getXP() const
    {
        return _xp;
    }
    Point2D getPosition() const
    {
        return _position;
    }
};
