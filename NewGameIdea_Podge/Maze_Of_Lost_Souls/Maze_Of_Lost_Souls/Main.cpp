#include <iostream>
#include "Player.h"
#include "Map.h"
#include <conio.h>

int main()
{
    Player player("Hero", 100, 10);  // Example player
    Map gameMap(10, 10);  // Create a 10x10 map
    gameMap.generateMaze();  // Generate the maze

    // Game loop
    char input;
    while (true)
    {
        system("cls");  // Clear the screen
        gameMap.printMap();  // Print the map with the player's position

        // Print player info
        std::cout << "Player: " << player.getName() << " | Health: " << player.getHealth() << std::endl;

        // Get player input
        input = _getch();
        if (input == 'q')
        {
            break;  // Quit the game
        }

        // Player movement
        player.move(input, gameMap);
    }

    return 0;
}
