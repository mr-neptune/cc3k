#include "small.h"

Small::Small(int x, int y, GameObject *below) : Gold(x, y, below) {}

Small::~Small() {}

void Small::useItem(playerCharacter *player) {
    const int smallSize = 1;
    player->increaseGold(smallSize);
}

bool Small::playerCanUse() { return true; }
