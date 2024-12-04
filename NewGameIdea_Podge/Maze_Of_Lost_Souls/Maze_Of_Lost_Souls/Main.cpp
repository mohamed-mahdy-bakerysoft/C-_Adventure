#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <cstdlib>
#include <ctime>
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
    std::cout << "     _______________________  " << std::endl;
    std::cout << "   |   ADVENTURE GAME        | " << std::endl;
    std::cout << "   |  [1] Start Game         | " << std::endl;
    std::cout << "   |  [2] Load Game          | " << std::endl;
    std::cout << "   |  [3] Quit               | " << std::endl;
    std::cout << "   ==========================================" << std::endl;
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

        if (menuChoice == '1')
        {
            // Ask the player for their name
            std::cout << "Enter your player name: ";
            std::getline(std::cin, playerName);

            if (playerName.empty())
            {
                playerName = "Hero"; // Default name if no input
            }

            Player player(playerName, 100, 10); // Create player
            Map gameMap(10, 10); // Create a map of size 10x10
            gameMap.generateMaze(); // Generate a maze

            bool inventoryVisible = false; // Inventory is not shown initially

            char input;
            while (true)
            {
                system("cls"); // Clear screen
                gameMap.printMap(); // Display the map

                // Print the player's status
                std::cout << "Player: " << player.getName() << " | Health: " << player.getHealth() << " | XP: " << player.getXP() << " | Level: " << player.getLevel() << std::endl;

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
                else if (input == 'i')
                {
                    inventoryVisible = !inventoryVisible; // Toggle inventory visibility
                }
                else if (input == ' ')
                {
                    // Attempt to pick up an item if standing on one
                    if (gameMap.isItem(player.getPosition().getX(), player.getPosition().getY()))
                    {
                        std::shared_ptr<Item> item = std::make_shared<Item>("Healing Potion", "Restores 50 health.", 50, 0); // You may want to handle item reference properly
                        player.collectItem(item); // Collect item
                    }
                }
                else
                {
                    player.move(input, gameMap); // Move player on the map
                }
            }
            break; // Exit main menu loop
        }
        else if (menuChoice == '2')
        {
            std::cout << "Load Game functionality is not implemented yet." << std::endl;
            break; // Exit if load game is chosen
        }
        else if (menuChoice == '3')
        {
            std::cout << "Exiting game. Goodbye!" << std::endl;
            break; // Exit if quit is chosen
        }
        else
        {
            std::cout << "Invalid choice, please press '1' to start, '2' to load, or '3' to quit." << std::endl;
        }
    }

    return 0;
}
