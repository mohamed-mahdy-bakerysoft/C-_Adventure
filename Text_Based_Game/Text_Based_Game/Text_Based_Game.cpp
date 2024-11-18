// text_based_game.cpp
#include <iostream>
#include <cstdlib> // For system()
#include <vector>
#include <string>
#include "Player.h"
#include "SaveAndLoad.h"

using namespace std;

// Function prototypes
void displayTitle();
void clearScreen();
void startNewGame();
void loadExistingGame();

int main()
{
    displayTitle(); // Show the title of the game

    int choice;

    // Main game loop
    do
    {
        // Show main menu options
        cout << "Welcome to the Prison Break Game!" << endl;
        cout << " " << endl;
        cout << "Choose an option:" << endl;
        cout << "1. Start New Game" << endl;
        cout << "2. Load Existing Game" << endl;
        cout << "3. Exit" << endl; // Option to exit
        cout << "" << endl;

        // Get the player's choice
        cout << "Enter your choice: ";
        cin >> choice;

        clearScreen(); // Clear the console after the choice

        switch (choice)
        {
        case 1:
            startNewGame();
            break;

        case 2:
            loadExistingGame();
            break;

        case 3:
            cout << "Exiting the game. Goodbye!" << endl;
            break;

        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
        cout << endl; // New line for better readability

    } while (choice != 3); // Continue until the player chooses to exit

    return 0; // Exit the program successfully
}

// This function shows the title of the game
void displayTitle()
{
    const string red = "\033[31m"; // Set the text color to red
    const string reset = "\033[0m"; // Reset the text color to normal

    // Print the word "Prison" in red
    cout << red;
    cout << "                                 88888888ba               88                                          " << endl;
    cout << "                                 88      \"8b              \"\"                                          " << endl;
    cout << "                                 88      ,8P                                                     " << endl;
    cout << "                                 88aaaaaa8P'  8b,dPPYba,  88  ,adPPYba,   ,adPPYba,   8b,dPPYba, " << endl;
    cout << "                                 88\"\"\"\"\"\"'    88P'   \"Y8  88  I8[    \"\"  a8\"     \"8a  88P'   `\"8a" << endl;
    cout << "                                 88           88          88   `\"Y8ba,   8b       d8  88       88" << endl;
    cout << "                                 88           88          88  aa    ]8I  \"8a,   ,a8\"  88       88" << endl;
    cout << "                                 88           88          88  `\"YbbdP\"'   `\"YbbdP\"'   88       88" << endl;
    cout << reset << endl;  // Go back to normal text color

    // Print the word "Break" in red
    cout << red;
    cout << "                                 88888888ba                                       88" << endl;
    cout << "                                 88      \"8b                                      88" << endl;
    cout << "                                 88      ,8P                                      88" << endl;
    cout << "                                 88aaaaaa8P'  8b,dPPYba,   ,adPPYba,  ,adPPYYba,  88   ,d8" << endl;
    cout << "                                 88\"\"\"\"\"\"8b,  88P'   \"Y8  a8P_____88  \"\"     `Y8  88 ,a8\" " << endl;
    cout << "                                  88     ,d8P  88          8PP\"\"\"\"\"\"\"   88      88  88\"    " << endl;
    cout << "                                  88   ,d8\"    88          \"8b,   ,aa   88      88  88       " << endl;
    cout << "                                  88888888P     88           `\"Ybbd8\"'   88      88  88       " << endl;
    cout << reset; // Go back to normal text color
}

// Function to clear the console screen
void clearScreen()
{
#ifdef _WIN32
    system("cls"); // For Windows
#else
    system("clear"); // For Unix-based systems
#endif
}

// Function to start a new game
void startNewGame()
{
    string playerName;

    cout << "Enter your name: ";
    cin >> playerName;

    Player player(playerName); // Create a new player instance
    savePlayerData(player); // Save player data to a file
    cout << "New game started!" << endl;
    player.displayStatus(); // Display player status
}

// Function to load an existing game
void loadExistingGame()
{
    string playerName;

    cout << "Enter your name to load your game: ";
    cin >> playerName;

    Player player(playerName); // Create a new player instance
    if (loadPlayerData(player, playerName))
    {
        cout << "Game loaded successfully!" << endl;
        player.displayStatus(); // Display loaded player status
    }
    else
    {
        cout << "No saved game found for '" << playerName << "'." << endl;
    }
}
