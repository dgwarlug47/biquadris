//
// Created by User on 4/20/2020.
//

#include "level0block.h"

char Level0Block::restOfCreateNewBlock() {
    char c;
    if(fileInput >> c){
        return c;
    }
    else{
        fileInput = ifstream{filename};
        return restOfCreateNewBlock();
    }
}