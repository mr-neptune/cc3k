#include "troll.h"
#include <cmath>

Troll::Troll(int x, int y, GameObject *below)
    : PlayerCharacter(x, y, below)
{
    maxHP = 120;
    curHP = 120;
    atk = 25;
    def = 15;
    healthRegenerate = 5;
    potionMagnification = 1;
    race = Race::Troll;
}

Troll::~Troll() {}

bool Troll::attack(EnemyCharacter *enemy) {
    bool successfulHit = enemy->isAttackedBy(this);
    int newHP = this->getCurHP() + this->getHealthReg(); // regain 5 HP
    this->setHealth(newHP);
    return successfulHit;
}

bool Troll::isAttackedBy(EnemyCharacter *enemy) {
    double damage = (100.00 / (100.00 + this->getDef())) * enemy->getAtk();
    int realDamage = (int)ceil(damage);

    int newHP = this->getCurHP()  - realDamage;
    this->setHealth(newHP);
    if(!this->isAlive()) {
        this->die();
    } else {    // regain 5 HP
        newHP += this->getHealthReg();
        this->setHealth(newHP);
    }
}
