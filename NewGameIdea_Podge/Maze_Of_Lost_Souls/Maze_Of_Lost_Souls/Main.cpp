#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <chrono> // Sleep
#include <thread>// Sleep
#include <fstream> // For save/load functionality
#include <conio.h> // For _getch()
#include "Map.h"
#include "Player.h"
#include "Point2D.h"
#include "Item.h"
#include "Enemy.h"

// This shows the main menu where I can start, load, or quit the game
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

// Saves my game by writing the player's data to a file
void saveGame(const Player& player)
{
    std::ofstream saveFile("savegame.txt");

    // Save the player's current state
    saveFile << player.getName() << " " << player.getHealth() << " "
        << player.getXP() << " " << player.getPosition().getX() << " "
        << player.getPosition().getY() << "\n";

    // Save all the items in the inventory
    for (const auto& item : player.getInventory())
    {
        saveFile << item.getName() << " " << item.getDescription() << "\n";
    }

    saveFile.close();
    std::cout << "Game saved!" << std::endl;
}

// Loads my saved game from a file
void loadGame(Player& player, Map& gameMap)
{
    std::ifstream loadFile("savegame.txt");

    // Check if the save file exists
    if (!loadFile.is_open())
    {
        std::cout << "No save file found. Starting a new game." << std::endl;
        return;
    }

    std::string playerName;
    int health, xp, x, y;

    // Read player data
    if (!(loadFile >> playerName >> health >> xp >> x >> y))
    {
        std::cout << "Error reading player data. Starting a new game." << std::endl;
        return;
    }

    player = Player(playerName, health, 10);
    player.setPosition(x, y);
    player.gainXP(xp);

    // Load the player's inventory
    std::string itemName, itemDescription;
    while (loadFile >> itemName)
    {
        std::getline(loadFile, itemDescription);
        if (!itemDescription.empty() && itemDescription[0] == ' ')
        {
            itemDescription.erase(0, 1);
        }
        player.collectItem(Item(itemName, itemDescription));
    }

    // Update the map with the player's position
    gameMap.setTile(x, y, '*');
    std::cout << "Game successfully loaded!" << std::endl;
}

