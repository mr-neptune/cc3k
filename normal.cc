#include "normal.h"

Normal::Normal(int x, int y, GameObject *below) : Gold(x, y, below) {}

Normal::~Normal() {}

void Normal::useItem(playerCharacter *player) {
    const int normalSize = 2;
    player->increaseGold(normalSize);
}

bool Normal::playerCanUse() { return true; }
