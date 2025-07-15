#ifndef FLOOR_H
#define FLOOR_H
#include <vector>
#include <map>
#include <string>
#include "index.h"
#include "gameObject.h"

class Floor {
    size_t numRows;
    size_t numCols;
    GameObject ***floor;    // 2D array of pointers to GameObject object

    public:
        Floor(size_t numRows, size_t numCols);

        // set cell (x, y) to given object pointer
        void setCell(size_t x, size_t y, GameObject *object); 

        // change cell (x, y) to given obj ptr, with its cellbelow field being original game obj at that position
        void putObjectAbove(size_t x, size_t y, GameObject *object); 

        GameObject *getCell(size_t x, size_t y) const;

        // free all game object stored in the floor
        void clearFloor();

        size_t getNumRows() const {return numRows;}
        size_t getNumCols() const {return numCols;}

        ~Floor();
};

#endif
