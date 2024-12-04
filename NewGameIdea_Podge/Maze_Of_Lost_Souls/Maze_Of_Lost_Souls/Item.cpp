#include "Item.h"
#include <iostream>

// Constructor sets item properties
Item::Item(std::string name, std::string description, int healthBoost, int attackBoost, bool isConsumable)
    : _name(name), _description(description), _healthBoost(healthBoost), _attackBoost(attackBoost), _isConsumable(isConsumable)
{
}

// Get the item's name
std::string Item::getName() const
{
    return _name;
}

// Get the item's description
std::string Item::getDescription() const
{
    return _description;
}

// Get the health boost value of the item
int Item::getHealthBoost() const
{
    return _healthBoost;
}

// Get the attack boost value of the item
int Item::getAttackBoost() const
{
    return _attackBoost;
}

// Check if the item is consumable
bool Item::isConsumable() const
{
    return _isConsumable;
}

// Use the item, applying boosts
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

// Print the details of the item
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
