#include "Item.h"
#include <iostream>
#include <memory>

std::vector<std::shared_ptr<Item>> Item::_itemPool;  // Static pool of items

// Constructor to initialize item properties
Item::Item(std::string name, std::string description, int healthBoost, int attackBoost, bool isConsumable)
    : _name(name), _description(description), _healthBoost(healthBoost), _attackBoost(attackBoost), _isConsumable(isConsumable)
{
}

// Static method to return the item pool
std::vector<std::shared_ptr<Item>> Item::getItemPool()
{
    return _itemPool;
}

// Static method to add an item to the pool
void Item::addItemToPool(std::shared_ptr<Item> item)
{
    _itemPool.push_back(item);
}

// Initialize the item pool with some default items
void Item::initializeItemPool()
{
    addItemToPool(std::make_shared<Item>("Healing Potion", "Restores 50 health.", 50, 0, true));
    addItemToPool(std::make_shared<Item>("Strength Potion", "Increases attack by 20.", 0, 20, true));
    addItemToPool(std::make_shared<Item>("Mana Potion", "Restores 30 mana.", 0, 0, true));
    addItemToPool(std::make_shared<Item>("Shield", "Increases defense by 10.", 0, 0, false));
    addItemToPool(std::make_shared<Item>("Magic Sword", "Increases attack by 50.", 0, 50, false));
    // Add the key as an item
    addItemToPool(std::make_shared<Item>("Key", "A key to open locked doors.", 0, 0, false));  // Key is not consumable
}

// Get the name of the item
std::string Item::getName() const
{
    return _name;
}

// Check if the item is consumable
bool Item::isConsumable() const
{
    return _isConsumable;
}

// Use the item (e.g., applying health or attack boosts)
void Item::useItem()
{
    if (_healthBoost > 0)
    {
        std::cout << "You gained " << _healthBoost << " health!" << std::endl;
    }
    if (_attackBoost > 0)
    {
        std::cout << "You gained " << _attackBoost << " attack!" << std::endl;
    }
}

// Print the item details
void Item::printDetails() const
{
    std::cout << "Item: " << _name << std::endl;
    std::cout << "Description: " << _description << std::endl;
    if (_healthBoost > 0)
    {
        std::cout << "Health Boost: " << _healthBoost << std::endl;
    }
    if (_attackBoost > 0)
    {
        std::cout << "Attack Boost: " << _attackBoost << std::endl;
    }
    if (_isConsumable)
    {
        std::cout << "This item is consumable." << std::endl;
    }
    else
    {
        std::cout << "This item is not consumable." << std::endl;
    }
}
