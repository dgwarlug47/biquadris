//
// Created by User on 2020-04-11.
//

#ifndef BIQUADRIS_BOARD_H
#define BIQUADRIS_BOARD_H

#include <vector>
#include "string"
#include "subject.h"
#include "tblockcontent.h"
#include "sblockcontent.h"
#include "zblockcontent.h"
#include "oblockcontent.h"
#include "lblockcontent.h"
#include "iblockcontent.h"
#include "jblockcontent.h"
#include "leftoperation.h"
#include "rightoperation.h"
#include "downoperation.h"
#include "rotateoperation.h"
#include "counterrotateoperation.h"
#include "map"
#include <memory>
class Setup;
using namespace std;
class Board {
    int id;
    int rowSize = 15 + 3;
    int columnSize = 11;
    TheBoard theBoard;
    Subject clear;
    BlockContent* blockContent;
    map<char, unique_ptr<struct BlockContent>> interpreterBetweenCharsAndBlocks;
    bool isThereAnyBlockHere = false;
    void clears();
    void addNewBlockToTheBoard();
    void clearThisRow(int);
    vector<int> shapeNotification(vector<vector<int>>);

public:
    bool setNewBlock(char);
    void right();
    void left();
    bool down();
    void drop();
    void clockWise();
    void counterClockWise();
    string stringfy(bool);
    bool addBrown();
    bool heavy();
    friend class Setup;
};
#endif //BIQUADRIS_BOARD_H
