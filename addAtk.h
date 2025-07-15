#ifndef ADDATK_H
#define ADDATK_H

#include "tempPotion.h"

class AddATK: public TempPotion {
    public:
        AddATK (int x, int y, GameObject *below);
        ~AddATK ();
        void useItem(PlayerCharacter *player) override;

};

#endif
