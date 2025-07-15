#include "addHP.h"
#include <cmath>

AddHP::AddHP(int x, int y, GameObject *below) : TempPotion(x, y, below) {}

AddHP::~AddHP() {}

void AddHP::useItem(PlayerCharacter *player) {
    player->setHealth(player->getCurHP() + ceil(10 * player->getPotionMag()));
}
