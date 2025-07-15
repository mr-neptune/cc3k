#ifndef INSTRUCTION_INTERPRETER_H
#define INSTRUCTION_INTERPRETER_H
#include "playerActivityManager.h"

class InstructionInterpreter {
    protected:
        PlayerActivityManager &pam;

        InstructionInterpreter(PlayerActivityManager &pam) : pam{pam} {}
};

#endif
