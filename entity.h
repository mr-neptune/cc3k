#ifndef ENTITY_H
#define ENTITY_H

#include "gameObject.h"
#include "gameStateManager.h"
#include "cell.h"

class Entity : public GameObject {
    protected:
        GameStateManager &state;
        GameObject *objectbelow;

    public:
        Entity(char display, int x, int y, GameObject *below) : GameObject(display, x, y), objectbelow{below} {}
        virtual ~Entity() { delete objectbelow; }

        // pure virtual
        virtual bool playerCanAccess() const = 0;
        virtual bool enemyCanAccess() const = 0;
        GameObject *getBelow() { return objectbelow; }
        void *setBelow( GameObject* newBelow ) { objectbelow = newBelow; }
};

#endif
