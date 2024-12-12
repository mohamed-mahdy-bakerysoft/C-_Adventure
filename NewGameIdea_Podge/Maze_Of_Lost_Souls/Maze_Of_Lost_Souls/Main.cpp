#include <conio.h> // For _getch()
#include "GameManager.h"
#include <iostream>
#include <string>

int main() 
{
    GameManager gameManager; //Reference to GameManager
    std::string playerName;
    char menuChoice;

    gameManager.displayMainMenu(); // Show the game menu

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

            gameManager.startGame(playerName);
        }
        else if (menuChoice == '2') // Load a saved game
        {
            Player player("Hero", 50, 10);
            Map gameMap(10, 10);
            gameMap.generateMaze();
            gameManager.loadGame(player, gameMap);

            gameManager.gameLoop(player, gameMap);
        }
        else if (menuChoice == '3') // Quit
        {
            std::cout << "Exiting game...."
                << std::endl;
            break;
        }
        else // Invalid menu choice
        {
            std::cout << "Invalid choice, please press '1', '2', or '3'."
                << std::endl;
        }
    }

    return 0;
}