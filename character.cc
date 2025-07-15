#include "character.h"

// constructor
Character::Character( char display, int x, int y, GameObject* below )
    : Entity(display, x, y, below) {}

// destructor
Character::~Character() {}


// no implementation for pure virtual methods:
//      playerCanAccess()
//      enemyCanAccess()
//      moveTo(x,y)
//      die()


// common methods
bool Character::isAlive() { return curHP > 0; }

void Character::setHealth( int health ) {
    if (health > 0 && health <= maxHP) {
        curHP = health;
    } else if (health <= 0) {
        curHP = 0;
    } else {
        curHP = maxHP;
    }
}

// getters
int Character::getAtk() const { return atk; } // default

int Character::getDef() const { return def; }  // default

int Character::getCurHP() const { return curHP; }

int Character::getMaxHP() const { return maxHP; }

double Character::getPotionMag() const { return potionMagnification; }

int Character::getHealthReg() const { return healthRegenerate; }


// setters
void Character::setAtk( int atkStat ) { atk = atkStat; }

void Character::setDef( int defStat ) { def = defStat; }

void Character::setPotionMag( int potionMag ) { potionMagnification = potionMag; }

void Character::setHealthReg( int healthReg ) { healthRegenerate = healthReg; }
