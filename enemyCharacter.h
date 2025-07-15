#ifndef ENEMYCHARACTER_H
#define ENEMYCHARACTER_H

#include "character.h"
#include "playerCharacter.h"
#include "gold.h"

class EnemyCharacter: public Character {
    private:
        static bool isHostile;
        ObjectName enemyRace;
    
    public:
        EnemyCharacter( char display, int x, int y );
        virtual ~EnemyCharacter();

        // common
        bool isHostile() const;

        // virtual
        virtual bool attack( PlayerCharacter &player );
        virtual bool isAttackedBy( PlayerCharacter &player );
        virtual void dropGold( PlayerCharacter &player );
        virtual void die( PlayerCharacter &player );
        virtual void moveTo( int x, int y );

        // inherited pure virtual methods becomes common
        bool playerCanAccess();
        bool enemyCanAccess();

}

#endif
