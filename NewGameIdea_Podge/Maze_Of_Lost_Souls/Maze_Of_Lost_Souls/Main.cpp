#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <fstream> // For save/load functionality
#include <conio.h> // For _getch()

#include "Map.h"
#include "Player.h"
#include "Point2D.h"
#include "Item.h"

// This function shows the main menu of the game
void displayMainMenu()
{
    std::cout << "============================================" << std::endl;
    std::cout << "       WELCOME TO THE MAZE OF LOST SOULS    " << std::endl;
    std::cout << "   ==========================================" << std::endl;
    std::cout << "   |  [1] Start Game         | " << std::endl;
    std::cout << "   |  [2] Load Game          | " << std::endl;
    std::cout << "   |  [3] Quit               | " << std::endl;
    std::cout << "   ==========================================" << std::endl;
}

// Save the player's state
void saveGame(const Player& player)
{
    std::ofstream saveFile("savegame.txt");
    saveFile << player.getName() << " " << player.getHealth() << " " << player.getXP() << " "
        << player.getPosition().getX() << " " << player.getPosition().getY() << "\n";
    for (const auto& item : player.getInventory())
    {
        saveFile << item->getName() << "\n";
    }
    saveFile.close();
    std::cout << "Game saved!" << std::endl;
}

// Load the player's state
void loadGame(Player& player, Map& gameMap)
{
    std::ifstream loadFile("savegame.txt");
    if (!loadFile.is_open())
    {
        std::cout << "No save file found. Starting new game." << std::endl;
        return;
    }
    std::string playerName;
    int health, xp, x, y;
    loadFile >> playerName >> health >> xp >> x >> y;
    player = Player(playerName, health, 10); // Assume default attack power
    player.setPosition(x, y);
    player.gainXP(xp);
    std::string itemName;
    while (loadFile >> itemName)
    {
        auto item = std::find_if(Item::getItemPool().begin(), Item::getItemPool().end(),
            [&](std::shared_ptr<Item> i) { return i->getName() == itemName; });
        if (item != Item::getItemPool().end())
        {
            player.collectItem(*item);
        }
    }
    loadFile.close();
    gameMap.setTile(x, y, 'P');
    std::cout << "Game loaded!" << std::endl;
}

int main()
{
    // Initialize the item pool with default items
    Item::initializeItemPool();

    std::string playerName;
    char menuChoice;

    // Show the main menu
    displayMainMenu();

    while (true)
    {
        menuChoice = _getch();

        if (menuChoice == '1') // Start new game
        {
            std::cout << "Enter your player name: ";
            std::getline(std::cin, playerName);

            if (playerName.empty())
            {
                playerName = "Hero"; // Default name if no input
            }

            Player player(playerName, 100, 10); // Create player
            Map gameMap(10, 10);               // Create a map of size 10x10
            gameMap.generateMaze();           // Generate a maze

            bool inventoryVisible = false;    // Initialize inventory visibility toggle

            char input;
            while (true)
            {
                system("cls");                // Clear screen
                gameMap.printMap();           // Display the map

                // Print the player's status
                std::cout << "Player: " << player.getName() << " | Health: " << player.getHealth()
                    << " | XP: " << player.getXP() << " | Level: " << player.getLevel() << std::endl;

                // If the inventory is visible, show it
                if (inventoryVisible)
                {
                    player.showInventory();
                }

                input = _getch(); // Get player input

                if (input == 'q')
                {
                    break; // Exit the game loop
                }
                else if (input == ' ')
                {
                    // Attempt to pick up an item if standing on one
                    int x = player.getPosition().getX();
                    int y = player.getPosition().getY();
                    if (gameMap.isItem(x, y))
                    {
                        auto item = gameMap.getItem(x, y); // Fetch the actual item from the map
                        if (item)
                        {
                            player.collectItem(item);
                            gameMap.setTile(x, y, ' '); // Remove the item from the map
                        }
                    }
                }
                else if (input == 'i')
                {
                    inventoryVisible = !inventoryVisible; // Toggle inventory visibility
                    if (inventoryVisible)
                    {
                        player.showInventory();
                    }
                }
                else
                {
                    player.move(input, gameMap); // Move player on the map
                }
            }
            break; // Exit main menu loop
        }
        else if (menuChoice == '2') // Load game
        {
            Player player("Hero", 100, 10); // Default values; overwritten by loadGame
            Map gameMap(10, 10);           // Create a map of size 10x10
            gameMap.generateMaze();        // Generate a maze
            loadGame(player, gameMap);

            char input;
            while (true)
            {
                system("cls");
                gameMap.printMap();

                std::cout << "Player: " << player.getName() << " | Health: " << player.getHealth()
                    << " | XP: " << player.getXP() << " | Level: " << player.getLevel() << std::endl;

                input = _getch();
                if (input == 'q')
                {
                    break;
                }
                else if (input == ' ')
                {
                    int x = player.getPosition().getX();
                    int y = player.getPosition().getY();
                    if (gameMap.isItem(x, y))
                    {
                        auto item = gameMap.getItem(x, y); // Fetch the actual item from the map
                        if (item)
                        {
                            player.collectItem(item);
                            gameMap.setTile(x, y, ' '); // Remove the item from the map
                        }
                    }
                }
                else
                {
                    player.move(input, gameMap); // Move player
                }
            }
            break;
        }
        else if (menuChoice == '3') // Quit
        {
            std::cout << "Exiting game. Goodbye!" << std::endl;
            break;
        }
        else
        {
            std::cout << "Invalid choice, please press '1' to start, '2' to load, or '3' to quit." << std::endl;
        }
    }

    return 0;
}
