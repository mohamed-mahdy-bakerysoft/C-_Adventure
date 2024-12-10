#pragma once
#include <vector>
#include <map>
#include "Item.h"
#include "Point2D.h"

class Map
{
private:
    int _width, _height;
    std::vector<std::vector<char>> _map;
    std::map<Point2D, Item> _itemMap; // Store items directly

public:
    Map(int width, int height);

    void setTile(int x, int y, char symbol);
    void printMap();
    bool isWalkable(int x, int y);
    void generateMaze();
    char getTile(int x, int y);
    bool isItem(int x, int y);
    Item getItem(int x, int y); // Fetch item from the map
    void placeItemsOnMap();
};