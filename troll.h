#ifndef TROLL_H
#define TROLL_H

#include "playerCharacter.h"
#include "enemyCharacter.h"
#include <memory>

class Troll : public PlayerCharacter {
    public:
        Troll(int x, int y, GameObject *below);
        ~Troll() override;

        bool attack(EnemyCharacter *enemy) override;
        bool isAttackedBy(EnemyCharacter *enemy) override;
};

#endif
