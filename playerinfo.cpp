//
// Created by User on 4/17/2020.
//

#include <iostream>
#include "playerinfo.h"

int PlayerInfo::getHeavynessFromChoice(){
    int choice_component = 0;
    if(heavyChoice.getState()){
        choice_component = 2;
    }
    return choice_component;
}
int PlayerInfo::getHeavynessFromLevel() {
    if(level.getLevel() > 2){
        return 1;
    }
    return 0;
}
bool PlayerInfo::getBlind() {
    return blindChoice.getState();
}
char PlayerInfo::createNewBlock() {

    if(!random){
        char  c;
        if(!(inputFile >> c)){
            random = true;
            return createNewBlock();
        }
        else{
            return c;
        }
    } else if(forceChoice.getState()) {
        return forceChoice.getExtraInfo()[0];
    }
    return level.createNewBlock();
}

char PlayerInfo::getNextBlock(){
    return nextBlock;
}
void PlayerInfo::setNextBlock() {
    nextBlock = createNewBlock();
}
bool PlayerInfo::gotScrewed() {
   int timePeriod =  timeWithoutScoring.currentTime - timeWithoutScoring.lastTimeChosen;
    if(level.getLevel() > 3 and timePeriod%5 == 0 and timePeriod > 0){
        return true;
    }
    else{
        return false;
    }
}

void PlayerInfo::noRandom(string filename) {
    random = false;
    inputFile = ifstream (filename);
}

void PlayerInfo::randomize(){
    random = true;
}
PlayerInfo::PlayerInfo(int id){
    id = id;
}