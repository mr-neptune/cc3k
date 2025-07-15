#include "spawnRule.h"
#include <cstdlib>

// stores how many of each SpawnType will be generated
map<ObjectType, int> SpawnRule::generateNum {
    {Player, 1}, {Stair, 1}, {Potion, 10}, {Gold, 10}, {Enemy, 20}
}; 

// weight of each subtype of spawntype will be generated, given the spawntype will be generated
map<ObjectType, map<ObjectName, int>> SpawnRule::spawnWeight {
    {Enemy, {{Human, 4}, {Dwarf, 3}, {Halfling, 5}, {Elf, 2}, {Orcs, 2}, {Merchant, 2}}},
    {Potion, {{RH, 1}, {BA, 1}, {BD, 1}, {PH, 1}, {WA, 1}, {WD, 1}}},
    {Gold, {{Small, 2}, {Normal, 5}, {Dragon_hoard, 1}}},
    {Stair, {{StairObject, 1}}},
    {Player, {{PlayerObject, 1}}}
}; 

vector<ObjectType> SpawnRule::generateTypes() {
    vector<ObjectType> types;
    for (auto const [key, value] : generateNum) {
        types.emplace_back(key);
    }
    return types;
}

int SpawnRule::generateTypeNum(ObjectType type) {
    return generateNum.at(type);
}

map<ObjectName, int> SpawnRule::weightOf(ObjectType type) {
    return spawnWeight.at(type);
}

bool canSpawnHere(const vector<vector<int>> &chamberMap, const vector<vector<ObjectName>> &spawn, ObjectName obj, size_t x, size_t y) {
    if (x < 0 || x >= chamberMap.size() || y < 0 || y >= chamberMap[x].size()) {return false;}
    if (chamberMap[x][y] == 0 || spawn[x][y] != Void) {return false;}
    if (obj == Dragon_hoard) {     // to spawn dragon hoard, must be place to spawn dragon surrounding it
        if (canSpawnHere(chamberMap, spawn, Dragon, x+1, y) ||
            canSpawnHere(chamberMap, spawn, Dragon, x+1, y+1) ||
            canSpawnHere(chamberMap, spawn, Dragon, x+1, y-1) ||
            canSpawnHere(chamberMap, spawn, Dragon, x-1, y) ||
            canSpawnHere(chamberMap, spawn, Dragon, x-1, y+1) ||
            canSpawnHere(chamberMap, spawn, Dragon, x-1, y-1) ||
            canSpawnHere(chamberMap, spawn, Dragon, x, y+1) ||
            canSpawnHere(chamberMap, spawn, Dragon, x, y-1)) {
                return true;
            }
            else {
                return false;
            }
    }
    else if (obj == PlayerObject) {    // player can't be spawn in same chamber as stair
        for (size_t i = 0; i < spawn.size(); i++) {
            for (size_t j = 0; j < spawn[i].size(); j++) {
                if (spawn[i][j] == StairObject && (chamberMap[i][j] == chamberMap[x][y])) {
                    return false;
                }
            }
        }
        return true;
    }
    else if (obj == StairObject) {    // stair can't be spawn in same chamber as player
        for (size_t i = 0; i < spawn.size(); i++) {
            for (size_t j = 0; j < spawn[i].size(); j++) {
                if (spawn[i][j] == PlayerObject && (chamberMap[i][j] == chamberMap[x][y])) {
                    return false;
                }
            }
        }
        return true;
    }
    else {
        return true;
    }
}

// each chamber has equal probability
vector<vector<double>> probabilityByChamber(const vector<vector<int>> &chamberMap, const vector<vector<ObjectName>> &spawn, ObjectName obj) {
    map<int, vector<vector<size_t>>> chamberContents;
    vector<vector<double>> probabilities (chamberMap.size(), vector<double>{});

    for (size_t i = 0; i < chamberMap.size(); i++) {
        probabilities[i] = vector<double>(chamberMap[i].size(), 0);
        for (size_t j = 0; j < chamberMap[i].size(); j++) {
            // if can spawn at (i, j), record its coordinate and chamber number
            if (canSpawnHere(chamberMap, spawn, obj, i, j)) {
                vector<size_t> coordinate{i, j};
                int chamber = chamberMap[i][j];
                if (chamberContents.contains(chamber)) {
                    chamberContents[chamber].push_back(coordinate);
                }
                else {
                    chamberContents[chamber] = vector<vector<size_t>>{};
                    chamberContents[chamber].push_back(coordinate);
                }
            }
        }
    }

    int chamberNum = chamberContents.size();
    for (auto const &[key, value] : chamberContents) {    // for each chamber
        for (auto it = value.begin(); it != value.end(); ++it) {    // for each coordinate
            int x = (*it)[0];
            int y = (*it)[1];
            probabilities[x][y] = 1.0 / (chamberNum * value.size());
        }
    }

    return probabilities;
}

// each grid has equal probability
vector<vector<double>> probabilityByGrid(const vector<vector<int>> &chamberMap, const vector<vector<ObjectName>> &spawn, ObjectName obj) {
    vector<vector<double>> probabilities (chamberMap.size(), vector<double>{});
    vector<vector<size_t>> possibleAddress;

    // record all coordinate can can spawn the object
    for (size_t i = 0; i < chamberMap.size(); i++) {
        probabilities[i] = vector<double>(chamberMap[i].size(), 0);
        for (size_t j = 0; j < chamberMap[i].size(); j++) {
            // if can spawn at (i, j), record its coordinate
            if (canSpawnHere(chamberMap, spawn, obj, i, j)) {
                vector<size_t> coordinate{i, j};
                possibleAddress.push_back(coordinate);
            }
        }
    }

    for (auto it = possibleAddress.begin(); it != possibleAddress.end(); ++it) {    // for each coordinate
        int x = (*it)[0];
        int y = (*it)[1];
        probabilities[x][y] = 1.0 / (possibleAddress.size());
    }
    return probabilities;
}

#include <iostream>
vector<vector<double>> SpawnRule::spawnProbabilityOf(const vector<vector<int>> &chamberMap, const vector<vector<ObjectName>> &spawn, ObjectName obj) {
    return probabilityByChamber(chamberMap, spawn, obj);
}

void SpawnRule::spawnAt(ObjectName obj, size_t x, size_t y, vector<vector<ObjectName>> &spawnTemplate, const vector<vector<int>> &chamberMap) {
    if (obj == Dragon_hoard) {
        spawnTemplate[x][y] = obj;    // spawn the dragon hoard
        vector<vector<size_t>> lst;

        // find place to spawn dragon
        for (size_t i = max((size_t)0, x-1); i <= min(x+1, spawnTemplate.size()); i++) {
            for (size_t j = max((size_t)0, y-1); j <= min(y+1, spawnTemplate[i].size()); j++) {
                if (canSpawnHere(chamberMap, spawnTemplate, Dragon, i, j)) {
                    lst.push_back({i, j});
                }
            }
        }
        vector<size_t> dragonAddress = lst[rand() % (lst.size())];
        spawnTemplate[dragonAddress[0]][dragonAddress[1]] = Dragon;
    }
    else {
        spawnTemplate[x][y] = obj;
    }
}
