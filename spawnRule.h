#ifndef SPAWNRULE_H
#define SPAWNRULE_H
#include "index.h"

class SpawnRule {
    // stores how many of each SpawnType will be generated
    static map<ObjectType, int> generateNum;

    // weight of each subtype of spawntype will be generated, given the spawntype will be generated
    static map<ObjectType, map<ObjectName, int>> spawnWeight;

    public:
        static vector<ObjectType> generateTypes();    // return all object types that will be generated
        static int generateTypeNum(ObjectType type);    // get how many instances of given type should be generated
        static map<ObjectName, int> weightOf(ObjectType type);    // return weight of generating each ObjectName (subtype), given ObjectType
        static vector<vector<double>> spawnProbabilityOf(const vector<vector<int>> &chamberMap, const vector<vector<ObjectName>> &spawn, ObjectName obj);    // create matrix storing probability to generate obj at each coordinate
        static void spawnAt(ObjectName obj, size_t x, size_t y, vector<vector<ObjectName>> &spawnTemplate, const vector<vector<int>> &chamberMap);
};

#endif
