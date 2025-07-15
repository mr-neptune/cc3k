#ifndef ENEMYACTIVITYMANAGER_H
#define ENEMYACTIVITYMANAGER_H
#include "activityManager.h"

class EnemyActivityManager : ActivityManager {
    public:
        void moveAllEnemies();
        
        EnemyActivityManager(GameStateManager *gsm) : ActivityManager{gsm} {}

};

#endif
