#ifndef ADDDEF_H
#define ADDDEF_H

#include "tempPotion.h"

class AddDEF: public TempPotion {
    public:
        AddDEF (int x, int y, GameObject *below);
        ~AddDEF ();
        void useItem(PlayerCharacter *player) override;

};

#endif
