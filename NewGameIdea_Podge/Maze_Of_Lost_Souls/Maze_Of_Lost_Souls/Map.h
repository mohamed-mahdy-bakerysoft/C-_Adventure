#pragma once
#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>

class Map
{
private:
    int _width, _height;  // Declaring the width and height of the map
    std::vector<std::vector<char>> _map;  // 2D grid representing the map

public:
    Map(int width, int height);  // Constructor

    void setTile(int x, int y, char symbol);  // Set a specific tile
    void printMap();  // Print the entire map
    bool isWalkable(int x, int y);  // Check if a tile is walkable
    void generateMaze();  // Generate the maze
    char getTile(int x, int y);  // Get the tile at a specific location
    bool isDoor(int x, int y);  // Check if the tile is a door
    bool isItem(int x, int y);  // Check if the tile is an item
};
