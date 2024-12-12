#pragma once
#include <string>

class Item
{
private:

    std::string description;
    std::string name;

public:
    // Constructor to initialize name and description
    Item(std::string name = "Default", std::string description = "Default description");

    // Getter for item name
    std::string getName() const;

    // Getter for item description
    std::string getDescription() const;

    // Print item details
    void printDetails() const;
};
