#include "floor.h"

Floor::Floor(size_t numRows, size_t numCols) : numRows{numRows}, numCols{numCols} {
    // initialize the 2D array to all nullptr
    floor = new GameObject**[numRows];
    for (size_t i = 0; i < numRows; i++) {
        floor[i] = new GameObject*[numCols];
        for (size_t j = 0; j < numCols; j++) {
            floor[i][j] = nullptr;
        }
    }
}

// set floor[x][y] = object, without freeing previous object stored there
void Floor::setCell(size_t x, size_t y, GameObject *object) {
    floor[x][y] = object;
}

void Floor::clearFloor() {
    for (size_t i = 0; i < numRows; i++) {
        for (size_t j = 0; j < numCols; j++) {
            delete floor[i][j];
            floor[i][j] = nullptr;
        }
    }
}

// change cell (x, y) to given obj ptr, with its cell below field being original game obj at that position
void Floor::putObjectAbove(size_t x, size_t y, GameObject *object) {
    object->setXCoor(x);
    object->setYCoor(y);
    object->setBelow(floor[x][y]);
    floor[x][y] = object;
}

GameObject *Floor::getCell(size_t x, size_t y) const{
    return floor[x][y];
}

// destructor: frees all elements in floor, then free floor
Floor::~Floor() {
    clearFloor();    // delete each cell
    for (size_t i = 0; i < numRows; i++) {
        delete[] floor[i];    // delete each row
    }
    delete[] floor;    // delete the 2D matrix
}
