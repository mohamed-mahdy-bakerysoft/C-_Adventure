#pragma once
#include "Item.h"
#include <map>
#include "Point2D.h"
#include <vector>

class Map
{
private:
    int _width, _height;
    std::vector<std::vector<char>> map;
    std::map<Point2D, Item> itemMap; // Store items directly

public:
    bool isItem(int x, int y);
    bool isWalkable(int x, int y);
    char getTile(int x, int y);
    Item getItem(int x, int y); // Fetch item from the map
    Map(int width, int height);
    void generateMaze();
    void placeItemsOnMap();
    void printMap();
    void setTile(int x, int y, char symbol);
};