#include "Map.h"

Map::Map(int width, int height) : _width(width), _height(height)
{
    _map.resize(height, std::vector<char>(width, ' '));  // Initialize the map with empty spaces
}

void Map::setTile(int x, int y, char symbol)
{
    if (x >= 0 && x < _width && y >= 0 && y < _height)
    {
        _map[y][x] = symbol;
    }
}

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

bool Map::isWalkable(int x, int y)
{
    return x >= 0 && x < _width && y >= 0 && y < _height && _map[y][x] != '#';  // # is a wall
}

void Map::generateMaze()
{
    srand(time(0));  // Seed for random generation

    // Add walls randomly
    for (int y = 0; y < _height; ++y)
    {
        for (int x = 0; x < _width; ++x)
        {
            if (rand() % 10 < 2)
            {  // Random chance to place a wall
                setTile(x, y, '#');
            }
        }
    }

    // Place items and doors randomly
    for (int y = 0; y < _height; ++y)
    {
        for (int x = 0; x < _width; ++x)
        {
            if (_map[y][x] == ' ' && rand() % 5 < 1)
            {  // Random chance to place items or doors
                if (rand() % 2 == 0)
                {
                    setTile(x, y, 'I');  // Item
                }
                else {
                    setTile(x, y, 'D');  // Door
                }
            }
        }
    }

    // Make sure player starts in a free spot
    setTile(1, 1, 'P');  // P is the player
}

char Map::getTile(int x, int y)
{
    return _map[y][x];
}

bool Map::isDoor(int x, int y)
{
    return getTile(x, y) == 'D';
}

bool Map::isItem(int x, int y)
{
    return getTile(x, y) == 'I';
}
