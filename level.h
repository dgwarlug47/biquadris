//
// Created by User on 4/14/2020.
//

#ifndef BIQUADRIS_LEVEL_H
#define BIQUADRIS_LEVEL_H

#include "observer.h"
#include "subject.h"
#include "level0block.h"
#include "level1block.h"
#include "level2block.h"
#include "level3block.h"
#include <memory>
using namespace std;
//TODO: add all the #include of the other levels
class Level : public Observer{
    int id = 0;
    int level = 0;
    int score = 0;
    unique_ptr<FactoryBlock> factoryLevel0{new Level0Block};
    unique_ptr<FactoryBlock> factoryLevel1{new Level1Block};
    unique_ptr<FactoryBlock> factoryLevel2{new Level2Block};
    unique_ptr<FactoryBlock> factoryLevel3{new Level3Block};
    FactoryBlock* currentFactory = factoryLevel0.get();
    void useSeeds(int);
public:
    void levelAdder(int);
    void notify(vector<string>, vector<int>) override;
    int getLevel();
    int getScore();
    int getHeavyComponent();
    char createNewBlock();
    friend class Setup;
};
#endif //BIQUADRIS_LEVEL_H