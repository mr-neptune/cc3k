#ifndef TEMPPOTION_H
#define TEMPPOTION_H

#include "potion.h"

class TempPotion: public Potion {
    public:
        TempPotion (int x, int y, GameObject *below);
        virtual ~TempPotion ();

        // pure virtual
        virtual void useItem( PlayerCharacter *player ) = 0;
};

#endif
