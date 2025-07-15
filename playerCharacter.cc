#include "playerCharacter.h"

// ctor
PlayerCharacter::PlayerCharacter( int x, int y, GameObject* below )
    : Character( '@', x, y, below)
{
    gold = 0;
    type = ObjectType::Player;
}

// dtor
PlayerCharacter::~PlayerCharacter() {}


// virtual
PlayerCharacter *PlayerCHaracter::getBase() {
    return this;
}

bool PlayerCharacter::attack( EnemyCharacter &enemy ) {
    return enemy.isAttackedBy(*this);
}

bool PlayerCharacter::isAttackedBy( EnemyCharacter & enemy ) {
    return true;
}


// common method
int PlayerCharacter::getGold() { return gold; }

void PlayerCharacter::increaseGold( int increase ) { gold += increase; }

void PlayerCharacter::setGold( int newGold ) { gold = newGold; }

void PlayerCharacter::pickupGold( Gold *gold ) {
    if (gold->playerCanUse()) {
        gold->useItem(this);
    }
}

void PlayerCharacter::usePotion( Potion *p ) {
    p->useItem(this);
    if (!this->isAlive()) {
        this->die();
    }
}


// inherited pure virtual methods becomes common
// what if player don't move and instead attack? not sure about this one...
bool PlayerCharacter::playerCanAccess() { return false; }

bool PlayerCharacter::enemyCanAccess() { return false; }


// assume that player have access to (x, y)
void PlayerCharacter::moveTo( int x, int y ) {
    // the coordinate of the previous position
    int oldX = this->getXCoor();
    int oldY = this->getYCoor();

    // relink the object below it to the floor grid
    state.setObjectAt(oldX, oldY, this->getBelow);

    // the target object that the player is about to step on
    GameObject *targetObject = state.getObjectAt(x,y);

    if (targetObject->getType() == ObjectType::Gold) {   // step on GOLD
        if (targetObject->playerCanUse()) {
            // set the player's below to the target position's below,
            // because we know there must be a object below the target
            this->setBelow(targetObject->getBelow());

            // pick up the gold
            this->pickupGold(targetObject);

            // disconnect target object with its base and destroy itself only
            targetObject->selfDestruct();
        } else {
            this->setBelow(targetObject);
        }
    } else {                                             // step on TILES
        this->setBelow(targetObject);    
    }

    // finally update the coordinates.
    this->setXCoor(x);
    this->setYCoor(y);
}

// not finished, need to see the implementation of GameStateManager
void PlayerCharacter::die() {
    state.endGame();
}
