#ifndef TEXT_INSTRUCTION_INTERPRETER_H
#define TEXT_INSTRUCTION_INTERPRETER_H
#include "InstructionInterpreter.h"
#include <iostream>

class TextInstructionInterpreter : public InstructionInterpreter {

    istream &in;

    string quit = "q";
    string usePotion = "u";
    string attack = "a";

    map<string, Race> raceMap = {
        {"s", Shade},
        {"d", Drow},
        {"v", Vampire},
        {"g", Goblin},
        {"t", Troll}
    };

    map<string, Direction> directionMap = {
        {"no", North},
        {"so", South},
        {"ea", East},
        {"we", West},
        {"ne", NorthEast},
        {"nw", NorthWest},
        {"se", SouthEast},
        {"sw", SouthWest}
    };

    public:
        void readRaceSelection();    // read race selection and apply it
        void readPlayerAction();    // read and apply player action

        TextInstructionInterpreter(PlayerActivityManager &pam, istream &in) : 
            InstructionInterpreter{pam}, in{in} {}
};

#endif
