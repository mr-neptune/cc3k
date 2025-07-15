#include "goblin.h"
#include <cmath>

Goblin::Goblin(int x, int y, GameObject *below)
    : PlayerCharacter(x, y, below)
{
    maxHP = 110;
    curHP = 110;
    atk = 15;
    def = 20;
    healthRegenerate = 0;
    potionMagnification = 1;
    race = Race::Goblin;
}

Goblin::~Goblin() {}

bool Goblin::attack(EnemyCharacter *enemy) {
    bool successfulHit = enemy->isAttackedBy(this);
    if (!enemy->isAlive()) {
        this->setGold(5);
    }
    return successfulHit;
}

bool Goblin::isAttackedBy(EnemyCharacter *enemy) {
    double damage = (100.00 / (100.00 + this->getDef())) * enemy->getAtk();
    int realDamage = (int)ceil(damage);

    int newHP = this->getCurHP()  - realDamage;
    this->setHealth(newHP);
    if(!this->isAlive()) {
        this->die();
    }
}

