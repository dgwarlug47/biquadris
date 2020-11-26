//
// Created by User on 4/15/2020.
//

#ifndef BIQUADRIS_LEFTOPERATION_H
#define BIQUADRIS_LEFTOPERATION_H

#include "blockoperation.h"
class LeftOperation : public BlockOperation{
    int transformationOnRow(vector<int>, BlockContent&) override;
    int transformationOnColumn(vector<int>, BlockContent&) override;
};


#endif //BIQUADRIS_LEFTOPERATION_H
