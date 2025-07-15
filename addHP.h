#ifndef ADDHP_H
#define ADDHP_H

#include "permenantPotion.h"

class AddHP: public PermenantPotion {
    public:
        AddHP (int x, int y, GameObject *below);
        ~AddHP ();
        void useItem(PlayerCharacter *player) override;
};

#endif
