//
// Created by User on 4/14/2020.
//

#ifndef BIQUADRIS_PLAYERINFO_H
#define BIQUADRIS_PLAYERINFO_H

#include <fstream>
#include "playercommands.h"
#include "observeroftimeandactivationtime.h"
#include "level.h"
#include "subject.h"
class Setup;
class PlayerInfo{
    int id;
    // changes at the end of round.
    ObserverOfTimeAndActivationTime blindChoice{"blind", "choice", 1, 2};
    ObserverOfTimeAndActivationTime heavyChoice{"heavy", "choice", 1 , 2};
    ObserverOfTimeAndActivationTime forceChoice{"force", "choice", 1, 2};
    ObserverOfTimeAndActivationTime timeWithoutScoring{"timeWithoutScoring", "clear", 0 , 5};
    char nextBlock;
    // change by user
    bool random = true;
    ifstream inputFile;
public:
    Level level;
    PlayerCommands playerCommands;
    int getHeavynessFromLevel();
    int getHeavynessFromChoice();
    bool getBlind();
    char createNewBlock();
    char getNextBlock();
    void setNextBlock();
    bool gotScrewed();
    void noRandom(string);
    void randomize();
    PlayerInfo(int);
    friend class Setup;
    friend Observer;
};
#endif //BIQUADRIS_PLAYERINFO_H