#ifndef DROW_H
#define DROW_H

#include "playerCharacter.h"
#include "enemyCharacter.h"
#include <memory>

class Drow : public PlayerCharacter {
    public:
        Drow(int x, int y, GameObject *below);
        ~Drow() override;

        bool attack(EnemyCharacter *enemy) override;
        bool isAttackedBy(EnemyCharacter *enemy) override;
};

#endif
