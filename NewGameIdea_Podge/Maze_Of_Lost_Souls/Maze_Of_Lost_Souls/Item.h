#pragma once
#include <string>
#include <iostream>

class Item {
private:
    std::string _name;
    std::string _description;
    int _healthBoost;
    int _attackBoost;
    bool _isConsumable;

public:
    Item(std::string name, std::string description, int healthBoost = 0, int attackBoost = 0, bool isConsumable = true);

    std::string getName() const;
    std::string getDescription() const;
    int getHealthBoost() const;
    int getAttackBoost() const;
    bool isConsumable() const;

    void useItem();
    void printDetails() const;
};
