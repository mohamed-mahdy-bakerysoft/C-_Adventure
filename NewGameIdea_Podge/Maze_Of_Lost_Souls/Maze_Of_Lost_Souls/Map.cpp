#include "Map.h"
#include "Item.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

// Constructor for Map
Map::Map(int width, int height) : _width(width), _height(height)
{
    _map.resize(height, std::vector<char>(width, ' '));
    srand(time(0));  // Initialize random seed
}

// Set the tile at specific coordinates
void Map::setTile(int x, int y, char symbol)
{
    if (x >= 0 && x < _width && y >= 0 && y < _height)
    {
        _map[y][x] = symbol;
    }
}

// Print the map
void Map::printMap()
{
    for (int y = 0; y < _height; ++y)
    {
        for (int x = 0; x < _width; ++x)
        {
            std::cout << "[" << _map[y][x] << "]";
        }
        std::cout << std::endl;
    }
}

// Check if the tile is walkable (not a wall)
bool Map::isWalkable(int x, int y)
{
    return x >= 0 && x < _width && y >= 0 && y < _height && _map[y][x] != '#';
}

// Get the tile at a specific position
char Map::getTile(int x, int y)
{
    return _map[y][x];
}

// Check if the tile contains an item
bool Map::isItem(int x, int y)
{
    return _map[y][x] != ' ' && _map[y][x] != '#';  // Items are not walls or empty spaces
}

// Check if the tile contains a door
bool Map::isDoor(int x, int y)
{
    return _map[y][x] == 'D';  // Example: Door symbol as 'D'
}

// Randomly place items from the item pool and the key ('K') on the map
void Map::placeItemsOnMap()
{
    for (int y = 0; y < _height; ++y)
    {
        for (int x = 0; x < _width; ++x)
        {
            // Ensure we place items on empty spaces (' ')
            if (_map[y][x] == ' ' && rand() % 5 < 1)  // 20% chance for items
            {
                // Randomly choose to place either an item or the key
                if (rand() % 10 < 1)  // 10% chance to place a key ('K')
                {
                    setTile(x, y, 'K');  // Place key
                }
                else
                {
                    // Select a random item from the pool
                    auto randomItem = Item::getItemPool()[rand() % Item::getItemPool().size()];
                    char itemSymbol = randomItem->getName()[0];
                    setTile(x, y, itemSymbol);  // Place item (using its first letter as the symbol)
                }
            }
        }
    }
}

// Generate a random maze with walls and items
void Map::generateMaze()
{
    for (int y = 0; y < _height; ++y)
    {
        for (int x = 0; x < _width; ++x)
        {
            if (rand() % 10 < 2)  // 20% chance to place a wall
            {
                setTile(x, y, '#');
            }
        }
    }

    // Place items from the pool on the map
    placeItemsOnMap();

    // Place the player at a starting position
    setTile(1, 1, 'P');
}
