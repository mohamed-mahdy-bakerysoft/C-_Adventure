#include <cstdlib>
#include <ctime>
#include "Enemy.h"
#include <iostream>
#include "Player.h"

Player player; // reference to player class
//constructor 
Enemy::Enemy(int health, int attack) : health(health), attackDamage(attack) {}

Enemy::Enemy(){}


// Damages Player
void Enemy::Damage_Player(Player& player, int amount)
{
    player.heal(-amount);
}