#pragma once
#include "Player.h"
#include "Map.h"

class GameManager 
{
public:

    void displayMainMenu();
    void gameLoop(Player& player, Map& gameMap);
    void loadGame(Player& player, Map& gameMap);
    void saveGame(const Player& player);
    void startGame(const std::string& playerName);

};