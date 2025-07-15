#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "index.h"

class GameObject {
    protected:
        int chamber_num;
        bool is_outside_chamber;
        char display;
        int x, y;
        const ObjectType type;

    public:
        GameObject(char display, int x, int y);
        virtual ~GameObject();

        // pure virtual
        virtual bool playerCanAccess() const = 0;
        virtual bool enemyCanAccess() const = 0;

        // common methods
        ObjectType getType() const;
        char getDisplay() const;
        int getXCoor() const;
        int getYCoor() const;
        void setXCoor( int xcoor );
        void setYCoor( int ycoor );
};

#endif

