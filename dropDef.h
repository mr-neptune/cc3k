#ifndef DROPDEF_H
#define DROPDEF_H

#include "tempPotion.h"

class DropDEF: public TempPotion {
    public:
        DropDEF (int x, int y, GameObject *below);
        ~DropDEF ();
        void useItem(PlayerCharacter *player) override;

};

#endif
