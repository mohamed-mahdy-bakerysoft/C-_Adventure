// SaveAndLoad.h
#ifndef SAVEANDLOAD_H
#define SAVEANDLOAD_H

#include <string>
#include "Player.h"

void savePlayerData(const Player& player);
bool loadPlayerData(Player& player, const std::string& playerName);

#endif // SAVEANDLOAD_H
