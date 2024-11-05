// SaveAndLoad.cpp

#include <iostream>
#include <fstream>
#include "SaveAndLoad.h"

using namespace std;

void savePlayerData(const Player& player) {
    ofstream outfile(player.getName() + ".save");
    if (outfile) {
        outfile << player.getName() << endl;
        outfile << player.getHealth() << endl;

        const auto& inventory = player.getInventory();
        outfile << inventory.size() << endl; // Save inventory size
        for (const string& item : inventory) {
            outfile << item << endl; // Save each item
        }

        outfile.close();
        cout << "Game saved successfully as " << player.getName() + ".save" << "!" << endl;
    }
    else {
        cout << "Error saving game data." << endl;
    }
}

bool loadPlayerData(Player& player, const string& playerName) {
    ifstream infile(playerName + ".save");
    if (!infile) {
        return false; // Return false if the file does not exist
    }

    string name;
    int health;
    size_t inventorySize;

    infile >> name >> health;
    infile >> inventorySize;

    player.setName(name);
    player.setHealth(health);
    player.clearInventory();

    for (size_t i = 0; i < inventorySize; i++) {
        string item;
        infile >> item;
        player.addItem(item);
    }

    infile.close();
    return true; // Return true on successful load
}
