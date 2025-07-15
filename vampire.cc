#include "vampire.h"
#include <cmath>
#include <climits>

Vampire::Vampire(int x, int y, GameObject *below)
    : PlayerCharacter(x, y, below)
{
    maxHP = INT_MAX;
    curHP = 50;
    atk = 25;
    def = 25;
    healthRegenerate = 5;
    potionMagnification = 1;
    race = Race::Vampire;
}

Vampire::~Vampire() {}

bool Vampire::attack(EnemyCharacter *enemy) {
    bool successfulHit = enemy->isAttackedBy(this);
    if (successfulHit) {
        int newHP = this->getCurHP() + this->getHealthReg();
        this->setHealth(newHP);
    }
    return successfulHit;
}

bool Vampire::isAttackedBy(EnemyCharacter *enemy) {
    double damage = (100.00 / (100.00 + this->getDef())) * enemy->getAtk();
    int realDamage = (int)ceil(damage);

    int newHP = this->getCurHP()  - realDamage;
    this->setHealth(newHP);
    if(!this->isAlive()) {
        this->die();
    }
}

