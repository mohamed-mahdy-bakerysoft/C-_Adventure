#ifndef INVENTORY_H
#define INVENTORY_H

#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Inventory {
public:
    void addItem(const string& item);
    bool hasItem(const string& item);
    void showInventory();

private:
    vector<string> items;
};

#endif // INVENTORY_H
