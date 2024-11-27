#pragma once
#include <string>

class Enemy {

private:

	int damage;

	std::string name;




public:

	Enemy(std::string Name, int Damage) : name(Name), damage(Damage) {};


};
