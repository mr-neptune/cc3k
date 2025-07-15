#include "textInstructionInterpreter.h"

void TextInstructionInterpreter::readRaceSelection() {
    while (true) {
        string s;
        in >> s;

        if (in.eof() || s == quit) {
            pam.endGame();
            return;
        }
        else if (raceMap.contains(s)) {
            pam.setRace(raceMap[s]);
            return;
        }
    }
}

void TextInstructionInterpreter::readPlayerAction() {
    while (true) {
        string s;
        in >> s;

        if (in.eof() || s == quit) {
            pam.endGame();
            return;
        }
        else if (s == usePotion) {
            string d;
            in >> d;
            if (directionMap.contains(d)) {
                pam.usePotion(directionMap[d]);
                return;
            }
        }
        else if (s == attack) {
            string d;
            in >> d;
            if (directionMap.contains(d)) {
                pam.playerAttack(directionMap[d]);
                return;
            }
        }
        else if (directionMap.contains(s)) {
            pam.playerMove(directionMap[s]);
            return;
        }
    }
}
