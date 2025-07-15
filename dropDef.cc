#include "dropDef.h"

DropDEF::DropDEF(int x, int y, GameObject *below) : TempPotion(x, y, below) {}

DropDEF::~DropDEF() {}

void DropDEF::useItem(PlayerCharacter *player) {
    player = new DefenseDecorator(player, -5);
}
