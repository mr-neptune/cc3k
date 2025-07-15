#include "addDef.h"

AddDEF::AddDEF(int x, int y, GameObject *below) : TempPotion(x, y, below) {}

AddDEF::~AddDEF() {}

void AddDEF::useItem(PlayerCharacter *player) {
    player = new DefenseDecorator(player, 5);
}
