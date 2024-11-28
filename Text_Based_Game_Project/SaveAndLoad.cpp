#include "SaveAndLoad.h"
#include "Player.h"
#include "Inventory.h"
#include "DayCounter.h"
#include <fstream>
#include <iostream>

void SaveAndLoad::saveGame(const Player& player, const Inventory& inventory, const DayCounter& dayCounter) 
{
    std::ofstream saveFile("save.txt");

    if (saveFile.is_open()) 
    {
        saveFile << player.getName() << std::endl;
        saveFile << player.getHealth() << std::endl;
        saveFile << player.getScore() << std::endl;

        std::vector<std::string> items = inventory.getInventory();
        saveFile << items.size() << std::endl;
        for (const auto& item : items) {
            saveFile << item << std::endl;
        }

        saveFile << dayCounter.getDay() << std::endl;
        saveFile.close();
        std::cout << "Game Saved!\n";
    }
    else 
    {
        std::cerr << "Error creating save file!\n";
    }
}

bool SaveAndLoad::loadGame(Player& player, Inventory& inventory, DayCounter& dayCounter) 
{
    std::ifstream loadFile("save.txt");

    if (loadFile.is_open()) 
    {
        std::string name;
        int health, score, day, numItems;

        loadFile >> name;
        player.setName(name);
        loadFile >> health;
        player.setHealth(health);
        loadFile >> score;
        player.setScore(score);

        loadFile >> numItems;
        for (int i = 0; i < numItems; ++i) 
        {
            std::string item;
            loadFile >> item;
            inventory.addItem(item);
        }

        loadFile >> day;
        dayCounter.setDay(day);

        loadFile.close();
        std::cout << "Game Loaded!\n";
        return true;
    }
    else 
    {
        std::cerr << "No save file found.....\n";
        return false;
    }
}
