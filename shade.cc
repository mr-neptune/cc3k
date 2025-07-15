#include "shade.h"
#include <cmath>

Shade::Shade(int x, int y, GameObject *below)
    : PlayerCharacter(x, y, below)
{
    maxHP = 125;
    curHP = 125;
    atk = 25;
    def = 25;
    healthRegenerate = 0;
    potionMagnification = 1;
    race = Race::Shade;
}

Shade::~Shade() {}

bool Shade::attack(EnemyCharacter *enemy) {
    bool successfulHit = enemy->isAttackedBy(this);
    return successfulHit;
}

bool Shade::isAttackedBy(EnemyCharacter *enemy) {
    double damage = (100.00 / (100.00 + this->getDef())) * enemy->getAtk();
    int realDamage = (int)ceil(damage);

    int newHP = this->getCurHP()  - realDamage;
    this->setHealth(newHP);
    if(!this->isAlive()) {
        this->die();
    }
}

