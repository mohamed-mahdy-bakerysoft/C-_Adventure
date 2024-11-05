// Player.h
#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include <string>

class Player {
private:
    std::string name;
    int health;
    std::vector<std::string> inventory;

public:
    Player(std::string playerName);

    // Getters
    std::string getName() const;
    int getHealth() const;
    size_t getInventorySize() const;
    const std::vector<std::string>& getInventory() const;

    // Setters
    void setName(const std::string& playerName);
    void setHealth(int newHealth);
    void clearInventory();

    // Methods
    void displayStatus();
    void addItem(const std::string& item);
    bool useItem(const std::string& item);
    void takeDamage(int damage);
    void heal(int amount);
};

#endif // PLAYER_H
