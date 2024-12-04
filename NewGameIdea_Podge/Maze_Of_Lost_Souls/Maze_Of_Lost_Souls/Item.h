#pragma once
#include <string>
#include <vector>
#include <memory>  // For std::shared_ptr

class Item {
private:
    std::string _name;
    std::string _description;
    int _healthBoost;
    int _attackBoost;
    bool _isConsumable;

public:
    // Constructor to initialize item properties
    Item(std::string name, std::string description, int healthBoost = 0, int attackBoost = 0, bool isConsumable = true);

    // Getters
    std::string getName() const;
    std::string getDescription() const;
    int getHealthBoost() const;
    int getAttackBoost() const;
    bool isConsumable() const;

    // Static function to get the item pool
    static std::vector<std::shared_ptr<Item>> getItemPool();

    // Static function to add items to the pool
    static void addItemToPool(std::shared_ptr<Item> item);

    // Static function to initialize the item pool
    static void initializeItemPool();

    // Item actions
    void useItem();
    void printDetails() const;

private:
    // Static item pool that holds all the item templates
    static std::vector<std::shared_ptr<Item>> _itemPool;
};
