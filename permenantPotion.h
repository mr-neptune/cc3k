#ifndef PERMENANTPOTION_H
#define PERMENANTPOTION_H

#include "potion.h"

class PermenantPotion: public Potion {
    public:
        PermenantPotion (int x, int y, GameObject* below);
        virtual ~PermenantPotion ();

        // pure virtual
        virtual void useItem( PlayerCharacter* player ) = 0;
};


#endif
