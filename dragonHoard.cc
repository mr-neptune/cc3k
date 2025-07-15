#include "dragonHoard.h"

DragonHoard::DragonHoard(int x, int y, GameObject *below) : Gold(x, y, below)
{
    isProtected = true;
}

DragonHoard::~DragonHoard() {}

bool DragonHoard::getStatus() { return isProtected; }

void DragonHoard::freeHoard() { isProtected = false; }

void DragonHoard::useItem(playerCharacter *player) {
    const int dragonSize = 6;
    player->increaseGold(dragonSize);
}

bool DragonHoard::playerCanUse() { return this->getStatus(); }
