#pragma once
#include <vector>
#include <memory>
#include "Item.h"

class Map
{
private:
    int _width, _height;
    std::vector<std::vector<char>> _map;

public:
    Map(int width, int height);

    void setTile(int x, int y, char symbol);
    void printMap();
    bool isWalkable(int x, int y);
    void generateMaze();
    char getTile(int x, int y);
    bool isItem(int x, int y);
    bool isDoor(int x, int y);
    void placeItemsOnMap();
};
