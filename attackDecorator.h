#ifndef ATTACKDECORATOR_H
#define ATTACKDECORATOR_H

#include <cmath>
#include "PlayerCharacterDecorator.h"

class AttackDecorator: public PlayerCharacterDecorator {
    private:
        int change;
    public:
        AttackDecorator(PlayerCharacter* player, int change)
            : PlayerCharacterDecorator(player), change{change} {}

        int getAtk() const override {
            return basePlayer->getAtk() + ceil(change * this->getBase()->getPotionMag()); // change attack by need amount
        }
};

#endif
