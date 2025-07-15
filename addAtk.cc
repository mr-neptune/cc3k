#include "addAtk.h"

AddATK::AddATK(int x, int y, GameObject *below) : TempPotion(x, y, below) {}

AddATK::~AddATK() {}

void AddATK::useItem(PlayerCharacter *player) {
    player = new AttackDecorator(player, 5);
}
