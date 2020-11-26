//
// Created by User on 4/19/2020.
//

#ifndef BIQUADRIS_ROTATEOPERATION_H
#define BIQUADRIS_ROTATEOPERATION_H

#include "blockoperation.h"
class RotateOperation : public BlockOperation{
    int transformationOnRow(vector<int>, BlockContent&) override;
    int transformationOnColumn(vector<int>, BlockContent&) override;
};
#endif //BIQUADRIS_ROTATEOPERATION_H
