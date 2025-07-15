#ifndef PLAYERCHARACTERDECORATOR_H
#define PLAYERCHARACTERDECORATOR_H

#include "PlayerCharacter.h"

class PlayerCharacterDecorator : public PlayerCharacter {
protected:
    PlayerCharacter* basePlayer;

public:
    PlayerCharacterDecorator(PlayerCharacter* player);
    virtual ~PlayerCharacterDecorator();

    PlayerCharacter* getBase() override;

    int getAtk() const override;
    int getDef() const override;

    // Other methods can just call the base player's methods
    /*
    void attack(EnemyCharacter &enemy) override;
    void isAttackedBy(EnemyCharacter &enemy) override;
    int getGold() const override;
    void setGold(int increase) override;
    void pickupGold(Gold &gold) override;
    void moveTo(int x, int y) override;
    void die() override;
    */
};

#endif

