#include "Player.h"
#include "Inventory.h"
#include "DayCounter.h"

class SaveAndLoad 
{
    public:
        void saveGame(const Player& player, const Inventory& inventory, const DayCounter& dayCounter);
        bool loadGame(Player& player, Inventory& inventory, DayCounter& dayCounter);
};
