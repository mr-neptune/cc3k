#ifndef DROPHP_H
#define DROPHP_H

#include "permenantPotion.h"

class DropHP: public PermenantPotion {
    public:
        DropHP (int x, int y, GameObject *below);
        ~DropHP ();
        void useItem(PlayerCharacter *player) override;
};

#endif
