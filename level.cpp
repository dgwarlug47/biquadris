//
// Created by User on 4/14/2020.
//

#include "level.h"

void Level::notify(vector<string>, vector<int> i) {
    score += (level + i[0])*(level + i[0]);
}

int Level::getLevel(){
    return level;
}
int Level::getScore() {
    return score;
}
void Level::levelAdder(int i){
    level = max(0, min(4, i + level));
    switch (level){
        case 0:
            currentFactory = factoryLevel0.get();
        case 1:
            currentFactory = factoryLevel1.get();
            return;
        case 2:
            currentFactory = factoryLevel2.get();
            return;
        case 3:
            currentFactory = factoryLevel3.get();
            return;
        case 4:
            currentFactory = factoryLevel3.get();
    }
}
int Level::getHeavyComponent() {
    if (level > 2){
        return 1;
    }
    else{
        return 0;
    }
}
char Level::createNewBlock() {
    return currentFactory->createNewBlock();
}

void Level::useSeeds(int seed){
    factoryLevel0->isThereAnySeed = true;
    factoryLevel0->seed = seed;
    factoryLevel1->isThereAnySeed = true;
    factoryLevel1->seed = seed;
    factoryLevel2->isThereAnySeed = true;
    factoryLevel2->seed = seed;
    factoryLevel3->isThereAnySeed = true;
    factoryLevel3->seed = seed;
}