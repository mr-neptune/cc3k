#ifndef GOLD_H
#define GOLD_H

#include "items.h"
#include "gameStateManager.h"
#include "playerCharacter.h"
#include "enemyCharacter.h"

class Gold: public Items {
    public:
        Gold ( int x, int y, GameObject* below );
        virtual ~Gold();

        // pure virtual
        virtual void useItem( PlayerCharacter *player ) = 0;
        virtual bool playerCanUse() = 0;

        bool playerCanAccess() const;
        bool enemyCanAccess() const;
        void selfDestruct();
}

#endif
