#include <iostream>
#include "floorGenerator.h"
#include "textInstructionInterpreter.h"
#include "playerActivityManager.h"
#include "enemyActivityManager.h"
#include "textDisplayer.h"
#include <ctime>
#include <cstdlib>
using namespace std;

int main() {
    // srand(time(0));
    // FloorGenerator fg = FloorGenerator{"cc3kfloor.txt", true};
    // FloorGenerator fg2 = FloorGenerator();
    // fg.print();
    // fg2.print();

    GameStateManager *gsm;
    PlayerActivityManager *pam;
    EnemyActivityManager *eam;
    TextInstructionInterpreter *tii;
    TextDisplayer *td;

    string layoutFile = "";
    bool spawnEntites = true;

    cout << "Do you want customize the map (y/n)" << endl;
    string response;
    cin >> response;
    if (response == "y") {
        cout << "Please enter the map file" << endl;
        cin >> layoutFile;

        cout << "Do you want to spawn player, enemies, gold, potion, and stair?" << endl;
        string r;
        cin >> r;
        if (r == "y") {
            spawnEntites = true;
        }
        else {
            spawnEntites = false;
        } 

        gsm = new GameStateManager(layoutFile, spawnEntites);  
    }
    else {
        gsm = new GameStateManager();
    }

    pam = new PlayerActivityManager{gsm};
    eam = new EnemyActivityManager{gsm};
    tii = new TextInstructionInterpreter{*pam, cin};
    td = new TextDisplayer(*gsm);
    gsm->attach(td);

    // choose race
    tii->readRaceSelection();

    while (!(gsm->gameOver())) {
        gsm->callAllDisplayers();    // display
        tii->readPlayerAction();    // player action
        eam->moveAllEnemies();    // enemy action
    }

    
}
