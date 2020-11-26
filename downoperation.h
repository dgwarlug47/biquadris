//
// Created by User on 4/18/2020.
//

#ifndef BIQUADRIS_DOWNOPERATION_H
#define BIQUADRIS_DOWNOPERATION_H

#include "blockoperation.h"
class DownOperation : public BlockOperation{
    int transformationOnRow(vector<int>, BlockContent&) override;
    int transformationOnColumn(vector<int>, BlockContent&) override;
};


#endif //BIQUADRIS_DOWNOPERATION_H
