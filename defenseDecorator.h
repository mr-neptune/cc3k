#ifndef DEFENSEDECORATOR_H
#define DEFENSEDECORATOR_H

#include <cmath>
#include "PlayerCharacterDecorator.h"

class DefenseDecorator : public PlayerCharacterDecorator {
    private:
        int change;
    public:
        DefenseDecorator(PlayerCharacter* player, int change)
            : PlayerCharacterDecorator(player), change{change} {}

        int getDef() const override {
            return basePlayer->getDef() + ceil(change * basePlayer->getPotionMag()); // change def
        }
};

#endif
