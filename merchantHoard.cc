#include "merchantHoard.h"

MerchantHoard::MerchantHoard(int x, int y, GameObject *below) : Gold(x, y, below) {}

MerchantHoard::~MerchantHoard() {}

void MerchantHoard::useItem(playerCharacter *player) {
    const int merchantSize = 4;
    player->increaseGold(merchantSize);
}

bool MerchantHoard::playerCanUse() { return true; }
