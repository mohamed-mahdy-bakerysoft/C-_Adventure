#include "Item.h"
#include <iostream>

// Constructor to initialize item properties
Item::Item(std::string name, std::string description)
    : _name(name), _description(description)
{

}

// Get the name of the item
std::string Item::getName() const
{
    return _name;
}

// Get the description of the item
std::string Item::getDescription() const
{
    return _description;
}

// Print the item details
void Item::printDetails() const
{
    std::cout << "Item: " << _name << std::endl;
    std::cout << "Description: " << _description << std::endl;
}
