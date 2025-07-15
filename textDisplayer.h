#ifndef TEXTDISPLAYER_H
#define TEXTDISPLAYER_H
#include "displayer.h"
#include "gameStateManager.h"

class TextDisplayer : public Displayer {
    GameStateManager &gsm;

    public:
        void display();

        TextDisplayer(GameStateManager &gsm) : gsm{gsm} {}
};

#endif
