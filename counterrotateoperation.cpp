//
// Created by User on 4/19/2020.
//

#include "counterrotateoperation.h"

int CounterRotateOperation::transformationOnRow(vector<int> i, BlockContent& b){
    return b.getCorners()[3] - (i[1] - b.getCorners()[0]);
}
int CounterRotateOperation::transformationOnColumn(vector<int> i, BlockContent& b){
    return b.getCorners()[0]  - b.getCorners()[2] + i[0];
}