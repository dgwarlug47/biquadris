//
// Created by User on 4/17/2020.
//

#include "factoryblock.h"

char FactoryBlock::createNewBlock() {
    if(isThereAnySeed){
        srand(seed);
    }
    else{
        sleep(1);
        srand( (unsigned)time(0) );
    }
    return restOfCreateNewBlock();
}

void FactoryBlock::setFile(string s) {
    filename = s;
    fileInput = ifstream{s};
}