#ifndef PLAYERACTIVITYMANAGER_H
#define PLAYERACTIVITYMANAGER_H
#include "activityManager.h"

class PlayerActivityManager : public ActivityManager {
    public:
        void setRace(Race r);
        void playerMove(Direction d);
        void playerAttack(Direction d);
        void usePotion(Direction d);
        void endGame();

        PlayerActivityManager(GameStateManager *gsm) : ActivityManager{gsm} {}
};

#endif
