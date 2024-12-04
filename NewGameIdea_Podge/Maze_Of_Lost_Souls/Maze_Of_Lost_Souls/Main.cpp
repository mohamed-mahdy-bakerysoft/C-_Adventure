#include <iostream>
#include "Map.h"
#include "Player.h"
#include "Point2D.h"
#include <conio.h>

int main() {
    Player player("Hero", 100, 10);  // Example player
    Map gameMap(10, 10);  // Create a 10x10 map
    gameMap.generateMaze();  // Generate the maze

    bool inventoryVisible = false;  // Track inventory visibility

    // Game loop
    char input;
    while (true) {
        system("cls");  // Clear the screen
        gameMap.printMap();  // Print the map with the player's position

        // Print player info
        std::cout << "Player: " << player.getName() << " | Health: " << player.getHealth() << std::endl;

        // Show or hide inventory if 'i' is pressed
        if (inventoryVisible) {
            player.showInventory();
        }

        // Get player input
        input = _getch();

        if (input == 'q') {
            break;  // Quit the game
        }
        else if (input == 'i') {
            inventoryVisible = !inventoryVisible;  // Toggle inventory visibility
        }
        else {
            player.move(input, gameMap);  // Player movement
        }
    }

    return 0;
}
