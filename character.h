#ifndef CHARACTER_H
#define CHARACTER_H

#include "entity.h"
#include "gameStateManager.h"

class Character: public Entity{
    private:
        int atk;
        int def;
        int maxHP;
        int curHP;
        double potionMagnification;
        int healthRegenerate;

    public:
        Character( char display, int x, int y, GameObject* below );
        virtual ~Character();

        // pure virtual
        virtual bool playerCanAccess() const = 0;
        virtual bool enemyCanAccess() const = 0;
        virtual void moveTo( int x, int y ) = 0;
        virtual void die() = 0;


        // common methods
        bool isAlive() const;
        void setHealth( int health );

        // getAtk and getDef are virtual because we need to implement
        // potion decorators later on, we need to override them
        virtual int getAtk() const;
        virtual int getDef() const;

        // common methods
        int getCurHP() const;
        int getMaxHP() const;
        double getPotionMag() const;
        int getHealthReg() const;

        void setAtk( int atkStat );
        void setDef( int defStat );
        void setPotionMag( int potionMag );
        void setHealthReg( int healthReg );
};

#endif
