#ifndef GOBLIN_H
#define GOBLIN_H

#include "playerCharacter.h"
#include "enemyCharacter.h"
#include <memory>

class Goblin: public PlayerCharacter {
    public:
        Goblin(int x, int y, GameObject *below);
        ~Goblin() override;

        bool attack(EnemyCharacter *enemy) override;
        bool isAttackedBy(EnemyCharacter *enemy) override;
};

#endif
