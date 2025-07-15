#ifndef ACTIVITYMANAGER_H
#define ACTIVITYMANAGER_H
#include "gameStateManager.h"

class ActivityManager {
    protected:
        GameStateManager *gsm;

    public:
        ActivityManager(GameStateManager *gsm) : gsm{gsm} {}
        virtual ~ActivityManager() = 0;
};

#endif
