//
// Created by User on 4/19/2020.
//

#include "level3block.h"

char Level3Block::restOfCreateNewBlock() {
    int decider = rand()%9;
    switch (decider){
        case 0:
            return 'S';
        case 1:
            return 'S';
        case 2:
            return 'Z';
        case 3:
            return 'Z';
        case 4:
            return 'I';
        case 5:
            return 'J';
        case 6:
            return 'L';
        case 7:
            return 'O';
        case 8:
            return 'T';
        }
}