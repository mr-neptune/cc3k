#ifndef ITEMS_H
#define ITEMS_H

#include "entity.h"
#include "gameStateManager.h"
#include "playerCharacter.h"

class Items: public Entity {
    public:
        Items( char display, int x, int y, GameObject *below );
        virtual ~Items();

        // pure virtual 
        virtual void useItem( PlayerCharacter *player ) = 0;
        virtual bool playerCanAccess() = 0;
        virtual bool playerCanUse() = 0;
        virtual bool enemyCanAccess() = 0;
        virtual void selfDestruct() = 0;
}

#endif
