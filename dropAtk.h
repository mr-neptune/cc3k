#ifndef DROPATK_H
#define DROPATK_H

#include "tempPotion.h"

class DropATK: public TempPotion {
    public:
        DropATK (int x, int y, GameObject *below);
        ~DropATK ();
        void useItem(PlayerCharacter *player) override;

};

#endif
