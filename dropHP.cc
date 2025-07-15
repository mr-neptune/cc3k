#include "dropHP.h"
#include <cmath>

DropHP::DropHP(int x, int y, GameObject *below) : TempPotion(x, y, below) {}

DropHP::~DropHP() {}

void DropHP::useItem(PlayerCharacter *player) {
    player->setHealth(player->getCurHP() - ceil(10 * player->getPotionMag()));
}
