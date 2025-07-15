#ifndef DRAGONHOARD_H
#define DRAGONHOARD_H

#include "gold.h"

class DragonHoard: public Gold {
    private:
        bool isProtected;

    public: 
        DragonHoard( int x, int y, GameObject* below );
        ~DragonHoard();

        bool getStatus() const;
        void freeHoard();
        void useItem(Playercharacter *player) override;
        bool playerCanUse() const override;
}

#endif
