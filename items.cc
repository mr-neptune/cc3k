#include "items.h"

// constructor
Items::Items(char display, int x, int y, GameObject* below) :
    Entity(display, x, y, below) {}

//destructor
Items::~Items() {}
