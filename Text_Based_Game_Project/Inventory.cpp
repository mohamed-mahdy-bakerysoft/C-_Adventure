#include "Inventory.h"

void Inventory::addItem(const string& item) {
    if (!hasItem(item)) {
        items.push_back(item);
        cout << "Added " << item << " to your inventory.\n";
    }
    else {
        cout << item << " is already in your inventory.\n";
    }
}

bool Inventory::hasItem(const string& item) {
    return find(items.begin(), items.end(), item) != items.end();
}

void Inventory::showInventory() {
    cout << "Your inventory contains:\n";
    for (const auto& item : items) {
        cout << "- " << item << '\n';
    }
}
