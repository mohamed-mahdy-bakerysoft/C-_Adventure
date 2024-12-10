#pragma once
#include <string>
#include <vector>
#include "Point2D.h"
#include "Item.h"
#include "Map.h"

class Player
{
private:
    std::string name;
    int health;
    int attack;
    int xp;
    Point2D position;
    bool hasKey;
    std::vector<Item> inventory;

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
