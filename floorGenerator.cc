#include "floorGenerator.h"
#include "objectCreater.h"
#include <iostream>
#include <cstdlib>

// modify given landscape template and spawn template based on input stream given
// tested
void loadTemplate(vector<vector<ObjectName>> &landscape, vector<vector<ObjectName>> &spawn, size_t rowNum, size_t colNum, istream &is) {
    for (size_t i = 0; i < rowNum; i++) {
        string line;
        getline(is, line);
        for (size_t j = 0; j < colNum; j++) {
            char c = line[j];
            if (is.eof()) return;
            if (Index::isType(c, Landscape)) {    // if c represents a landscape, store corresponding ObjectName
                landscape[i][j] = Index::charToObjectName(c);
            }
            else {    // c represent a spawn object to be placed on a tile
                landscape[i][j] = Tiles;
                spawn[i][j] = Index::charToObjectName(c);
            }
        }
    }
}

// randomly select a ObjectName (i.e. subtype) from the ObjectType
ObjectName randomSubtype(ObjectType type) {
    int totalWeight = 0;
    map<ObjectName, int> weight = SpawnRule::weightOf(type);
    for (auto &[key, value] : weight) {
        totalWeight += value;
    }

    // randomly select an ObjectName
    int select = rand() % totalWeight;
    for (auto &[key, value] : weight) {
        if (select >= 0 && select < value) {
            return key;
        }
        else {
            select -= value;
        }
    }
    return Void;
}

// given matrix stores probability of generating at each (x, y), randomly choose an address (x, y) based on that
vector<size_t> randomAddress(vector<vector<double>> probMatrix) {
    vector<size_t> address{0, 0};
    double select = (double) rand()/RAND_MAX;    // random number between 0 and 1
    for (size_t i = 0; i < probMatrix.size(); i++) {
        for (size_t j = 0; j < probMatrix[i].size(); j++) {
            if (select >= 0 && select < probMatrix[i][j]) {
                address = {i, j};
                return address;
            }
            else {
                select -= probMatrix[i][j];
            }
        }
    }
    return address;
}

// randomly generate entities to spawnTemplate
void spawnEntities(const vector<vector<ObjectName>> &landscape, vector<vector<ObjectName>> &spawn, const vector<vector<int>> &chamberMap, size_t rowNum, size_t colNum) {
    // loop through all entity types to be spawned
    vector<ObjectType> allGenerateTypes = SpawnRule::generateTypes();
    for (auto it = allGenerateTypes.begin(); it != allGenerateTypes.end(); ++it) {
        // for each instance of the type to be generated
        for (int j = 0; j < SpawnRule::generateTypeNum(*it); ++j) {
            ObjectName randSubtype = randomSubtype(*it);    // randomly choose a subtype
            vector<vector<double>> probMatrix = SpawnRule::spawnProbabilityOf(chamberMap, spawn, randSubtype);    // matrix stores probability of generating at each (x, y)
            vector<size_t> address = randomAddress(probMatrix);
            SpawnRule::spawnAt(randSubtype, address[0], address[1], spawn, chamberMap);
        }
    }
}

// change given address of chamberMap to given chamber num, and recursively call all cells connected with it (8 directions)
void exploreChamber(vector<vector<int>> &chamberMap, const vector<vector<ObjectName>> &landscape, size_t x, size_t y, int chamberNum) {
    // return if out of the map
    if (x < 0 || x >= chamberMap.size() || y < 0 || y >= chamberMap[x].size()) {return;}
    // return if not a tile and not undiscovered
    if (landscape[x][y] != Tiles || chamberMap[x][y] != 0) {return;}
    // change the current chamberNum
    chamberMap[x][y] = chamberNum;
    // recursively call 8 directions
    exploreChamber(chamberMap, landscape, x+1, y, chamberNum);
    exploreChamber(chamberMap, landscape, x-1, y, chamberNum);
    exploreChamber(chamberMap, landscape, x+1, y+1, chamberNum);
    exploreChamber(chamberMap, landscape, x+1, y-1, chamberNum);
    exploreChamber(chamberMap, landscape, x-1, y+1, chamberNum);
    exploreChamber(chamberMap, landscape, x+1, y-1, chamberNum);
    exploreChamber(chamberMap, landscape, x, y+1, chamberNum);
    exploreChamber(chamberMap, landscape, x, y-1, chamberNum);
}

// based on the landscape map, label every cell with the chamber # they belong to
// tested
void loadChamberMap(vector<vector<int>> &chamberMap, const vector<vector<ObjectName>> &landscape, int &chamberNum) {
    for (size_t i = 0; i < chamberMap.size(); i++) {
        for (size_t j = 0; j < chamberMap[i].size(); j++) {
            // only tiles can belong to a chamber, check if current cell is not discovered yet
            if (landscape[i][j] == Tiles && chamberMap[i][j] == 0) {
                ++chamberNum;
                exploreChamber(chamberMap, landscape, i, j, chamberNum);
            }
        }
    }
}

// default constructor
FloorGenerator::FloorGenerator() {
    fileIn.open(mapFile);
    landscapeTemplate = vector<vector<ObjectName>>(ROWNUM, vector<ObjectName>(COLNUM, Void));
    spawnTemplate = vector<vector<ObjectName>>(ROWNUM, vector<ObjectName>(COLNUM, Void));
    chamberMap = vector<vector<int>>(ROWNUM, vector<int>(COLNUM, 0));
}

// constructor with given mapFile
// tested
FloorGenerator::FloorGenerator(string mapFile, bool spawnEntity) : mapFile{mapFile}, spawnEntity{spawnEntity} {
    fileIn.open(mapFile);
    landscapeTemplate = vector<vector<ObjectName>>(ROWNUM, vector<ObjectName>(COLNUM, Void));
    spawnTemplate = vector<vector<ObjectName>>(ROWNUM, vector<ObjectName>(COLNUM, Void));
    chamberMap = vector<vector<int>>(ROWNUM, vector<int>(COLNUM, 0));
}

// create floor object using the template, excluding player
Floor *FloorGenerator::generateFloor() {
    loadTemplate(landscapeTemplate, spawnTemplate, ROWNUM, COLNUM, fileIn);
    loadChamberMap(chamberMap, landscapeTemplate, chamberNum);
    
    // randomly spawn entity if needed
    if (spawnEntity) {
        spawnEntities(landscapeTemplate, spawnTemplate, chamberMap, ROWNUM, COLNUM);
    }

    Floor *floor = new Floor{ROWNUM, COLNUM};

    // first fill the landscape
    for (int i = 0; i < ROWNUM; i++) {
        for (int j = 0; j < COLNUM; j++) {
            ObjectCreater::newObjectAt(i, j, floor, landscapeTemplate[i][j]);
        }
    }

    // next fill the spawned objects other than player (on top of tiles)
    for (int i = 0; i < ROWNUM; i++) {
        for (int j = 0; j < COLNUM; j++) {
            if (spawnTemplate[i][j] != PlayerObject) {
                ObjectCreater::newObjectAt(i, j, floor, spawnTemplate[i][j]);
            }
        }
    }

    return floor;
}

// return address of player on the Floor (x, y)
vector<int> FloorGenerator::getPlayerLoc() {

    for (int i = 0; i < ROWNUM; i++) {
        for (int j = 0; j < COLNUM; j++) {
            if (spawnTemplate[i][j] == PlayerObject) {
                return vector<int>{i, j};
            }
        }
    }

    return vector<int>{0, 0};
}
