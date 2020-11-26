//
// Created by User on 4/19/2020.
//

#include "rotateoperation.h"

int RotateOperation::transformationOnRow(vector<int> i, BlockContent& b){
    return b.getCorners()[3] - (- i[1] + b.getCorners()[1]) ;
}
int RotateOperation::transformationOnColumn(vector<int> i, BlockContent& b){
    return b.getCorners()[0] + ( b.getCorners()[3] - i[0]);
}