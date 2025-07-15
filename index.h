#ifndef INDEX_H
#define INDEX_H
#include <vector>
#include <map>
using namespace std;

// all player races
enum Race {Shade, Drow, Vampire, Troll, Goblin};

// all general types of game objects
enum ObjectType {Enemy, Potion, Gold, Landscape, Stair, Player};

// all directions
enum Direction {North, South, East, West, NorthEast, NorthWest, SouthEast, SouthWest};

// all specific subtypes of game objects
enum ObjectName {
    Human, Dwarf, Elf, Orcs, Merchant, Dragon, Halfling,    // enemy
    RH, BA, BD, PH, WA, WD,    // potion
    Small, Normal, Merchant_hoard, Dragon_hoard,    // gold
    Bridge, Tiles, Door, Vwall, Hwall, Void,    // landscape
    StairObject,    // stair
    PlayerObject    // player
    };


class Index {

    // map containing list of ObjectNames that belongs to the ObjectType
    static const map<ObjectType, vector<ObjectName>> OBJECT_TYPE_DICT;

    // map that maps each char (key) with their ObjectName (value)
    static const map<char, ObjectName> CHAR_DICT;

    public:
        static bool isType(char c, ObjectType type);    // checks if a char represent the given type of gameobject
        static bool isType(ObjectName subtype, ObjectType type);
        static ObjectName charToObjectName(char c);    // convert character to corresponding ObjectName (e.g. '#'->bridge)
};

#endif
