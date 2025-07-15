#ifndef POTION_H
#define POTION_H

#include "items.h"
#include "playerCharacter.h"

class Potion: public Items {
    public:
        virtual Potion (int x, int y, GameObject* below);
        virtual ~Potion();

        // pure virtual 
        virtual void useItem( PlayerCharacter *player ) = 0;

        // common
        bool playerCanUse() const;
        bool playerCanAccess() const;
        bool enemyCanAccess() const;
        void selfDestruct();
}

#endif
