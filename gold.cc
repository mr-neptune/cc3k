#include "gold.h"

Gold::Gold( int x, int y, GameObject* below ) : Items('G', x, y, below) {}

Gold::~Gold() {}

bool Gold::playerCanAccess() { return true; }

bool Gold::enemyCanAccess() { return false; }

void Gold::selfDestruct() {
    this->setBelow(nullptr);
    delete this;
}
