//
// Created by User on 4/19/2020.
//

#include "level2block.h"

char Level2Block::restOfCreateNewBlock() {
    int decider = rand()%7;
    switch (decider){
        case 0:
            return 'I';
        case 1:
            return 'S';
        case 2:
            return 'Z';
        case 3:
            return 'J';
        case 4:
            return 'T';
        case 5:
            return 'O';
        case 6:
            return 'L';
    }
}