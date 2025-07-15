#ifndef PLAYERCHARACTER_H
#define PLAYERCHARACTER_H

#include "character.h"
#include "enemyCharacter.h"
#include "gold.h"

class PlayerCharacter: public Character {
    private:
        int gold;
        Race race;
    
    public:
        PlayerCharacter( int x, int y, GameObject* below );
        virtual ~PlayerCharacter();

        // virtual
        virtual PlayerChacater *getBase();
        virtual bool attack( EnemyCharacter &enemy );
        virtual bool isAttackedBy( EnemyCharacter &enemy );

        // common method
        int getGold() const;
        void increaseGold( int increase );
        void setGold( int newGold );
        void pickupGold( Gold *gold );
        void usePotion( Potion* p );

        // inherited pure virtual methods becomes common
        bool playerCanAccess();
        bool enemyCanAccess();
        void moveTo( int x, int y );
        void die();
}

#endif
