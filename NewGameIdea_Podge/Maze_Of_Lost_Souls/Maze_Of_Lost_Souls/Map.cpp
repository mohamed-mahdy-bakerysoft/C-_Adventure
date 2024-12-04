#include "Map.h"
#include <ctime>

// Constructor initializes map size and fills with empty spaces
Map::Map(int width, int height) : _width(width), _height(height)
{
    _map.resize(height, std::vector<char>(width, ' '));
}

// Sets a tile on the map at specific coordinates with a symbol
void Map::setTile(int x, int y, char symbol)
{
    if (x >= 0 && x < _width && y >= 0 && y < _height)
    {
        _map[y][x] = symbol;
    }
}

// Prints the map to the screen
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

// Checks if a tile is walkable (not a wall)
bool Map::isWalkable(int x, int y)
{
    return x >= 0 && x < _width && y >= 0 && y < _height && _map[y][x] != '#';
}

// Generates a random maze with walls ('#') and items ('I')
void Map::generateMaze()
{
    srand(time(0)); // Seed for random number generation

    // Loop through each cell to randomly place walls
    for (int y = 0; y < _height; ++y)
    {
        for (int x = 0; x < _width; ++x)
        {
            if (rand() % 10 < 2) // 20% chance to place a wall
            {
                setTile(x, y, '#');
            }
        }
    }

    // Loop through each cell to randomly place items
    for (int y = 0; y < _height; ++y)
    {
        for (int x = 0; x < _width; ++x)
        {
            if (_map[y][x] == ' ' && rand() % 5 < 1) // 20% chance for items
            {
                if (rand() % 2 == 0)
                {
                    setTile(x, y, 'I'); // Place an item
                }
            }
        }
    }

    // Place the player at a starting position
    setTile(1, 1, 'P');
}

// Gets the tile at a specific position on the map
char Map::getTile(int x, int y)
{
    return _map[y][x];
}

// Checks if the tile is a door
bool Map::isDoor(int x, int y)
{
    return getTile(x, y) == 'D';
}

// Checks if the tile is an item
bool Map::isItem(int x, int y)
{
    return getTile(x, y) == 'I';
}
