#ifndef SHADE_H
#define SHADE_H

#include "playerCharacter.h"
#include "enemyCharacter.h"
#include <memory>

class Shade: public PlayerCharacter {
    public:
        Shade(int x, int y, GameObject* below);
        ~Shade() override;

        bool attack(EnemyCharacter *enemy) override;
        bool isAttackedBy(EnemyCharacter *enemy) override;
};

#endif
