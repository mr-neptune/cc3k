#include "drow.h"
#include <cmath>

Drow::Drow(int x, int y, GameObject *below)
    : PlayerCharacter(x, y, below)
{
    maxHP = 150;
    curHP = 150;
    atk = 25;
    def = 15;
    healthRegenerate = 0;
    potionMagnification = 1.5;
    race = Race::Drow;
}

Drow::~Drow() {}

bool Drow::attack(EnemyCharacter *enemy) {
    bool successfulHit = enemy->isAttackedBy(this);
    return successfulHit;
}

bool Drow::isAttackedBy(EnemyCharacter *enemy) {
    double damage = (100.00 / (100.00 + this->getDef())) * enemy->getAtk();
    int realDamage = (int)ceil(damage);

    int newHP = this->getCurHP()  - realDamage;
    this->setHealth(newHP);
    if (!this->isAlive()) {
        this->die();
    }
}
