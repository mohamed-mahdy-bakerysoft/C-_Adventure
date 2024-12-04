#pragma once
#include <string>
#include "Point2D.h"
#include "Map.h"

class Player
{
private:
    std::string _name;
    int _health;
    int _attack;
    int _xp;
    Point2D _position;  // Player's position on the map
    bool _hasKey;  // Whether the player has found a key to open locked doors

public:
    Player(std::string name, int health, int attack);

    void move(char direction, Map& gameMap);  // Move player and interact with the map
    void collectItem();  // Collect an item
    void openDoor();  // Try to open a door
    void gainXP(int xp);  // Gain experience points

    // Getters and Setters
    std::string getName()
    {
        return _name;
    }
    int getHealth()
    {
        return _health;
    }
    Point2D getPosition()
    {
        return _position;
    }
    void setHasKey(bool hasKey)
    {
        _hasKey = hasKey;
    }
};
