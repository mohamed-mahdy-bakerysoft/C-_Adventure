#include "Item.h"
#include <iostream>

// Constructor to initialize item properties
Item::Item(std::string name, std::string description)
    : name(name), description(description)
{

}

// Get the name of the item
std::string Item::getName() const
{
    return name;
}

// Get the description of the item
std::string Item::getDescription() const
{
    return description;
}

// Print the item details
void Item::printDetails() const
{
    std::cout << "Item: " << name << std::endl;
    std::cout << "Description: " << description << std::endl;
}
