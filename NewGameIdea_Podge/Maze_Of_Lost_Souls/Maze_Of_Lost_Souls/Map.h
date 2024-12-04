#pragma once
#include <vector>
#include <map>
#include <memory>
#include "Item.h"
#include "Point2D.h"

class Map
{
private:
    int _width, _height;
    std::vector<std::vector<char>> _map;
    std::map<Point2D, std::shared_ptr<Item>> _itemMap; // Map of coordinates to items

public:
    Map(int width, int height);

    void setTile(int x, int y, char symbol);
    void printMap();
    bool isWalkable(int x, int y);
    void generateMaze();
    char getTile(int x, int y);
    bool isItem(int x, int y);
    bool isDoor(int x, int y);
    std::shared_ptr<Item> getItem(int x, int y); // Fetch item from the map
    void placeItemsOnMap();
};
