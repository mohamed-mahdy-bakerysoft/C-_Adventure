#pragma once
#include "Player.h"
#include "Point2D.h"
#include "Map.h"
#include <vector>
class Enemy
{
private:

    int attackDamage;
    int health;
    
public:
    Enemy(int health, int attack);
    Enemy();
    void Damage_Player(Player& player, int amount);

};
