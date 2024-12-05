#pragma once
#include <string>
#include <vector>
#include "Point2D.h"
#include "Item.h"
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
    std::vector<Item> _inventory;

public:
    Player(std::string name, int health, int attack);

    void move(char direction, Map& gameMap);
    void collectItem(const Item& item);
    void gainXP(int xp);
    void showInventory();
    int getLevel() const;

    void setPosition(int x, int y);
    std::string getName() const;
    int getHealth() const;
    int getXP() const;
    Point2D getPosition() const;

    const std::vector<Item>& getInventory() const;
};
