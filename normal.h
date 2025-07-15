#ifndef NORMAL_H
#define NORMAL_H

#include "gold.h"

class Normal: public Gold {
    public:        
        Normal( int x, int y, GameObject* below );
        ~Normal();

        void useItem(Playercharacter *player) override;
        bool playerCanUse() const override;
}

#endif
