#include "potion.h"

Potion::Potion(int x, int y, GameObject* below) : Items("P", x, y, below) {}

Potion::~Potion() {}

bool Potion::playerCanUse() { return true; }

bool Potion::playerCanAccess() { return false; }

bool Potion::enemyCanAccess() { return false; }

void Potion::selfDestruct() {
    this->setBelow(nullptr);
    delete this;
}

