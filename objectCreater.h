#ifndef OBJECTCREATER_H
#define OBJECTCREATER_H
#include "floor.h"
#include "playerCharacter.h"

class ObjectCreater {
    
    public:
        // Not completed
        // initialize new GameObject based on ObjectName, put it in floor[x][y] (or replace floor[x][y] with it)
        static void newObjectAt(int x, int y, Floor* floor, ObjectName obj);

        // initialize a player of given race on heap and return ptr to it
        static PlayerCharacter *newPlayer(Race race);

        // given a playercharacter object, copy a same one on heap and return ptr to the new one
        static PlayerCharacter *newPlayer(PlayerCharacter *player);
};

#endif
