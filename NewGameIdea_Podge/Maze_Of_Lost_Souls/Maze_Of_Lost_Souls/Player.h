#pragma once
#include "Item.h"
#include "Map.h"
#include "Point2D.h"
#include <string>
#include <vector>

class Player
{
private:
    bool hasKey;
    bool loadingSave;
    int health;
    int attack;
    int xp;
    Point2D position;
    std::string name;
    std::vector<Item> inventory;

public:
    const std::vector<Item>& getInventory() const;
    bool hasItem(const std::string& itemName);
    int getHealth() const;
    int getLevel() const;
    int getXP() const;
    Player(std::string name, int health, int attack);
    Player();
    Point2D getPosition() const;
    std::string getName() const;
    void collectItem(const Item& item);
    void discardItem(const std::string& itemName);
    void gainXP(int xp);
    void heal(int amount);
    void move(char direction, Map& gameMap);
    void setLoadingSave(bool loading);
    void setHealth(int health);
    void setPosition(int x, int y);
    void showInventory();
};
   