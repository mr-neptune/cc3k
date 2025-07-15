#include "enemyActivityManager.h"
#include "index.h"

void EnemyActivityManager::moveAllEnemies() {
    size_t rowNum = gsm->getRowNum();
    size_t colNum = gsm->getColNum();
    vector<EnemyCharacter*> enemies;

    // find all ememies line by line
    for (size_t i = 0; i < rowNum; i++) {
        for (size_t j = 0; j < colNum; j++) {
            if (gsm->getObjectAt(i, j)->getType() == Enemy) {
                EnemyCharacter *e = dynamic_cast<EnemyCharacter*>(gsm->getObjectAt(i, j));
                enemies.emplace_back(e);
            }
        }
    }

    // all enemies action
    for (auto it = enemies.begin(); it != enemies.end(); ++it) {
        EnemyCharacter *e = *it;
        e->action();
    }
}
