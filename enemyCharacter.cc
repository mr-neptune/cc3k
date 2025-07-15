#include "enemyCharacter.h"
#include <cmath>

// ctor
EnemyCharacter::EnemyCharacter( char display, int x, int y )
    : Character( display, x, y)
{
    type = ObjectType::Enemy;
}

// dtor
EnemyCharacter::~EnemyCharacter() {}


// common identifier
bool EnemyCharacter::isHostile() { return isHostile; }


// virtual
bool EnemyCharacter::attack( PlayerCharacter &player ) {
    return player.isAttackedBy(*this);
}

bool EnemyCharacter::isAttackedBy( PlayerCharacter &player ) {
    return true;
}

// this is the default dropGold method for enemies except for merchant, human, and dragon
void EnemyCharacter::dropGold( PlayerCharacter &player ) {
    int random = rand() % 10 + 1;

    if (random <= 3) {
        Gold *normal = new Normal(this->getXCoor(), this->getYCoor);
        normal->useItem(player);
        delete normal;
    } else {
        Gold *small = new Small(this->getXCoor(). this->getYCoor());
        small->useItem(player);
        delete small;
    }
}

// this is the defulat die method for enemies except for merchant, human, and dragon
void EnemyCharacter::die( PlayerCharacter &player ) {
    int x = this->getXCoor();
    int y = this->getYCoor();
    this->dropGold(player);
    // Cell newTile = new Tile(x, y);
    // state.setObjectAt(x, y, new Tile(x, y))
}

// this is the defualt moveTo method for enemies except for dragon
void EnemyCharacter::moveTo( int x, int y ) {
    this->setXCoor(x);
    this->setYCoor(y);
}

// inherited pure virtual methods becomes common
bool EnemyCharacter::playerCanAccess() { return false; }

bool EnemyCharacter::enemyCanAccess() { return false; }
