#include "dropAtk.h"

DropATK::DropATK(int x, int y, GameObject *below) : TempPotion(x, y, below) {}

DropATK::~DropATK() {}

void DropATK::useItem(PlayerCharacter *player) {
    player = new AttackDecorator(player, -5);
}
