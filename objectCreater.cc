#include "objectCreater.h"

// not complete
// when creating dragon_hoard/dragon, need to look for initialized dragon/dragon_hoard in floor surrounding it and link them
// link the first dragon/dragon_hoard that hasn't been linked by other dragon_hoard/dragon
// access surroundings in order that the floor is filled (i.e. row by row, left to right)
// for all entities, cellbelow field will be whatever that is currently at floor(x, y). Then replace floor(x, y) with the new entity

