//
// Created by User on 4/18/2020.
//

#ifndef BIQUADRIS_RIGHTOPERATION_H
#define BIQUADRIS_RIGHTOPERATION_H


#include "blockoperation.h"
class RightOperation : public BlockOperation{
    int transformationOnRow(vector<int>, BlockContent&) override;
    int transformationOnColumn(vector<int>, BlockContent&) override;
};

#endif //BIQUADRIS_RIGHTOPERATION_H
