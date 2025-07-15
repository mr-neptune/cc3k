#ifndef MERCHANTHOARD_H
#define MERCHANTHOARD_H

#include "gold.h"

class MerchantHoard: public Gold {
    public:
        MerchantHoard( int x, int y, GameObject* below );
        ~MerchantHoard();

        void useItem(Playercharacter *player) override;
        bool playerCanUse() const override;
}

#endif
