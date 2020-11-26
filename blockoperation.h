//
// Created by User on 4/15/2020.
//

#ifndef BIQUADRIS_BLOCKOPERATION_H
#define BIQUADRIS_BLOCKOPERATION_H

#include "blockcontent.h"
#include "theboard.h"
class BlockOperation {
    virtual int transformationOnRow(vector<int>, BlockContent&) = 0;
    virtual int transformationOnColumn(vector<int>, BlockContent&) = 0;
    bool checkIfPossibleToDoTransformation(BlockContent &, TheBoard);
public:
    bool executeTransformation(BlockContent &, const TheBoard &);
};

#endif //BIQUADRIS_BLOCKOPERATION_H
