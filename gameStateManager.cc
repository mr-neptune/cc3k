#include "gameStateManager.h"
#include "objectCreater.h"

bool GameStateManager::gameOver() const {
    return gameEnded;
}

PlayerCharacter* GameStateManager::getFloorPlayer() const {
    GameObject *p = floor->getCell(basePlayer->getXCoor(), basePlayer->getYCoor());
    return dynamic_cast<PlayerCharacter*>(p);
}

GameObject *GameStateManager::getObjectAt(size_t x, size_t y) const {
    return floor->getCell(x, y);
}

// put GameObject in (x, y) to the cellBelow field, then replace object at (x, y) to c, leaving old cellBelow field in its orig position
void GameStateManager::moveCharacterTo(size_t x, size_t y, Character *c) {
    // GameObject *below = c->getBelow();
    // floor->setCell(c->getX(), c->getY(), below);
    // floor->putObjectAbove(x, y, c);
    if (canMoveHere(x, y, c)) {
        c->moveTo(x, y);
    }
}

void GameStateManager::characterAttack(Character *attacker, Character *defender) {
    attacker->attack(defender);
}

void GameStateManager::applyItemEffect(Items *item) {
    item->useItem(getFloorPlayer());
}

bool GameStateManager::canMoveHere(size_t x, size_t y, Character *c) const {
    if (x < 0 || y < 0 || x >= getRowNum() || y >= getColNum()) {return false;}
    return (floor->getCell(x, y))->objectCanAccess(c);
}

bool GameStateManager::canMove(Character *c) const {
    return c->canMove();
}


void GameStateManager::createPlayer(Race race) {
    basePlayer = ObjectCreater::newPlayer(race);
}

void GameStateManager::initNextFloor() {
    // copy the base player with copy ctor
    PlayerCharacter *newPC = ObjectCreater::newPlayer(basePlayer);

    // clear the current floor, include the old player object that is in it
    floor->clearFloor();

    // change player field to the copied player
    basePlayer = newPC;

    // generate next floor (excluding player)
    fg->generateFloor();

    // get new player position and put it there
    vector<int> playerPos = fg->getPlayerLoc();
    floor->putObjectAbove(playerPos[0], playerPos[1], basePlayer);
}


void GameStateManager::addActionMsg(string msg) {
    actionMsg.emplace_back(msg);
}

void GameStateManager::removeActionMsg(string msg) {
    for (auto it = actionMsg.begin(); it != actionMsg.end(); ++it) {
        if (*it == msg) {
            actionMsg.erase(it);
            break;
        }
    }
}

void GameStateManager::clearActionMsg() {
    actionMsg = vector<string>{};
}

vector<string> GameStateManager::getActionMsg() const {
    return actionMsg;
}
