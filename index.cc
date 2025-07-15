#include "index.h"

const map<ObjectType, vector<ObjectName>> Index::OBJECT_TYPE_DICT = {
    {Enemy, {Human, Dwarf, Elf, Orcs, Merchant, Dragon, Halfling}},
    {Potion, {RH, BA, BD, PH, WA, WD}},
    {Gold, {Small, Normal, Merchant_hoard, Dragon_hoard}},
    {Landscape, {Bridge, Tiles, Door, Vwall, Hwall, Void}},
    {Stair, {StairObject}},
    {Player, {PlayerObject}}
};

const map<char, ObjectName> Index::CHAR_DICT = {
    {'H', Human}, {'W', Dwarf}, {'E', Elf}, {'O', Orcs}, {'M', Merchant}, {'D', Dragon}, {'L', Halfling},
    {'0', RH}, {'1', BA}, {'2', BD}, {'3', PH}, {'4', WA}, {'5', WD},
    {'6', Small}, {'7', Normal}, {'8', Merchant_hoard}, {'9', Dragon_hoard},
    {'#', Bridge}, {'.', Tiles}, {'+', Door}, {'|', Vwall}, {'-', Hwall}, {' ', Void},
    {'\\', StairObject},
    {'@', PlayerObject}
};

ObjectName Index::charToObjectName(char c) {
    return Index::CHAR_DICT.at(c);
}

bool Index::isType(char c, ObjectType type) {
    vector<ObjectName> typeLst = Index::OBJECT_TYPE_DICT.at(type);
    ObjectName cObject = charToObjectName(c);
    // loop through typeLst to find cObject
    for (auto it = typeLst.begin(); it != typeLst.end(); ++it) {
        if (*it == cObject) {
            return true;
        }
    }
    return false;
}

bool Index::isType(ObjectName subtype, ObjectType type) {
    vector<ObjectName> typeLst = Index::OBJECT_TYPE_DICT.at(type);
    // loop through typeLst to find cObject
    for (auto it = typeLst.begin(); it != typeLst.end(); ++it) {
        if (*it == subtype) {
            return true;
        }
    }
    return false;
}
