#include "Enemy.h"
#include "Player.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

Player player; // reference to player class
//constructor 
Enemy::Enemy(int health, int attack) : health(health), attackDamage(attack) {}

Enemy::Enemy(){}



void Enemy::Damage_Player(int Damage)
{
	

	player.setHealth(player.getHealth() - Damage);
	std::cout << "Player's health: " << player.getHealth() << std::endl;
}