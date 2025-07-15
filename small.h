#ifndef SMALL_H
#define SMALL_H

#include "gold.h"

class Small: public Gold {
    public:
        Small( int x, int y, GameObject* below );
        ~Small();

        void useItem(Playercharacter *player) override;
        bool playerCanUse() const override;
}

#endif
