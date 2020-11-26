//
// Created by User on 4/14/2020.
//

#include "level1block.h"

char Level1Block::restOfCreateNewBlock() {
    int decider = rand()%12;
    switch (decider){
        case 0:
            return 'I';
        case 1:
            return 'I';
        case 2:
            return 'J';
        case 3:
            return 'J';
        case 4:
            return 'O';
        case 5:
            return 'O';
        case 6:
            return 'L';
        case 7 :
            return 'L';
        case 8:
            return 'T';
        case 9:
            return 'T';
        case 10:
            return 'S';
        case 11:
            return 'Z';
    }
}