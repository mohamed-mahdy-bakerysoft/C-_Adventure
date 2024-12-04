#include "Map.h"
#include "Item.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

// Constructor for Map
Map::Map(int width, int height) : _width(width), _height(height)
{
    _map.resize(height, std::vector<char>(width, ' '));
    srand(time(0)); // Initialize random seed
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
    return x >= 0 && x < _width && y >= 0 && y < _height && _map[y][x] != '#';
}

char Map::getTile(int x, int y)
{
    return _map[y][x];
}

bool Map::isItem(int x, int y)
{
    return _itemMap.find({ x, y }) != _itemMap.end();
}

std::shared_ptr<Item> Map::getItem(int x, int y)
{
    auto it = _itemMap.find({ x, y });
    if (it != _itemMap.end())
    {
        auto item = it->second;
        _itemMap.erase(it); // Remove item from map
        return item;
    }
    return nullptr;
}

bool Map::isDoor(int x, int y)
{
    return _map[y][x] == 'D'; // Example: Door symbol as 'D'
}

void Map::placeItemsOnMap()
{
    bool keyPlaced = false;
    bool doorPlaced = false;

    while (!keyPlaced || !doorPlaced)
    {
        int x = rand() % _width;
        int y = rand() % _height;

        if (_map[y][x] == ' ') // Only place on empty tiles
        {
            if (!keyPlaced)
            {
                setTile(x, y, 'K');
                _itemMap[{x, y}] = std::make_shared<Item>("Key", "A key to open locked doors.", 0, 0, false);
                keyPlaced = true;
            }
            else if (!doorPlaced)
            {
                setTile(x, y, 'D'); // Place a door
                doorPlaced = true;
            }
        }
    }

    // Add additional items
    int additionalItems = 5;
    for (int i = 0; i < additionalItems; ++i)
    {
        int x = rand() % _width;
        int y = rand() % _height;

        if (_map[y][x] == ' ')
        {
            auto randomItem = Item::getItemPool()[rand() % Item::getItemPool().size()];
            setTile(x, y, randomItem->getName()[0]);
            _itemMap[{x, y}] = randomItem;
        }
    }
}



void Map::generateMaze()
{
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

    placeItemsOnMap(); // Place a single door and key
    setTile(1, 1, 'P'); // Place the player at the starting position
}
