//
// Created by User on 4/15/2020.
//

#include "leftoperation.h"

int LeftOperation::transformationOnRow(vector<int> i, BlockContent& b){
    return i[0];
}
int LeftOperation::transformationOnColumn(vector<int> i, BlockContent& b){
    return i[1] - 1;
}