#ifndef GAMESTATEMANAGER_H
#define GAMESTATEMANAGER_H
#include "subject.h"
#include "floorGenerator.h"
#include "playerCharacter.h"
#include "enemyCharacter.h"
#include "items.h"

class GameStateManager : public Subject {

    Floor *floor;
    PlayerCharacter *basePlayer;   // ptr to player object without any temp potion effects
    vector<string> actionMsg;
    FloorGenerator *fg;

    bool gameEnded = false;    // whether or not game is over
    int floorNum = 0;

    public:
        bool gameOver() const;    // return if game is over (true) or not (false)
        PlayerCharacter* getFloorPlayer() const;    // get ptr to player object for the floor (with temp potion effects)
        GameObject *getObjectAt(size_t x, size_t y) const;
        int getRowNum() const {return floor->getNumRows();}
        int getColNum() const {return floor->getNumCols();}
        int getPlayerX() const {return basePlayer->getXCoor();}
        int getPlayerY() const {return basePlayer->getYCoor();}

        void endGame() {gameEnded = true;}

        // put GameObject in (x, y) to the cellBelow field, then replace object at (x, y) to c, leaving old cellBelow field in its orig position
        void moveCharacterTo(size_t x, size_t y, Character *c);
        
        void characterAttack(Character *attacker, Character *defender);
        void applyItemEffect(Items *item);
        bool canMoveHere(size_t x, size_t y, Character *c) const;
        bool canMove(Character *c) const;

        void createPlayer(Race race);
        void initNextFloor();

        void addActionMsg(string msg);
        void removeActionMsg(string msg);
        void clearActionMsg();
        vector<string> getActionMsg() const;

        GameStateManager();
        GameStateManager(string mapFile, bool spawnEntity);
};

#endif
