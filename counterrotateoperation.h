//
// Created by User on 4/19/2020.
//

#ifndef BIQUADRIS_COUNTERROTATEOPERATION_H
#define BIQUADRIS_COUNTERROTATEOPERATION_H

#include "blockoperation.h"
class CounterRotateOperation : public BlockOperation{
    int transformationOnRow(vector<int>, BlockContent&) override;
    int transformationOnColumn(vector<int>, BlockContent&) override;
};


#endif //BIQUADRIS_COUNTERROTATEOPERATION_H
