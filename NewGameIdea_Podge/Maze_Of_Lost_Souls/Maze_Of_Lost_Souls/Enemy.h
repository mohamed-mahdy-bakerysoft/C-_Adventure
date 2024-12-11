#pragma once
#include <vector>
#include "Point2D.h"
#include "Map.h"

class Enemy
{
private:

    int health;
    int attackDamage;


public:
    Enemy(int health, int attack);
    Enemy();
    void Damage_Player(int Damage);

};
