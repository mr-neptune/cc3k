#include "playerActivityManager.h"

void PlayerActivityManager::setRace(Race r) {
    gsm->createPlayer(r);
    gsm->addActionMsg("Race set to " + r);
}

vector<size_t> locAfterMove(size_t x, size_t y, Direction d) {
    vector<size_t> loc {x, y};

    switch(d) {
        case North:
            loc[1] -= 1;
            break;
        case South:
            loc[1] += 1;
            break;
        case East:
            loc[0] += 1;
            break;
        case West:
            loc[0] -= 1;
            break;
        case NorthEast:
            loc[1] -= 1;
            loc[0] += 1;
            break;
        case SouthEast:
            loc[1] += 1;
            loc[0] += 1;
            break;
        case NorthWest:
            loc[1] -= 1;
            loc[0] -= 1;
            break;
        case SouthWest:
            loc[1] += 1;
            loc[0] -= 1;
            break;
    }
    return loc;
}

void PlayerActivityManager::playerMove(Direction d) {
    size_t destX = gsm->getPlayerX();
    size_t destY = gsm->getPlayerY();

    // find where the player will be moving to
    vector<size_t> newLoc = locAfterMove(destX, destY, d);
    destX = newLoc[0];
    destY = newLoc[1];

    // only move if destination is valid
    if (gsm->canMoveHere(destX, destY, gsm->getFloorPlayer())) {
        gsm->moveCharacterTo(destX, destY, gsm->getFloorPlayer());
    }
}

void PlayerActivityManager::playerAttack(Direction d) {
    size_t destX = gsm->getPlayerX();
    size_t destY = gsm->getPlayerY();

    // find where the player will be attacking
    vector<size_t> newLoc = locAfterMove(destX, destY, d);
    destX = newLoc[0];
    destY = newLoc[1];

    // return if dest is not in the floor
    if (destX < 0 || destY < 0 || destX >= gsm->getRowNum() || destY >= gsm->getColNum()) {return;}

    // if dest is enemy, attack it
    if (gsm->getObjectAt(destX, destY)->getType() == Enemy) {
        EnemyCharacter *e = dynamic_cast<EnemyCharacter*>(gsm->getObjectAt(destX, destY));
        gsm->characterAttack(gsm->getFloorPlayer(), e);
    }
}

void PlayerActivityManager::usePotion(Direction d) {
    size_t destX = gsm->getPlayerX();
    size_t destY = gsm->getPlayerY();

    // find where the potion is located
    vector<size_t> newLoc = locAfterMove(destX, destY, d);
    destX = newLoc[0];
    destY = newLoc[1];

    // return if dest is not in the floor
    if (destX < 0 || destY < 0 || destX >= gsm->getRowNum() || destY >= gsm->getColNum()) {return;}

    // if dest is potion, use it
    if (gsm->getObjectAt(destX, destY)->getType() == Potion) {
        Items *item = dynamic_cast<Items*>(gsm->getObjectAt(destX, destY));
        gsm->applyItemEffect(item);
    }
}

void PlayerActivityManager::endGame() {
    gsm->endGame();
}
