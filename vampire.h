#ifndef VAMPIRE_H
#define VAMPIRE_H

#include "playerCharacter.h"
#include "enemyCharacter.h"
#include <memory>

class Vampire: public PlayerCharacter {
    public:
        Vampire(int x, int y, GameObject *below);
        ~Vampire() override;

        bool attack(EnemyCharacter *enemy) override;
        bool isAttackedBy(EnemyCharacter *enemy) override;
};

#endif