int main()
{
    Enemy enemy; // Enemy to interact with during the game
    std::string playerName;
    char menuChoice;

    displayMainMenu(); // Show the game menu

    while (true)
    {
        menuChoice = _getch(); // Get input from the menu

        if (menuChoice == '1') // Start a new game
        {
            std::cout << "Enter your player name: ";
            std::getline(std::cin, playerName);

            if (playerName.empty())
            {
                playerName = "Hero"; // Default name
            }

            Player player(playerName, 50, 10); // Create a player
            Map gameMap(10, 10);               // Create a 10x10 map
            gameMap.generateMaze();           // Generate a random maze

            bool inventoryVisible = false; // Keep track of inventory visibility

            char input;
            while (true)
            {
                system("cls");          // Clear the console
                gameMap.printMap();     // Show the map

                // Display the player's current stats
                std::cout << "Player: " << player.getName() << " | Health: " << player.getHealth()
                    << " | XP: " << player.getXP() << " | Level: " << player.getLevel() << std::endl;

                // Show inventory if toggled
                if (inventoryVisible)
                {
                    player.showInventory();
                }

                input = _getch(); // Get input for movement or actions

                if (input == 'q') // Quit the game
                {
                    saveGame(player); // Save the game before exiting
                    break;
                }
                else if (input == 'i') // Toggle inventory visibility
                {
                    inventoryVisible = !inventoryVisible;
                    while (_kbhit()) _getch();
                }
                else if (input == 'h') //Use a Potion
                {
                    if (player.getHealth() == 100)
                    {
                        std::cout << "At Max Health!" << std::endl;
                        std::this_thread::sleep_for(std::chrono::milliseconds(500));
                    }
                    else if (player.hasItem("Potion"))
                    {
                        player.heal(20);
                        player.discardItem("Potion");
                        std::cout << "1 potion used. Health restored." << std::endl;
                        std::this_thread::sleep_for(std::chrono::milliseconds(500));
                    }
                    else
                    {
                        std::cout << "You don't have any potions." << std::endl;
                        std::this_thread::sleep_for(std::chrono::milliseconds(500));
                    }
                    while (_kbhit()) _getch(); // Clear input
                }
                else // Move the player
                {
                    // Attempt to pick up an item if standing on one
                    int x = player.getPosition().getX();
                    int y = player.getPosition().getY();
                    if (gameMap.isItem(x, y))
                    {
                        Item item = gameMap.getItem(x, y); // Pickup item from the map
                        player.collectItem(item);

                        // Check if player has key and door
                        if (player.hasItem("Door") && player.hasItem("Key"))
                        {
                            std::cout << "You used the Key to unlock the Door! A new maze will be generated." << std::endl;
                            std::this_thread::sleep_for(std::chrono::milliseconds(1000));

                            // Remove the key and door from inventory
                            player.discardItem("Key");
                            player.discardItem("Door");

                            // Generate a new map
                            gameMap = Map(10, 10); // Create a new map
                            gameMap.generateMaze(); // Generate the new maze

                            // Reset the player's position
                            player.setPosition(0, 0); // Start at the top-left
                            gameMap.setTile(0, 0, '*'); // Mark the player's starting position
                            player.gainXP(100);
                        }

                        /*else if (item.getName() == "Enemy")
                        {
                            enemy.Damage_Player(20);
                        }*/

                        gameMap.setTile(x, y, ' '); // Remove the item
                    }
                    player.move(input, gameMap);
                }
            }
            break; // Exit the game loop
        }
        else if (menuChoice == '2') // Load a saved game
        {
            Player player("Hero", 50, 10);
            Map gameMap(10, 10);
            gameMap.generateMaze();
            loadGame(player, gameMap);

            bool inventoryVisible = false; // Keep track of inventory visibility
            char input;
            while (true)
            {
                system("cls");
                gameMap.printMap();
                std::cout << "Player: " << player.getName() << " | Health: " << player.getHealth()
                    << " | XP: " << player.getXP() << " | Level: " << player.getLevel() << std::endl;
                
                // Show inventory if toggled
                if (inventoryVisible)
                {
                    player.showInventory();
                }
                input = _getch();

                if (input == 'q') // Quit the game
                {
                    saveGame(player);
                    break;
                }
                else if (input == 'i') // Toggle inventory visibility
                {
                    inventoryVisible = !inventoryVisible;
                    while (_kbhit()) _getch();
                }
                else if (input == 'h') //Use a Potion
                {
                    if (player.getHealth() == 100)
                    {
                        std::cout << "At Max Health!" << std::endl;
                        std::this_thread::sleep_for(std::chrono::milliseconds(500));
                    }
                    else if (player.hasItem("Potion"))
                    {
                        player.heal(20);
                        player.discardItem("Potion");
                        std::cout << "1 Potion Used. Health restored." << std::endl;
                        std::this_thread::sleep_for(std::chrono::milliseconds(500));
                    }
                    else
                    {
                        std::cout << "You don't have any potions." << std::endl;
                        std::this_thread::sleep_for(std::chrono::milliseconds(500));
                    }
                    while (_kbhit()) _getch(); // Clear input
                }
                else // Move the player
                {
                    int x = player.getPosition().getX();
                    int y = player.getPosition().getY();
                    if (gameMap.isItem(x, y))
                    {
                        Item item = gameMap.getItem(x, y); // Pickup item from the map
                        player.collectItem(item);

                        // Check if player has key and door
                        if (player.hasItem("Door") && player.hasItem("Key"))
                        {
                            std::cout << "You used the Key to unlock the Door! A new maze will be generated." << std::endl;
                            std::this_thread::sleep_for(std::chrono::milliseconds(1000));

                            // Remove the key from inventory
                            player.discardItem("Key");
                            player.discardItem("Door");

                            // Generate a new map
                            gameMap = Map(10, 10); // Create a new map
                            gameMap.generateMaze(); // Generate the new maze

                            // Reset the player's position
                            player.setPosition(0, 0); // Start at the top-left corner
                            gameMap.setTile(0, 0, '*'); // Mark the player's starting position
                        }

                        if (player.hasItem("Enemy"))
                        {
                            Enemy enemy;
                            enemy.Damage_Player(20);
                            player.discardItem("Enemy");
                        }


                        gameMap.setTile(x, y, ' '); // Remove Item
                    }
                    player.move(input, gameMap);
                }
            }
            break;
        }
        else if (menuChoice == '3') // Quit
        {
            std::cout << "Exiting game. Goodbye!" << std::endl;
            break;
        }
        else // Invalid menu choice
        {
            std::cout << "Invalid choice, please press '1', '2', or '3'." << std::endl;
        }
    }

    return 0;
}
